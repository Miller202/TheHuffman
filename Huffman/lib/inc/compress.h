#ifndef HUFFMAN_COMPRESS_H
#define HUFFMAN_COMPRESS_H

#include "heap.h"
#include "hash.h"
#include "huff_tree.h"
#include <CUnit/CUnit.h>

unsigned char set_bit(unsigned char c, int i);

FILE *compress_file(FILE *input, FILE *output);

void open_files (char *input_name);

void write_tree_size(TREE *tree, FILE *input);

void write_trash(unsigned char trash, FILE *file);

unsigned char write_compress_doc(HASH *paths, FILE *input, FILE *output);

char* concat(char *s1, char *s2);      //essa função poderia ficar em outro arquivo
#endif //HUFFMAN_COMPRESS_H
