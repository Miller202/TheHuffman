#include "B-Tree.h"

void start_btree(btree *btree)
{
    btree->top = NULL;
    btree->num_keys = M - 1;
    btree->comp_keys = NULL;
}

btree_page create_page(btree *btree)
{
    size_t size = sizeof(btree_page) + sizeof(btree_item) * sizeof(M);
    btree_page *page = malloc(size);

    if(page == NULL){ return NULL;}
    memset(page, 0, size);
    return page;
}

btree_page* split_page(btree *btree, btree_page *page, void **key, void **value)
{
    *key = page->items[btree->num_keys / 2].key;
    *value = page->items[btree->num_keys / 2].value;

    page->size = btree->num_keys / 2;
    btree_page *new_page = create_page(btree);
    new_page = (btree->num_keys / 2) - 1;

    // copia o conteúdo dos item da posição [(btree->num_keys/2)+1] para o item da nova página
    memcpy(new_page->items, &page->items[(btree->num_keys / 2) + 1], (btree->num_keys / 2) * sizeof(btree_item));

    return new_page;
}

void* insert_page(btree *btree, btree_page *page, void **key, void **value)
{
    size_t left = 0, right = page->size;
    while(left < right)
    {
        size_t i = (left + right) / 2;
        int comp = btree->comp_keys(*key, page->items[i].key);
        if(comp == 0){ // item já existe
            return page->items[i].value;
        }
        if(comp > 0){
            left = i + 1;
        }else{
            right = i;
        }
    }
    size_t i = left;

    btree_page *child = page->items[i].child;
    btree_page *right_child = NULL;
    void *temp = NULL;

    if(!child){
        temp = *value;
    }else{
        temp = insert_page(btree, child, key, value);
        if(child->size < btree->num_keys){
            return temp;
        }
        right_child = split_page(btree, child, key, value);
    }

    page->size++;
    /* copia o conteúdo do item da posição i para a posição i+1;
    * a diferença pra o memcpy é que o memmove lida com a sobreposição de memória */
    memmove(&page->items[i+1], &page->items[i], (page->size - 1) * sizeof(btree_item));
    page->items[i].key = *key;
    page->items[i].value = *value;
    page->items[i].child = child;
    page->items[i+1].child = right_child;
    return temp;
}

void* insert_btree(btree *btree, void *key, void *value)
{
    btree_page *right_child = NULL;
    void *temp = NULL;

    if(btree->top){
        temp = insert_page(btree, btree->top, &key, &value);
        if(btree->top->size < btree->num_keys){
            return temp;
        }
        right_child = split_page(btree, btree->top, &key, &value);
    }else{
        temp = value;
    }

    btree_page *page = create_page(btree);
    page->size = 1;
    page->items[0].key = key;
    page->items[0].value = value;
    page->items[0].child = btree->top;
    page->items[1].child = right_child;

    btree->top = page;
    return temp;
}



