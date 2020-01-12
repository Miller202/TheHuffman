#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"
#include "hash.h"
#include "heap.h"

#ifndef HUFFMAN_HUFF_TREE_H
#define HUFFMAN_HUFF_TREE_H

//Functions

int empty_tree(TREE *tree);

int is_root(TREE *tree);

int escape_char(TREE *tree);

int tree_size(TREE *tree);

void free_tree(TREE *tree);

TREE *create_node(unsigned char character, long long int frequency, TREE *left, TREE *right);

TREE *create_huffman_tree(HEAP *heap);

void map_paths(TREE *tree, HASH *hash);

void read_pre_order_tree(TREE *tree, FILE *input);

void write_pre_order_tree(TREE *tree, FILE *output);


#endif //HUFFMAN_HUFF_TREE_H
