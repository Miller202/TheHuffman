#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/compress.h"

FILE *compress_file(FILE *input, char *input_name)
{
    //FILE *input = fopen(file, "rb");

    char *output_name = concat(input_name, ".huff");
    FILE *output = fopen(output_name, "w+b");

    HEAP *heap = mount_heap(input);
    TREE *huff_tree = create_huffman_tree(heap);
    
    HASH *paths = create_hash();
    unsigned char *path;
    map_paths(huff_tree, paths, path, 0);

    write_tree_size(huff_tree, output);
    write_pre_order_tree(huff_tree, output);

    unsigned char trash = 'c';

    // unsigned char trash = write_compress_doc(paths, input, output);

    write_trash(trash, output);

    return output;
}

void write_tree_size(TREE *tree, FILE *file)
{
    short tree_sz = tree_size(tree);
    tree_sz = tree_sz << 3;
    tree_sz = tree_sz >> 3;
    fwrite(tree_sz, 2, 1, file);
}

void write_trash(unsigned char trash, FILE *file)
{
    fseek(file, 0, SEEK_SET);

    unsigned char c;
    fread(c, 1, 1, file);

    trash = trash << 5;
    trash |= c;

    fseek(file, 0, SEEK_SET);
    fwrite(trash, 1, 1, file);

}

// char write_compress_doc(HASH *paths, FILE *input, FILE *output)
// {
//     unsigned char c;

//     while (fread(c, 1, 1, input) == 1)
//     {
//         char *atual = paths->table[c];

//         while (atual != '\0')
//         {
            
//         }
        
//     }
    
// }

char* concat(char *s1, char *s2)      //essa função poderia ficar em outro arquivo
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}