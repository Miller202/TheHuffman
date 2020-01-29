#include <stdio.h>
#include <stdlib.h>

#define M 5; // ordem da árvore

/* O cmp serve para comparar duas keys, retorna 0 se forem iguais*/
typedef int (*cmp_t)(void *key_1, void *key_2);

typedef struct btree_item{
    void *key;
    void *value;
    btree_page *child;
}btree_item;

typedef struct btree_page{
    size_t size;
    btree_item items[M];
}btree_page;

typedef struct btree
{
    btree_page *top;
    size_t num_keys;
    cmp_t comp_keys;
}btree;

void start_btree(btree *btree, cmp_t comp_keys, size_t num_keys); // inicia a árvore B
btree_page create_page(btree *btree); // Aloca espaço para criar uma nova página na árvore
btree_page* split_page(btree *btree, btree_page *page, void **key, void **value); // divide a página
void* insert_page(btree *btree, btree_page *page, void **key, void **value); // Insere uma chave na página
void* insert_btree(btree *btree, void *key, void *value); // Insere a página na árvore
void *search_btree(struct btree *btree, void *key); // pesquisar item na árvore

