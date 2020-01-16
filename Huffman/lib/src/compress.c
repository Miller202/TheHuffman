#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/compress.h"

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

    write_tree_size(huff_tree, output);
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
    short tree_sz = tree_size(tree);
    tree_sz <<= 3;
    tree_sz >>= 3;
    fwrite(&tree_sz, 2, 1, file);
}

void write_trash(unsigned char trash, FILE *file)
{
    rewind(file);

    unsigned char c;
    fread(&c, 1, 1, file);

    trash = trash << 5;
    trash |= c;

    rewind(file);
    fwrite(&trash, 1, 1, file);

}

unsigned char write_compress_doc(HASH *paths, FILE *input, FILE *output)
{
    int i = 0, bt_cont = 7, bt_sim = 0;
    unsigned char c, byte = 0;

    char byte_simulation[9];

    while (fscanf(input, "%c", &c) != EOF)      //enquanto ler 1 byte
    {
        char *atual = paths->table[c];         //pega o byte criptografado
        for(i = 0; i < strlen(atual); i++)
        {
            if (atual[i] == '1') {
                byte = set_bit(byte, bt_cont);
                byte_simulation[bt_sim] = '1';
            } else{
                byte_simulation[bt_sim] = '0';
            }
            
            bt_cont--;
            bt_sim++;

            if (bt_cont == -1)
            {
                bt_cont = 7;
                fwrite(&byte, 1, 1, output);
                byte = 0;
                for(bt_sim = 0; bt_sim < 8; bt_sim++)
                    byte_simulation[bt_sim] = '#';
                bt_sim = 0;
            }   
        }
    }

    if (i == 0)
        return 0;

    fwrite(&byte, 1, 1, output);

    return (unsigned char) 8 - (i - 1);       //retorna o lixo do fim do arquivo
    
}

char* concat(char *s1, char *s2)      //essa função poderia ficar em outro arquivo
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}