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


FILE *compress_file(FILE *input, FILE *output)
{
    HEAP *heap = mount_heap(input);
    rewind(input);
    TREE *huff_tree = create_huffman_tree(heap);
    
    HASH *paths = create_hash();
    char path[1000];
    map_paths(huff_tree, paths, path, 0);

    print_hash(paths);

    write_tree_size(huff_tree, output);

    print_tree_pre_order_char(huff_tree);
    printf("\n");

    write_pre_order_tree(huff_tree, output);

    unsigned char trash = write_compress_doc(paths, input, output);

    write_trash(trash, output);

    return output;
}

void open_files (char *input_name)
{
    // if (is_compressed_file(input_name)) //se é um arquivo compactado .huff
    // {
    //     printf("Arquivo já compactado!");
    //     return;
    // }

    FILE *input = fopen(input_name, "rb");
    if (input == NULL)
    {
        printf("Erro de Memória!");
        return;
    }
    
    char *output_name = concat(input_name, ".huff");
    FILE *output = fopen(output_name, "w+b");
    if (output == NULL)
    {
        printf("Erro de Memória!");
        exit(1);
    }

    compress_file(input, output);
}

void write_tree_size(TREE *tree, FILE *file)
{
    unsigned short tree_sz = tree_size(tree);

    // > 0000 0000 1111 1111
    if (tree_sz > 255)
    {
        fwrite(&tree_sz, 2, 1, file);
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

    trash = trash << 5;
    trash |= c;

    rewind(file);
//    fwrite(&trash, 1, 1, file);
    fprintf(file, "%c", trash);

    rewind(file);
}

unsigned char write_compress_doc(HASH *paths, FILE *input, FILE *output)
{
    int i = 0;
    int bt_cont = 7;
    int size;

    unsigned char c;
    unsigned char byte = 0;

    // Enquanto ler 1 byte
    while (fscanf(input, "%c", &c) != EOF)
    {
        // Pega o byte criptografado
        char *atual = paths->table[c];

        size = strlen(atual);
        for(i = 0; i < size; i++)
        {
            if (atual[i] == '1')
            {
                // Atribui o bit 1 na posição do byte
                byte = set_bit(byte, bt_cont);
            }

            bt_cont--;

            // Se já formou um byte
            if (bt_cont == -1)
            {
                bt_cont = 7;
                fwrite(&byte, 1, 1, output);

                // Zera o byte pra começar tudo de novo
                byte = 0;
            }   
        }
    }

//    int trash;
    if (bt_cont == 7){
//        trash = 0;
        return 0;
    }

    fwrite(&byte, 1, 1, output);

    // Retorna o lixo do fim do arquivo
//    trash = 8 - (i - 1);

    return (unsigned char) 8 - (bt_cont + 1);
}

// TODO: Essa função poderia ficar em outro arquivo
char* concat(char *s1, char *s2)
{
    // +1 for the null-terminator
    char *result = malloc(strlen(s1) + strlen(s2) + 1);

    // TODO: In real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);

    return result;
}