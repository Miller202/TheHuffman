#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int empty_tree(TREE *tree)
{
	return tree == NULL;
}

int is_leaf(TREE *tree)
{
	return (tree->left == NULL) && (tree->right == NULL);
}

int escape_char(TREE *tree, unsigned char c)
{
	if (is_leaf(tree))
	{
		return (c == '*' || c == '\\');
	}

	return  0;
}

short tree_size(TREE *tree)
{
	if (empty_tree(tree))
		return 0;

	if (escape_char(tree, tree->c))				//se um caracter especial está numa folha, no arquivo de texto, será escrito com 2 chars ('\*' ou '\\')
		return 2;
	
	return 1 + tree_size(tree->left) + tree_size(tree->right);

}

void free_tree(TREE *tree)
{
	if (empty_tree(tree))
		return;

	free_tree(tree->left);
	free_tree(tree->right);

	free(tree);
}

long long int get_parent_frequency(TREE *tree)
{
	return tree->left->frequency + tree->right->frequency;
}

TREE *create_huffman_tree(HEAP *heap)
{
	while (heap->size > 1)			//enquanto restar mais de 1 árvore na heap
	{
		TREE *left_child_tree = dequeue(heap);			//pega as 2 árvores de menor frequência
		TREE *right_child_tree = dequeue(heap);

		TREE *parent_tree = create_node('*', 0, left_child_tree, right_child_tree);		//cria uma nova árvore, com a frequência igual a das 2 árvores de menor frequência
		parent_tree->frequency = get_parent_frequency(parent_tree);

		enqueue(heap, parent_tree);		//adiciona a nova árvore à heap
	}

	return dequeue(heap);			//retorna a raiz da árvore
}

void map_paths(TREE *tree, HASH *hash, char *path, int i)
{
	if (empty_tree(tree))
		return;

	if (is_leaf(tree))		//se é uma folha, temos um caminho formado
	{
		path[i] = '\0';						//finaliza o caminho
		put(hash, (int) tree->c, path);		//adiciona o caminho no hash
		return;
	}

	if (!empty_tree(tree->left)) 		//há caminho à esquerda	
	{
		path[i++] = '0';
		map_paths(tree->left, hash, path, i);
	}

	if (!empty_tree(tree->right))	//há caminho à direita
	{
		path[i++] = '1';
		map_paths(tree->right, hash, path, i);
	}
}

TREE *read_pre_order_tree(TREE *tree, FILE *input, int *tree_size)
{
	if (tree_size == 0)			//termina de ler a árvore
	{
		return NULL;
	}

	unsigned char c;

	int is_leaf = 0;
	fread(&c, 1, 1, input);
	(*tree_size)--;

	if (escape_char(tree, c))		//se a folha tem um caracter de escape, lê o próximo char
	{
		fread(&c, 1, 1, input);
		is_leaf = 1;
	}
	else if (c != '*')
	{
		is_leaf = 1;
	}

	tree = create_node(c, 0, NULL, NULL);

	if (is_leaf)				//se for uma folha, não há nó filho
	{
		tree->left = NULL;
		tree->right = NULL;
	}
	else
	{
		tree->left = read_pre_order_tree(tree->left, input, tree_size);
		tree->right = read_pre_order_tree(tree->right, input, tree_size);
	}

	return tree;
}

void write_pre_order_tree(TREE *tree, FILE *output)
{
	if (empty_tree(tree))
	{
		return;
	}

	if (escape_char(tree, tree->c))		//se a folha tem um char especial, então escrevemos o caracter de escape
	{
		fprintf(output, "%c", "\\");
	}

	fwrite(&tree->c, 1, 1, output);
	write_pre_order_tree(tree->left, output);
	write_pre_order_tree(tree->right, output);
}

