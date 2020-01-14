#ifndef HUFFMAN_HEAP_H
#define HUFFMAN_HEAP_H

/* Heap - Priority Queue */
typedef struct HEAP HEAP;
struct HEAP{
    int size;
    void *data[256];
};

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
* 	@param: recebe o heap e o nó que deve ser enfileirado
*	@return: enfileira o nó na fila de prioridade(heap)
**/
void enqueue(HEAP *heap, void *item);

/** 
*	Função de manutenção das carateríticas do heap mínimo
*	@param: recebe o heap e a posição do nó que deve ser comparado com os filhos
*	@return: cumpre as propriedades, mantendo os pais sendo menores que os filhos 
**/
void min_heapify(HEAP *heap, int i);

/**
* 	Criar uma fila de prioridade(heap), a partir da frequência dos caracteres do arquivo
* 	@param: recebe um array com a frequencia dos caracteres e um heap
*	@return: cria nós com caracteres de qualquer frequencia e os enfileira no heap
**/
void create_priority_queue(long long int *frequency, HEAP *heap);

/**
* 	Desenfileirar um item da fila de prioridade(Heap)
* 	@param: recebe o heap
*	@return: desenfileirará o nó na primeira posição do heap.
**/
void* dequeue(HEAP *heap);

/**
* 	@param: recebe o ponteiro do arquivo de entrada
*	@return: retorna um array com as frequências dos caracteres do arquivo 
**/
long long int *frequency_counter(FILE *file);

HEAP *mount_heap(FILE *file);


#endif //HUFFMAN_HEAP_H
