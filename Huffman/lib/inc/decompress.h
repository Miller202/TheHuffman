#ifndef HUFFMAN_DECOMPRESS_H
#define HUFFMAN_DECOMPRESS_H

#include "heap.h"
#include "hash.h"
#include "huff_tree.h"
// #include <CUnit/CUnit.h>

/**
* 	@param: recebe o caracter e a posição do bit
*	@return: Verifica se o bit de um caractere está definido
**/
int is_bit_set(unsigned char c, int i);

/**
* 	@param: recebe o ponteiro do arquivo de entrada
*	@return: Retorna o tamanho do lixo do arquivo
**/
int get_trash_size(FILE *input);

/**
* 	@param: recebe o ponteiro do arquivo de entrada
*	@return: Retorna o tamanho da árvore do arquivo
**/
short get_tree_size(FILE *input);

/**
* 	@param: recebe o ponteiro do arquivo de entrada
*   @param: recebe o ponteiro de uma árvore criada
*	@return: Constrói a árvore do arquivo .huff
**/
TREE* get_hufftree(FILE *input, TREE* tree);

/**
* 	@param: recebe o ponteiro do arquivo de entrada
*   @param: recebe o ponteiro do arquivo de saída
*   @param: recebe a árvore do arquivo
*   @param: recebe o tamanho do lixo
*	@return: Realiza a descompactação do arquivo
**/
void decompress_file(FILE* input, FILE* output, TREE* tree, int trash_size);

/**
* 	@param: recebe o caminho do arquivo de entrada
*   @param: recebe o caminho do arquivo de saída
*	@return: Retorna o arquivo descompactado
**/
void decompress(char input_path[], char output_path[]);

#endif //HUFFMAN_DECOMPRESS_H