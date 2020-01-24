#ifndef HUFFMAN_UTILS_H
#define HUFFMAN_UTILS_H

#include <stdio.h>
#include "heap.h"
#include "hash.h"
#include "huff_tree.h"

/**
* 	Criar uma fila de prioridade(heap), a partir da frequência dos caracteres do arquivo
* 	@param: recebe um array com a frequencia dos caracteres e um heap
*	@return: cria nós com caracteres de qualquer frequencia e os enfileira no heap
**/
void create_priority_queue(long long int *frequency, HEAP *heap);

/**
* 	@param: recebe o ponteiro do arquivo de entrada
*	@return: retorna um array com as frequências dos caracteres do arquivo
**/
long long int *frequency_counter(FILE *file);

/**
* 	@param: recebe o ponteiro do arquivo de entrada
*	@return: constrói o heap
**/
HEAP *mount_heap(FILE *file);

void print_tree_node_heap(void *tree);

#endif //HUFFMAN_UTILS_H
