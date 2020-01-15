#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/heap.h"
#include "../inc/huff_tree.h"

HEAP *create_heap() {
    HEAP *heap = (HEAP *) malloc(sizeof(HEAP));
    int i;

    heap->size = 0;
    for (i = 1; i <= 256; ++i) {
        heap->data[i] = NULL;
    }

    return heap;
}

int get_parent_index(int i) { return i / 2; }

int get_left_index(int i) { return 2 * i; }

int get_right_index(int i) { return 2 * i + 1; }

void swap_data(void **item_1, void **item_2) {

    void *aux;
    aux = *item_1;
    *item_1 = *item_2;
    *item_2 = aux;

}

void swap_node(HEAP *heap, int i, int j) {
    TREE *temp;
    temp = heap->data[i];
    heap->data[i] = heap->data[j];
    heap->data[j] = temp;
}


void enqueue(HEAP *heap, void *item) {
    if (heap->size >= 256) {
        printf("Heap overflow.\n");
    } else {
        heap->data[++heap->size] = item; //Insere o nó na última posição na fila de prioridade;
        int key_index = heap->size; // Guarda o índice atual
        int parent_index = get_parent_index(key_index); // Guarda o índice do pai;


        //Enquanto a frequência do índice atual for maior que a do seu pai, troque suas posições.
        while (parent_index >= 1 && ((TREE *)heap->data[key_index])->frequency < ((TREE *)heap->data[parent_index])->frequency) {
            //swap_data(&heap->data[parent_index], &heap->data[key_index]); // troca as posições
            swap_node(heap, key_index, parent_index);
            key_index = parent_index; //Atualiza o índice;
            parent_index = get_parent_index(key_index); //Guarda o índice do novo pai;
        }
    }
}

void min_heapify(HEAP *heap, int i) {
    int smallest;
    int left_index = get_left_index(i);
    int right_index = get_right_index(i);

    TREE *t = heap->data[i];
    TREE *t_l = heap->data[left_index];
    TREE *t_r = heap->data[right_index];

    if (left_index <= heap->size && t_l->frequency < t->frequency) {
        smallest = left_index;
    } else {
        smallest = i;
    }

    TREE *t_s = heap->data[smallest];

    if (right_index <= heap->size && t_r->frequency < t_s->frequency) {
        smallest = right_index;
    }
    if (t->c != t_s->c) {
        swap_node(heap, i, smallest);
        //swap_data(&heap->data[i], &heap->data[smallest]);
        min_heapify(heap, smallest);
    }
}

void create_priority_queue(long long int frequency[], HEAP *heap) {
    int i;
    for (i = 0; i < 256; i++) {
        if (frequency[i] != 0) {
            enqueue(heap, create_node((unsigned char) i, frequency[i], NULL, NULL));
        }
    }
}

void *dequeue(HEAP *heap) {
    if (!(heap->size)) {
        printf("Heap underflow.\n");
        return NULL;
    } else {
        /* Desenfileira o item da primeira posição da heap*/
        void *item = heap->data[1];
        heap->data[1] = heap->data[heap->size]; // item da última posição é colocado na primeira
        heap->size -= 1; //após o desenfileiramento a propriedade da heap foi quebrada
        min_heapify(heap, 1); // portanto, chamamos a min_heapify para organizar a heap
        return item; //retorna o item que foi desenfileirado
    }
}

long long int *frequency_counter(FILE *file) {

    long long int *frequency = calloc(256, sizeof(long long int));
    unsigned char item;

    while (fscanf(file, "%c", &item) != EOF) {
        frequency[(int) item]++;
    }

    return frequency;
}

HEAP *mount_heap(FILE *file)
{
    HEAP *heap = create_heap();
    long long int *frequency = frequency_counter(file);
    create_priority_queue(frequency, heap);

    return heap;
}