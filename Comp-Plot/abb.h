#include <stdio.h>
#include <stdlib.h>

typedef struct binary_search_tree bs_tree;

struct binary_search_tree{
    int item;
    bs_tree *left;
    bs_tree *right;
};

bst* create_empty_bst(); // criar árvore vazia
bs_tree* create_node_bst(int item, bs_tree *left, bs_tree *right); // criar um novo nó
bs_tree* add_bst(bs_tree *bst, int item); // adicionar um item na árvore
bs_tree* search_bst(bs_tree *bst, int item); // buscar um item na árvore
