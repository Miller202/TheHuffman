#include <stdio.h>
#include <stdlib.h>

typedef struct binary_search_tree bs_tree;

struct binary_search_tree{
    int item;
    bs_tree *left;
    bs_tree *right;
};

bs_tree* create_empty_bst(); // criar árvore vazia
bs_tree* create_node_bst(int item, bs_tree *left, bs_tree *right); // criar um novo nó
bs_tree* add_bst(bs_tree *bst, int item); // adicionar um item na árvore
int search_bst(bs_tree *bst, int item, int *comp_bt); // buscar um item na árvore
