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
	if(bst == NULL)
	{
		return create_node_bst(item, NULL, NULL);
	}

	if(item < bst->item)
	{
		bst->left = add_bst(bst->left, item);
	}
	else if(item > bst->item)
	{
		bst->right = add_bst(bst->right, item);
	}

    return bst;
}

int search_bst(bs_tree *bst, int item, int *comp)
{
    (*comp)++;

    if(bst == NULL)
    {
        return 0;
    }
    else {
        if (bst->item == item)
        {
            return 1;
        } else if (item < bst->item)
        {
            search_bst(bst->left, item, comp);
        } else {
            search_bst(bst->right, item, comp);
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