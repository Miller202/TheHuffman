#ifndef HUFFMAN_DECOMPRESS_H
#define HUFFMAN_DECOMPRESS_H

#include "heap.h"
#include "hash.h"
#include "huff_tree.h"

/**
 *  Verifica se o bit do caracter está definido
 *
 *  @param: c o caracter
 *  @param i a posição do bit
 *  @return: 1 se o bit do caractere está definido, 0 se não
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
short get_tree_size_from_file(FILE *input);

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
* 	@param: recebe o ponteiro do arquivo de entrada
*   @param: recebe o ponteiro do arquivo de saída
*	@return: Realiza a decompactação do arquivo
**/
void decompress(FILE *input, FILE *output);

#endif //HUFFMAN_DECOMPRESS_H