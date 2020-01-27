#include "abb.h"

bs_tree* create_empty_bst()
{
	return NULL;
}

bs_tree* create_node_bst(int item, bs_tree *left, bs_tree *right)
{
	bs_tree *new_bst = (bs_tree*) malloc(sizeof(bs_tree));
	new_bst->item = item;
	new_bst->left = NULL;
	new_bst->right = NULL;
	return new_bst;
}

bs_tree* add_bst(bs_tree *bst, int item)
{
	if(bst == NULL) // se a árvore ainda é nula, crie um novo nó.
	{
		return create_node_bst(item, NULL, NULL);
	}

	if(item < bst->item) // se o item for menor que o atual, vai para o filho da esquerda;
	{
		bst->left = add_bst(bst->left, item);
	}
	else if(item > bst->item) // se o item for maior que o atual, vai para o filho da direita;
	{
		bst->right = add_bst(bst->right, item);
	}

	// se for igual, o item estará na posição correta, então retorna a árvore.
    return bst;
}

int search_bst(bs_tree *bst, int item, int *comp_bt)
{
	*comp_bt += 1;

	if(bst == NULL) // se a arvore é nula retorna 0;
	{
		return 0;
	}
	else{
		if(bst->item == item) // se o item atual é o que deseja, retorna 1
		{
			return 1;
		}
		else if(item < bst->item) // se o item é menor que o item atual, procure no filho da esquerda;
		{
			search_bst(bst->left, item, comp_bt);
		}
		else{	// se o item é maior que o item atual, procure no filho da direita.
			search_bst(bst->right, item, comp_bt);
		}
	}
}

int is_empty(bs_tree *root)
{
    return (root == NULL);
}

void print_pre_order(bs_tree *root)
{
    if(!is_empty(root))
    {
        printf("%d\n", root->item);
        print_pre_order(root->left);
        print_pre_order(root->right);
    }
}