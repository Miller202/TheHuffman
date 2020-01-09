#include "../inc/huff_tree.h"
#include "../inc/heap.h"

TREE *create_node(unsigned char character, long long int frequency, TREE *left, TREE *right)
{  
	TREE *new_node = (TREE*)malloc(sizeof(TREE));

	new_node->c = character;
	new_node->frequency = frequency;
	new_node->left = left;
	new_node->right = right;

	return new_node;
}

