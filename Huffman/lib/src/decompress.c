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

TREE* get_hufftree(FILE* input, TREE* tree)
{
	unsigned char c;
	fscanf(input, "%c",&c);
	tree = create_node(c, 0, NULL, NULL);

	if(c == '*'){
		tree->left = get_hufftree(input, tree->left);
		tree->right = get_hufftree(input, tree->right);
	}
	else if(c=='\\'){
		fscanf(input, "%c",&c);
		tree = create_node(c, 0, NULL, NULL);
	}

	return tree;
}

void decompress_file(FILE* input, FILE* output, TREE* tree, short trash_size, short size_tree)
{
	TREE* new_tree = tree;

	int i, is_EOF = 0, bytes = 0;
	unsigned char c, aux;

	while(fscanf(input, "%c", &c) != EOF)
	{
        is_EOF = fscanf(input, "%c", &aux);
        fseek(input, ftell(input) - 1, SEEK_SET);
		for(i = 7; i >= 0; i--)
		{
			if(is_bit_set(c, i))
			{
				new_tree = new_tree->right;
			}
			else{
				new_tree = new_tree->left;
			}

			if (is_leaf(new_tree))
            {
			    printf("%c", new_tree->c);
                fprintf(output, "%c", new_tree->c);
//                fwrite(&new_tree->c, 1, 1, output);
                new_tree = tree;
            }

            if(is_EOF && i < trash_size)
            {
                break;
            }
		}

		bytes++;
	}
}

void decompress(char input_path[], char output_path[])
{
	FILE* input;
	FILE* output;

	input = fopen(input_path, "rb");
	output = fopen(output_path, "w+b");

	short trash_size = get_trash_size(input);
	rewind(input);
	short  tree_size = get_tree_size(input);

//	unsigned char byte;
//    fscanf(input, "%c", &byte);

	TREE* tree = create_node('*', 0, NULL, NULL);

	tree = get_hufftree(input, tree);

	decompress_file(input, output, tree, trash_size, tree_size);

	fclose(input);
	fclose(output);
}