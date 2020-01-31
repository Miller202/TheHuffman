#ifndef HUFFMAN_HEAP_H
#define HUFFMAN_HEAP_H

#define HEAP_MAX_SIZE 257

/** Heap - Priority Queue **/
typedef struct HEAP HEAP;
struct HEAP{
    int size;
    void *data[HEAP_MAX_SIZE];
};

typedef long long int lli;

/**
*	Aloca memória para criar um heap
* 	@return: retorna o novo heap que foi criado
**/
HEAP *create_heap();

/**
* 	@param: recebe o índice de um nó do heap
*	@return: retorna o índice do nó pai, calculado como: (i/2)
**/
int get_parent_index(int i);

/**
* 	@param: recebe o índice de um nó do heap
*	@return: retorna o índice do filho da esquerda, calculado como: (2*i)
**/
int get_left_index(int i);

/**
* 	@param: recebe o índice de um nó do heap
*	@return: retorna o índice do filho da direita, calculado como: [(2*i)+1]
**/
int get_right_index(int i);

/**
* 	Função para trocar a posição de dois itens do heap
* 	@param: recebe os dois itens
*	@return: posições do item_1 e item_2 trocadas
**/
void swap_data(void** item_1, void** item_2);

/**
* 	Adicionar um nó da árvore de huffman na fila de prioridade(Heap)
* 	@param: recebe o heap, a prioridade do novo item e seus dados
*	@return: enfileira o nó na fila de prioridade(heap)
**/
void enqueue(HEAP *heap, lli priority, void *item);

/** 
*	Função de manutenção das carateríticas do heap mínimo
*	@param: recebe o heap e a posição do nó que deve ser comparado com os filhos
*	@return: cumpre as propriedades, mantendo os pais sendo menores que os filhos 
**/
void min_heapify(HEAP *heap, int i);

/**
* 	Desenfileirar um item da fila de prioridade(Heap)
* 	@param: recebe o heap
*	@return: desenfileirará o nó na primeira posição do heap.
**/
void* dequeue(HEAP *heap);

void print_heap(HEAP *heap, void (*print_func)(void *data));

#endif //HUFFMAN_HEAP_H
