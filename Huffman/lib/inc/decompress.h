#ifndef HUFFMAN_DECOMPRESS_H
#define HUFFMAN_DECOMPRESS_H

#include "heap.h"
#include "hash.h"
#include "huff_tree.h"
// #include <CUnit/CUnit.h>

int is_bit_set(unsigned char c, int i);

int get_trash_size(FILE *input);

short get_tree_size(FILE *input);

TREE* get_hufftree(FILE *input, TREE* tree);

void decompress_file(FILE* input, FILE* output, TREE* tree, int trash_size, short size_tree);

void decompress(char input_path[], char output_path[]);

#endif //HUFFMAN_DECOMPRESS_H