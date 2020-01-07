#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"
#include "hash.h"
#include "huff_tree.h"

#ifndef HUFFMAN_HEAP_H
#define HUFFMAN_HEAP_H

/*create_hash -> função para alocar memória para criar uma nova heap*/
heap *create_heap();

/* get_left_index -> função para retornar o índice do filho da esquerda*/
int get_left_index(int i);

/* get_right_index -> função para retornar o índice do filho da direita*/
int get_right_index(int i);

/* get_parent_index -> função para retornar o índice do nó do pai*/
int get_parent_index(int i);

/* swap -> Função para trocar a posição de dois nós da heap*/
void swap(heap *new_heap, int index_1, int index_2);

/*
void enqueue();
	
	- função deve receber a heap e o nó que vai ser 
	enfileirado em uma fila de prioridade;

	- primeiramente, a função tem que adicionar o nó no final da heap;
	- depois tem que fazer uma verificação, se o nó tem menos frequencia que o pai...
*/

#endif //HUFFMAN_HEAP_H
