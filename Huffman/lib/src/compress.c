#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "compress.h"
#include "heap.h"
#include "hash.h"
#include "huff_tree.h"
#include "utils.h"

u_char set_bit(u_char c, int i)
{
    u_char mask = 1 << i;
    return mask | c;
}


void compress_file(FILE *input, FILE *output)
{
    HEAP *heap = mount_heap(input);

    rewind(input);

    TREE *huff_tree = create_huffman_tree(heap);

    HASH *paths = create_hash();

    u_short tree_sz = get_tree_size(huff_tree);

    char path[tree_sz];

    map_paths(huff_tree, paths, path, 0);

    write_tree_size(tree_sz, output);

    write_pre_order_tree(huff_tree, output);

    u_char trash = 0;

    if (is_leaf(huff_tree))
    {
        trash = write_one_ascii_char_doc(input, output);
    }
    else
    {
        trash = write_compress_doc(input, output, paths);
    }

    write_trash(trash, output);

    free_tree(huff_tree);
    free_heap(heap);
    free_hash(paths);
}

void write_tree_size(u_short tree_sz, FILE *file)
{
    u_short bytes = tree_sz << 8;
    bytes |= tree_sz >> 8;

    fwrite(&bytes, 2, 1, file);
}

void write_trash(u_char trash, FILE *file)
{
    rewind(file);

    u_char c;
    fscanf(file, "%c", &c);

    trash = trash << 5;    //coloca os 3 últimos bits nas 3 primeiras posições do byte
    trash |= c;             //"junta" os 2 bytes

    rewind(file);
    fwrite(&trash, 1, 1, file);

    rewind(file);
}

u_char write_one_ascii_char_doc(FILE *input, FILE *output)
{
    int i = 0;
    u_char c, byte = 0;

    while (fscanf(input, "%c", &c) != EOF)
    {
        if(i == 7)
        {
            fwrite(&byte, 1, 1, output);
            i = 0;
        }
        else {
            i++;
        }

    }
    if (i == 0) {
        return 0;
    }

    fwrite(&byte, 1, 1, output);

    return (u_char) (8 - i);

}
u_char write_compress_doc(FILE *input, FILE *output, HASH *paths)
{
    int i = 0, bt_cont = 7, path_size;
    u_char c, byte = 0;

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

    return (u_char) (bt_cont + 1);   // Retorna o lixo do fim do arquivo
}