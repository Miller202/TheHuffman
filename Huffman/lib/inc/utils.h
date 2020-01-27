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

/**
*   Verifica se a alocação de memória foi feita de forma correta
*   @param: ponteiro para o espaço de memória alocado
**/
//void  // check_malloc(void *mem);    //TODO ENCONTRAR ALGUM ARQUIVO PRA COLOCAR

/**
*   Concatena 2 arrays de char
*   @param: prefixo
*   @param: sufixo
*   @return: array concatenado
**/
char* concat(char *s1, char *s2);

void print_tree_node_heap(void *tree);

#endif //HUFFMAN_UTILS_H
