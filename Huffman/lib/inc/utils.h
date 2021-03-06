#ifndef HUFFMAN_UTILS_H
#define HUFFMAN_UTILS_H

#include <stdio.h>
#include "heap.h"
#include "hash.h"
#include "huff_tree.h"

/**
 * 	Preenche uma fila de prioridade(heap), a partir de um array de frequência de caracteres
 *
 * 	@param *frequency      array com a frequência dos caracteres
 * 	@param heap            heap a ser preenchida
 */
void create_priority_queue(lli *frequency, HEAP *heap);

/**
 * Retorna a frequência que cada caractere se repete em um arquivo
 *
 * @param *file        o arquivo
 * @return             array com a frequência de cada caracter
 */
lli *frequency_counter(FILE *file);

/**
 * Constrói uma heap a partir da frequência dos caracteres de um arquivo
 *
 * @param *file        o arquivo
 * @return             heap construída
 */
HEAP *mount_heap(FILE *file);

/**
 * Verifica se a alocação de memória foi feita de forma correta
 *
 * @param *mem         o ponteiro para o espaço de memória alocado
 */
void check_malloc(void *mem);

/**
 * Concatena 2 arrays de char
 *
 * @param *s1      prefixo
 * @param *s2      sufixo
 * @return         array concatenado de *s1 e *s2
 */
char* concat(char *s1, char *s2);


#endif //HUFFMAN_UTILS_H
