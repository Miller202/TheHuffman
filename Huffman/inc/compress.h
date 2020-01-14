#ifndef HUFFMAN_COMPRESS_H
#define HUFFMAN_COMPRESS_H

#include "heap.h"
#include "hash.h"
#include "huff_tree.h"

FILE *compress_file(FILE *input, char *input_name);

void write_tree_size(TREE *tree, FILE *input);

void write_trash(unsigned char trash, FILE *file);

char write_compress_doc(HASH *paths, FILE *input, FILE *output);

char* concat(char *s1, char *s2);      //essa função poderia ficar em outro arquivo
#endif //HUFFMAN_COMPRESS_H
