#ifndef HUFFMAN_HUFF_TREE_H
#define HUFFMAN_HUFF_TREE_H

#include "heap.h"
#include "hash.h"

/* Huffman Tree */
typedef struct TREE{
    long long int frequency;
    unsigned char c;
    struct TREE *left;
    struct TREE *right;
} TREE;

//Functions

int empty_tree(TREE *tree);

int is_root(TREE *tree);

int escape_char(TREE *tree, unsigned char c);

int tree_size(TREE *tree);

void free_tree(TREE *tree);

TREE *create_node(unsigned char character, long long int frequency, TREE *left, TREE *right);


void map_paths(TREE *tree, HASH *hash, char *path, int i);


TREE *create_huffman_tree(HEAP *heap);

TREE *read_pre_order_tree(TREE *tree, FILE *input, int *tree_size);

void write_pre_order_tree(TREE *tree, FILE *output);


#endif //HUFFMAN_HUFF_TREE_H
