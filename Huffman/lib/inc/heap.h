#ifndef HUFFMAN_HEAP_H
#define HUFFMAN_HEAP_H

#define HEAP_MAX_SIZE 257

#include "typedefs.h"

/** Heap - Fila de prioridade **/
typedef struct HEAP HEAP;
struct HEAP {
    int size;
    void *data[HEAP_MAX_SIZE];
};

/** Nó auxiliar **/
typedef struct _node {
    lli priority;
    void *data;
} _node;

/**
 * Cria um nó dinamicamente para encapsular o novo item da heap e sua prioridade
 *
 * @param priority      a prioridade do novo item
 * @param data          os dados do novo item da heap
 * @return              o nó criado
 */
_node* _create_node(lli priority, void *data);

/**
 * Aloca memória para criar um heap
 *
 * @return     o novo heap criado
 */
HEAP *create_heap();

/**
 * Obtém o índice do nó pai
 *
 * @param i    o índice de um nó do heap
 * @return     o índice do nó pai, calculado como: (i/2)
 */
int get_parent_index(int i);

/**
 * Obtém o índice do filho da esquerda
 *
 * @param i    o índice de um nó do heap
 * @return     o índice do filho da esquerda, calculado como: (2*i)
 */
int get_left_index(int i);

/**
 * Obtém o índice do filho da direita
 *
 * @param i    o índice de um nó do heap
 * @return     o índice do filho da direita, calculado como: [(2*i)+1]
 */
int get_right_index(int i);

/**
 * Troca a posição de dois itens do heap
 *
 * @param **item_1     o item a ser trocado
 * @param **item_2     o item a ser trocado
 */
void swap_data(void **item_1, void **item_2);

/**
 * Adiciona um nó da árvore de huffman na fila de prioridade(Heap)
 *
 * @param *heap        o heap
 * @param priority     a prioridade do novo item
 * @param *data        os dados do novo item
 * @return             enfileira o nó na fila de prioridade(heap)
 */
void enqueue(HEAP *heap, lli priority, void *data);

/** 
 * Mantém as carateríticas do heap mínimo
 *
 * @param *heap    o heap
 * @param          i a posição do nó que deve ser comparado com os filhos
 */
void min_heapify(HEAP *heap, int i);

/**
 * Desenfileira um item da fila de prioridade(Heap)
 *
 * @param *heap    o heap
 */
void* dequeue(HEAP *heap);

/**
 * Libera toda a estrutura do heap da memória
 *
 * @param heap      o heap a ser liberado da memória
 */
void free_heap(HEAP *heap);


#endif //HUFFMAN_HEAP_H
