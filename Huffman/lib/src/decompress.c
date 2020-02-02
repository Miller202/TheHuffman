#include <stdio.h>
#include <stdlib.h>

#include "../inc/decompress.h"

int is_bit_set(u_char c, int i)
{
    u_char mask = 1 << i;
    return mask & c;
}

int get_trash_size(FILE *input)
{
	int trash_size = 0;
	u_char byte;
	fscanf(input, "%c", &byte);
	trash_size = byte >> 5;     //retira os 5 bits do tree size
	return trash_size;
}

short get_tree_size_from_file(FILE *input)
{
	short tree_size = 0;        //2 bytes
	u_char byte;
	fscanf(input, "%c", &byte);
	byte <<= 3;
	byte >>= 3;                 //retira os 3 bits do trash size
	tree_size = byte << 8;      //coloca o byte lido do arquivo no 1o byte da tree_size
	fscanf(input, "%c", &byte);
	tree_size = tree_size | byte;   //junta o 2o byte da tree_size com o 2o byte lido
	return tree_size;
}

TREE* get_hufftree(FILE* input, TREE* tree)
{
	u_char c;
	fscanf(input, "%c",&c);
	tree = create_node(c, 0, NULL, NULL);

	if(c == '*'){
		tree->left = get_hufftree(input, tree->left);
		tree->right = get_hufftree(input, tree->right);
	}
	else if(c=='\\'){   //se for um caracter de escape
		fscanf(input, "%c",&c);
        tree->c = c;
	}

	return tree;
}

void decompress_one_ascii_file(FILE* input, FILE* output, TREE* tree, int trash_size)
{
	TREE* new_tree = tree;

	int i;
    u_char c_1, c_2;

    fscanf(input, "%c", &c_1);
	while(fscanf(input, "%c", &c_2) != EOF)
	{
		for(i = 7; i >= 0; i--)
		{
            fwrite(&new_tree->c, 1, 1, output);
			new_tree = tree;
		}

        c_1 = c_2;
	}

    for(i = 7; i >= trash_size; i--)    //loop para o último byte
    {
        fwrite(&new_tree->c, 1, 1, output);
		new_tree = tree;
    }
}
void decompress_file(FILE* input, FILE* output, TREE* tree, int trash_size)
{
	TREE* new_tree = tree;

	int i;
    u_char c_1, c_2;

    fscanf(input, "%c", &c_1);
	while(fscanf(input, "%c", &c_2) != EOF)
	{
		for(i = 7; i >= 0; i--)
		{
			if(is_bit_set(c_1, i)) //se o bit da posicao atual é 1, então ir para a direita na árvore
			{
				new_tree = new_tree->right;
			}
			else{
				new_tree = new_tree->left;
			}
            
			if (is_leaf(new_tree))
            {
                fwrite(&new_tree->c, 1, 1, output);

                new_tree = tree;
            }
		}

        c_1 = c_2;
	}

    for(i = 7; i >= trash_size; i--)    //loop para o último byte
    {
		if(is_bit_set(c_1, i))
		{
			new_tree = new_tree->right;
		}
		else{
			new_tree = new_tree->left;
		}

        if(is_leaf(new_tree))
        {
            fwrite(&new_tree->c, 1, 1, output);
            new_tree = tree;
        }
    }
}

void decompress(FILE *input, FILE *output)
{
	int trash_size = get_trash_size(input);
	rewind(input);
	short tree_size = get_tree_size_from_file(input);

	TREE* tree = create_node('*', 0, NULL, NULL);

	tree = get_hufftree(input, tree);

	if (is_leaf(tree)){
		decompress_one_ascii_file(input, output, tree, trash_size);
	}
	else {
		decompress_file(input, output, tree, trash_size);
	}
	

	free_tree(tree);
}