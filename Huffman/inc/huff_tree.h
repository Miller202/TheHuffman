#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"
#include "hash.h"
#include "heap.h"

#ifndef HUFFMAN_HUFF_TREE_H
#define HUFFMAN_HUFF_TREE_H

//Functions

TREE *create_node(unsigned char character, long long int frequency, TREE *left, TREE *right);

#endif //HUFFMAN_HUFF_TREE_H
