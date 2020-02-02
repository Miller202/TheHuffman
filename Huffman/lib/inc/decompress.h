#ifndef HUFFMAN_DECOMPRESS_H
#define HUFFMAN_DECOMPRESS_H

#include "heap.h"
#include "hash.h"
#include "huff_tree.h"

/**
 * Verifica se o bit do caracter está definido
 *
 * @param c        o caractere
 * @param i        a posição do bit
 * @return        1 se o bit do caractere está definido, 0 se não
  */
int is_bit_set(u_char c, int i);

/**
 * Obtém o tamanho do lixo do arquivo
 *
 * @param *input       o ponteiro do arquivo de entrada
 * @return             o tamanho do lixo do arquivo
 */
int get_trash_size(FILE *input);

/**
 * Obtém o tamanho da árvore escrita no arquivo
 *
 * @param *input       o ponteiro do arquivo de entrada
 * @return             o tamanho da árvore do arquivo
 */
short get_tree_size_from_file(FILE *input);

/**
 * Obtém a árvore a partir do arquivo .huff
 *
 * @param *input       o ponteiro do arquivo de entrada
 * @param *tree        o ponteiro de uma árvore criada
 * @return             o tamanho da árvore do arquivo
 */
TREE* get_hufftree(FILE *input, TREE* tree);

/**
 * Função auxiliar de decompress.
 * Realiza a descompactação do arquivo que possui apenas 1 tipo de caractere da tabela ascii.
 *
 * @param *input       o ponteiro do arquivo de entrada
 * @param *output      o ponteiro do arquivo de saída
 * @param *tree        o ponteiro da árvore criada por get_hufftree
 * @param trash_size   o tamanho do lixo da árvore
 */
void decompress_one_ascii_file(FILE* input, FILE* output, TREE* tree, int trash_size);

/**
 * Função auxiliar de decompress. Realiza a descompactação do arquivo.
 *
 * @param *input       o ponteiro do arquivo de entrada
 * @param *output      o ponteiro do arquivo de saída
 * @param *tree        o ponteiro da árvore criada por get_hufftree
 * @param trash_size   o tamanho do lixo da árvore
 */
void decompress_file(FILE* input, FILE* output, TREE* tree, int trash_size);

/**
 * Realiza a descompactação do arquivo.
 *
 * @param *input       o ponteiro do arquivo de entrada
 * @param *output      o ponteiro do arquivo de saída
 */
void decompress(FILE *input, FILE *output);

#endif //HUFFMAN_DECOMPRESS_H