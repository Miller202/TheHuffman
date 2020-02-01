#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abb.h"
#include "list.h"

typedef struct binary_tree bt;
typedef struct avl_tree avl;

struct binary_tree
{
    int item;
    bt *left;
    bt *right;
};

bt *create_bt(int item, bt *left, bt *right)
{
    bt *new_bt = (bt*) malloc(sizeof(bt));
    new_bt->item = item;
    new_bt->left = left;
    new_bt->right = right;

    return new_bt;
}

bt *add_leaf_bt(bt *tree, int item)
{
    if(tree == NULL)
    {
        tree = create_bt(item, NULL, NULL);
    }
    else if(tree->item > item)
    {
        tree->left = add_leaf_bt(tree->left, item);
    }
    else
    {
        tree->right = add_leaf_bt(tree->right, item);
    }

    return tree;
}


//		### AVL ###


struct avl_tree
{
    int item;
    int h;
    avl *left;
    avl *right;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(avl *tree)
{
    if(tree == NULL)
    {
        return -1;
    }
    else
    {
        return 1 + max(height(tree->left), height(tree->right));
    }
}

avl *create_avl(int item, avl *left, avl *right)
{
    avl *new_avl = (avl*)malloc(sizeof(avl));
    new_avl->item = item;
    new_avl->left = left;
    new_avl->right = right;
    new_avl->h = height(new_avl);

    return new_avl;
}

avl *rotate_left(avl *tree)
{
    avl *subtree_root = NULL;
    if(tree != NULL && tree->right != NULL)
    {
        subtree_root = tree->right;
        tree->right	= subtree_root->left;
        subtree_root->left = tree;
    }
    subtree_root->h = height(subtree_root);
    tree->h = height(tree);

    return subtree_root;
}

avl *rotate_right(avl *tree)
{
    avl *subtree_root = NULL;
    if(tree != NULL & tree->left != NULL)
    {
        subtree_root = tree->left;
        tree->left = subtree_root->right;
        subtree_root->right = tree;
    }
    subtree_root->h = height(subtree_root);
    tree->h = height(tree);

    return subtree_root;
}

int balance_factor(avl *tree)
{
    if(tree != NULL)
    {
        return (height(tree->left) - height(tree->right));
    }
    return 0;
}

avl *add_leaf_avl(avl *tree, int item)
{
    if(tree == NULL)
    {
        return create_avl(item, NULL, NULL);
    }
    else if(tree->item > item)
    {
        tree->left = add_leaf_avl(tree->left, item);
    }
    else
    {
        tree->right = add_leaf_avl(tree->right, item);
    }

    tree->h = height(tree);
    avl *child;

    if(balance_factor(tree) == 2 || balance_factor(tree) == -2)
    {
        if(balance_factor(tree) == 2)
        {
            child = tree->left;
            if(balance_factor(child) == -1)
            {
                tree->left = rotate_left(child);
            }
            tree = rotate_right(tree);
        }
        else if(balance_factor(tree) == -2)
        {
            child = tree->right;

            if(balance_factor(child) == 1)
            {
                tree->right = rotate_right(child);
            }
            tree = rotate_left(tree);
        }
    }
    return tree;
}

int ABB_AVL_counter(avl *tree, int item)
{
    if(tree == NULL || tree->item == item)
    {
        return 1;
    }
    else if(tree->item > item)
    {
        return 1 + ABB_AVL_counter(tree->left, item);
    }
    else
    {
        return 1 + ABB_AVL_counter(tree->right, item);
    }
}





//void gerar_comparacoes(int final, node *list, bs_tree *bt, FILE *output, int *sorted_numbers, int *visited);

int main()
{
    node* list = create_linked_list();
    bs_tree* bt = create_empty_bst();

    int final, num, i;

    printf("Digite o numero final do intervalo (0 - numero)\n");
    scanf("%d", &final);

    FILE *out = fopen("../ot.txt", "w+b");
    srand(time(NULL));

    int sorted_numbers[100];
    for (i = 0; i < 100; i++)
	{
        num = rand() % final;
        sorted_numbers[i] = num;
        list = add_ending(list, num);
        bt = add_bst(bt, num);

    }


    int comp_list = 0, comp_bst = 0;
    for (i = 0; i < 100; i++)
    {
            num = rand() % 100;
            comp_list = search_list(list, sorted_numbers[num]);
            comp_bst = search_bst(bt, sorted_numbers[num]);

            if (comp_list != -1)
                fprintf(out, "%d %d %d\n", sorted_numbers[num], comp_list, comp_bst);

    }

    fclose(out);

    printf("blz andre\n");
    return 0;
}

void gerar_comparacoes(int final, node *list, bs_tree *bt, FILE *output, int *sorted_numbers, int *visited)
{
    int comp_list = 0, comp_bst = 0, num, i;
    for (i = 0; i < 5000; i++)
    {
        if (!visited[i])
        {
            num = rand() % final;
            comp_list = search_list(list, sorted_numbers[num]);
            comp_bst = search_bst(bt, sorted_numbers[num]);

            fprintf(output, "%d %d %d\n", sorted_numbers[num], comp_list, comp_bst);

            visited[i] = 1;
        }
    }
}