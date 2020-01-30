#ifndef HUFFMAN_UTILS_H
#define HUFFMAN_UTILS_H

#include <stdio.h>
#include "heap.h"
#include "hash.h"
#include "huff_tree.h"

/**
 * 	Preenche uma fila de prioridade(heap), a partir de um array de frequência de caracteres
 * 	@param: *frequency array com a frequência dos caracteres
 * 	@param: heap heap a ser preenchida
**/
void create_priority_queue(long long int *frequency, HEAP *heap);

/**
 *  retorna a frequência que cada caracter se repete em um arquivo
 * 	@param: *file
 *  @return: array com a frequência de cada caracter
**/
long long int *frequency_counter(FILE *file);

/**
 *  Constrói uma heap a partir da frequência dos caracteres de um arquivo
 *  @param: *file arquivo
 *  @return: heap construída
**/
HEAP *mount_heap(FILE *file);

/**
 *   Verifica se a alocação de memória foi feita de forma correta
 *   @param: ponteiro para o espaço de memória alocado
**/
void check_malloc(void *mem);

/**
 *  Concatena 2 arrays de char
 *  @param: *s1 prefixo
 *  @param: *s2 sufixo
 *  @return: array concatenado de *s1 e *s2
**/
char* concat(char *s1, char *s2);

void print_tree_node_heap(void *tree);

#endif //HUFFMAN_UTILS_H
