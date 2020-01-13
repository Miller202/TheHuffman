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

int is_root(TREE *tree)
{
	return (tree->left == NULL) && (tree->right == NULL);
}

int escape_char(TREE *tree)
{
	if (is_root(tree))
	{
		return (tree->c == '*' || tree->c == '\\');
	}

	return  0;
}

int tree_size(TREE *tree)
{
	if (empty_tree(tree))
		return 0;

	if (escape_char(tree))
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
	while (heap->size > 1)
	{
		TREE *left_child_tree = dequeue(heap);
		TREE *right_child_tree = dequeue(heap);

		TREE *parent_tree = new_node('*', 0, left_child_tree, right_child_tree);
		parent_tree->frequency = get_parent_frequency(parent_tree);

		enqueue(heap, parent_tree);
	}

	return dequeue(heap);
}

void map_paths(TREE *tree, HASH *hash, char *path, int i)
{
	if empty_tree(tree)
		return;

	if (is_root(tree))
	{
		path[i] = '\0';
		put(hash, (int) tree->c, path);
		return;
	}

	if (!empty_tree(tree->left))
	{
		path[i++] = '0';
		map_paths(tree->left, hash, path, i);
	}

	if (!empty_tree(tree->right))
	{
		path[i++] = '1';
		map_paths(tree->right, hash, path, i);
	}
}

TREE *read_pre_order_tree(TREE *tree, FILE *input, int *tree_size)
{
	if (tree_size == 0)
		return NULL;

	char c;
	fread(c, 1, 1, input);
	(*tree_size)--;

	if (escape_char(tree))
		fread(c, 1, 1, input);

	tree = create_node(c, 0, NULL, NULL);
	tree->left = read_pre_order_tree(tree->left, input, tree_size);
	tree->right = read_pre_order_tree(tree->right, input, tree_size);

	return tree;
}

void write_pre_order_tree(TREE *tree, FILE *output)
{
	if (empty_tree(tree))
		return;
	
	if (escape_char(tree))
		fwrite('\\', 1, 1, output);
		
	fwrite(tree->c, 1, 1, output);
	write_pre_order_tree(TREE *tree->left, FILE *output);
	write_pre_order_tree(TREE *tree->right, FILE *output);
}