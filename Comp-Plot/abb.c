#include "abb.h"

bst* create_empty_bst()
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
		add_bst(bst->left, item);
	}
	else if(item > bst->item) // se o item for maior que o atual, vai para o filho da direita;
	{
		add_bst(bst->right, item);
	}
	else{ // se for igual, o item estará na posição correta, então retorna a árvore.		
		return bst;
	}
}

bs_tree* search_bst(bs_tree *bst, int item)
{
	if(bst == NULL || bst->item == item) // se a arvore é nula ou o item atual é o que deseja, retorna a abb;
	{
		return bst;
	}
	else if(item < bst->item) // se o item é menor que o item atual, procure no filho da esquerda;
	{
		search(bst->left, item);
	}
    else{	// se o item é maior que o item atual, procure no filho da direita.
		search(bst->right, item);
	}
}