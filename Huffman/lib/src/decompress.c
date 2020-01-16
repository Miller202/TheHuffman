#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/decompress.h"

int is_bit_set(unsigned char c, int i)
{
    unsigned char mask = 1 << i;
    return mask & c;
}

short get_trash_size(FILE *input)
{
	short trash_size = 0;
	unsigned char byte;
	fscanf(input, "%c", &byte);
	trash_size = byte >> 5;
	return trash_size;
}

short get_tree_size(FILE *input)
{
	short tree_size = 0;
	unsigned char byte;
	fscanf(input, "%c", &byte);
	byte <<= 3;
	byte >>= 3;
	tree_size = byte << 8;
	fscanf(input, "%c", &byte);
	tree_size = tree_size | byte;
	return tree_size;
}

TREE* get_hufftree(FILE* input, TREE* tree){
	unsigned char c;
	fscanf(input, "%c",&c);
	tree = create_node(c,0,NULL,NULL);

	if(c == '*'){
		tree->left = get_hufftree(input, tree->left);
		tree->right = get_hufftree(input, tree->right);
	}
	else if(c=='\\'){
		fscanf(input, "%c",&c);
		tree = create_node(c,0,NULL,NULL);
	}

	return tree;

}