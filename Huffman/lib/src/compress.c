#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "compress.h"
#include "heap.h"
#include "hash.h"
#include "huff_tree.h"
#include "utils.h"

unsigned char set_bit(unsigned char c, int i)
{
    unsigned char mask = 1 << i;
    return mask | c;
}


void compress_file(FILE *input, FILE *output)
{
    HEAP *heap = mount_heap(input);
    rewind(input);
    TREE *huff_tree = create_huffman_tree(heap);

    //TODO free_heap(heap);
    
    HASH *paths = create_hash();
    char path[1000];        //TODO definir um tamanho maximo que uma árvore pode ter
    map_paths(huff_tree, paths, path, 0);

//    print_hash(paths);

    write_tree_size(huff_tree, output);

//    print_tree_pre_order_char(huff_tree);
//    printf("\n");

    write_pre_order_tree(huff_tree, output);
    unsigned char trash = write_compress_doc(input, output, paths);
    write_trash(trash, output);

    free_tree(huff_tree);
    //TODO free_hash(paths);
}

void write_tree_size(TREE *tree, FILE *file)
{
    unsigned short tree_sz = tree_size(tree);

//    printf("tree %d", tree_sz);

    if (tree_sz > 255)      //se são necessários 2 bytes para escrever a árvore no arquivo
    {
//        unsigned short bytes = tree_sz << 8;
//        bytes |= tree_sz >> 8;

        fwrite(&tree_size, 2, 1, file);
    }
    else
    {
        unsigned char zero = 0;
        fwrite(&zero, 1, 1, file);
        fwrite(&tree_sz, 1, 1, file);
    }
}

void write_trash(unsigned char trash, FILE *file)
{
    rewind(file);

    unsigned char c;
    fread(&c, 1, 1, file);

    trash = trash << 5;    //coloca os 3 últimos bits nas 3 primeiras posições do byte
    trash |= c;             //"junta os 2 bytes

    rewind(file);
    fprintf(file, "%c", trash);

    rewind(file);
}

unsigned char write_compress_doc(FILE *input, FILE *output, HASH *paths)
{
    int i = 0, bt_cont = 7, path_size;
    unsigned char c, byte = 0;

    while (fscanf(input, "%c", &c) != EOF)
    {
        char *path = paths->table[c]; // Pega o novo mapeamento do char c
        path_size = strlen(path);

        for(i = 0; i < path_size; i++)
        {
            if (path[i] == '1') {
                byte = set_bit(byte, bt_cont);  // Atribui o bit 1 na posição bt_cont do byte
            }

            bt_cont--;

            if (bt_cont == -1) // Se já formou um byte
            {
                fwrite(&byte, 1, 1, output);

                bt_cont = 7;
                byte = 0;
            }   
        }
    }

    if (bt_cont == 7) {          //se não tem lixo
        return 0;
    }
    fwrite(&byte, 1, 1, output);        //escreve o último byte (com lixo no final)

    return (unsigned char) (bt_cont + 1);   // Retorna o lixo do fim do arquivo
}