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
        int cmp = btree->comp_keys(*key, page->items[i].key);
        if(cmp == 0){ // item já existe
            return page->items[i].value;
        }
        if(cmp > 0){
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

void* search_btree(btree *btree, void *key)
{
	btree_page *page = btree->top;

	while (page!=0) {//Percorre pages
		size_t left = 0, right = page->size;
		while (left < right) { //Percorre as chaves da page
			size_t middle = (left + right) / 2;
			int cmp = btree->comp_keys(key, page->items[middle].key);
			if (cmp == 0)
				return page->items[middle].value;			
			else if(cmp > 0)//Key é maior que a key à esquerda
				left = middle + 1;
            else
                right = middle;//Key é menor que a key à direita
            
		}
		page = page->items[left].child;
	}
	return NULL;
}

btree_page *collapse(btree_page *page)
{
    btree_page *child = page->items[0].child;
    free(page);
    return child;
}

void get_smallest(btree_page *page, void **key, void **value)
{
    btree_page *child = page->items[0].child;
    if (child == NULL) {
        remove_page(page, 0, &key, &value);
        return;
    }
    get_smallest(child, key, value);
    if (child->size == 0)
        page->items[0].child = collapse(child);
}

void get_largest(btree_page *page, void **key, void **value)
{
    btree_page *child = page->items[page->size].child;
    if (child == NULL) {
        remove_page(page, page->size - 1, &key, &value);
        return;
    }
    get_largest(child, key, value);
    if (child->size == 0)
        page->items[page->size].child = collapse(child);
}

void remove_page(btree_page *page, size_t i, void **key, void **value)
{
    *key = page->items[i].key;
    *value = page->items[i].value;
    btree_page *left_child = page->items[i].child;
    btree_page *right_child = page->items[i + 1].child;

    if (left_child && right_child) {
        if (left_child->size > right_child->size) {
            get_largest(left_child, &key, &value);
            if (left_child->size == 0)
                page->items[i].child = collapse(left_child);
        } else {
            get_smallest(right_child, &key, &value);
            if (right_child->size == 0)
                page->items[i + 1].child = collapse(right_child);
        }
        page->items[i].key = key;
        page->items[i].value = value;
        return;
    }

    memmove(&page->items[i], &page->items[i + 1],
            (page->size - i) * sizeof(btree_item));
    page->size--;

    if (left_child)
        page->items[i].child = left_child;
    else
        page->items[i].child = right_child;
}

void *delete_page(btree *btree, btree_page *page, void *key)
{
    size_t left = 0, right = page->size, i;
    while (left < right) {
        i = (left + right) / 2;
        int cmp = btree->comp_keys(key, page->items[i].key);
        if (cmp == 0)
            break;
        if (cmp > 0)
            left = i + 1;
        else
            right = i;
    }

    if (left == right) {
        /* Ainda não foi encontrado, Recursão: */
        i = left;
        btree_page *child = page->items[i].child;
        if (child == NULL)
            return NULL;
        void *temp = delete_page(btree, child, key);
        if (child->size == 0)
            page->items[i].child = collapse(child);
        return temp;
    }

    void *temp = NULL;
    remove_page(page, i, &key, &temp);
    return temp;
}
