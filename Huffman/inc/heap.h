#ifndef HUFFMAN_HEAP_H
#define HUFFMAN_HEAP_H

/* Heap - Priority Queue */
typedef struct HEAP HEAP;
struct HEAP{
    int size;
    void *data[256];
};

/*create_hash -> função para alocar memória para criar uma nova heap*/
HEAP *create_heap();

/* get_parent_index -> função para retornar o índice do nó do pai*/
int get_parent_index(int i);
/* get_left_index -> função para retornar o índice do filho da esquerda*/
int get_left_index(int i);
/* get_right_index -> função para retornar o índice do filho da direita*/
int get_right_index(int i);

/* swap -> Função para trocar a posição de dois nós da heap*/
void swap_data(void** item_1, void** item_2);

/*enqueue -> Função para adicionar um nó da árvore de huffman na fila de prioridade(Heap)*/
void enqueue(HEAP *heap, void *item);

/*min_heapify -> função de manutenção das carateríticas do heap mínimo*/
void min_heapify(HEAP *heap, int i);

/*create_prioority_queue -> função para criar uma fila de prioridade(heap),
a partir da frequência dos carácteres do arquivo*/
void create_priority_queue(long long int *frequency, HEAP *heap);

/*dequeue-> Função para desenfileirar um item da fila de prioridade(Heap)*/
void* dequeue(HEAP *heap);

/*frequency_counter -> função para retornar um array com as 
frequências dos caracteres do arquivo*/
long long int *frequency_counter(FILE *file);


#endif //HUFFMAN_HEAP_H
