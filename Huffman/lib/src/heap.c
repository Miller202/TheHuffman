#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "heap.h"

typedef struct _node {
    lli priority;
    void *data;
} _node;

_node* _create_node(lli priority, void *data)
{
    _node *new_node = (_node *) malloc(sizeof(_node));

    new_node->priority = priority;
    new_node->data = data;

    return new_node;
}

HEAP *create_heap()
{
    HEAP *heap = (HEAP *) malloc(sizeof(HEAP));

    heap->size = 0;

    for (int i = 1; i < HEAP_MAX_SIZE; ++i)
    {
        heap->data[i] = NULL;
    }

    return heap;
}

int get_parent_index(int i)
{
    return (i / 2);
}

int get_left_index(int i)
{
    return (2 * i);
}

int get_right_index(int i)
{
    return (2 * i + 1);
}

void swap_data(void **item_1, void **item_2)
{
    void *aux = *item_1;
    *item_1 = *item_2;
    *item_2 = aux;
}

lli get_priority(HEAP *h, int index)
{
    return ((_node *) h->data[index])->priority;
}

void enqueue(HEAP *heap, lli priority, void *item)
{
    if (heap->size >= HEAP_MAX_SIZE - 1)
    {
        printf("Heap overflow.\n");
    }
    else
    {
        _node *new_node = _create_node(priority, item);

        //Insere o nó na última posição na fila de prioridade;
        heap->data[++heap->size] = new_node;

        // Guarda o índice atual
        int key_index = heap->size;

        // Guarda o índice do pai;
        int parent_index = get_parent_index(key_index);

        //Enquanto a frequência do índice atual for maior que a do seu pai, troque suas posições.
        while (parent_index >= 1 && get_priority(heap, key_index) < get_priority(heap, parent_index))
        {
            // troca as posições
            swap_data(&heap->data[parent_index], &heap->data[key_index]);

            //Atualiza o índice;
            key_index = parent_index;

            //Guarda o índice do novo pai;
            parent_index = get_parent_index(key_index);
        }
    }
}

void min_heapify(HEAP *heap, int i)
{
    int smallest;
    int left_index = get_left_index(i);
    int right_index = get_right_index(i);

    _node *t = heap->data[i];
    _node *t_l = heap->data[left_index];
    _node *t_r = heap->data[right_index];

    if (left_index <= heap->size && t_l->priority < t->priority)
    {
        smallest = left_index;
    }
    else
    {
        smallest = i;
    }

    _node *t_s = heap->data[smallest];

    if (right_index <= heap->size && t_r->priority < t_s->priority)
    {
        smallest = right_index;
        t_s = heap->data[smallest];
    }

    if (t != t_s)
    {
        swap_data(&heap->data[i], &heap->data[smallest]);
        min_heapify(heap, smallest);
    }
}

void *dequeue(HEAP *heap)
{
    if (!(heap->size))
    {
        printf("Heap underflow.\n");
        return NULL;
    }
    else
    {
        /* Desenfileira o item da primeira posição da heap*/
        _node *item = (_node *) heap->data[1];

        // item da última posição é colocado na primeira
        heap->data[1] = heap->data[heap->size];

        //após o desenfileiramento a propriedade da heap foi quebrada
        heap->size -= 1;

        // portanto, chamamos a min_heapify para organizar a heap
        min_heapify(heap, 1);

        //retorna o item que foi desenfileirado
        return item->data;
    }
}


void print_heap(HEAP *heap, void (*print_func)(void *data))
{
    for (int i = 1; i <= heap->size; ++i)
    {
        print_func(((_node *) heap->data[i])->data);
        printf(" ");
    }
}