#ifndef HUFFMAN_COMPRESS_H
#define HUFFMAN_COMPRESS_H


#include "hash.h"
#include "huff_tree.h"


/**
 * Transforma um bit de um caractere em 1
 *
 * @param c        o caractere
 * @param i        a quantidade de bits que o último bit do byte 1 será deslocado
 *                  da esquerda pra direita(0-7 contando do final ao inicio)
 * @return         O caractere com o bit atualizado
 */
u_char set_bit(u_char c, int i);

/**
 * Comprime um arquivo
 *
 * @param *input       o arquivo a ser comprimido
 * @param *output      o arquivo onde será escrita a compactação
 */
void compress_file(FILE *input, FILE *output);

/**
 * Escreve o tamanho de uma árvore binária em um arquivo
 *
 * @param size_tree        o tamanho da árvore binária
 * @param *file            o arquivo onde será escrito o tamanho
 */
void write_tree_size(u_short size_tree, FILE *file);

/**
 * Escreve o tamanho do lixo de compressão nos 3 primeiros bits de um arquivo
 *
 * @param trash        o tamanho do lixo
 * @param *file        o arquivo onde será escrito o tamanho
 */
void write_trash(u_char trash, FILE *file);

/**
 * Escreve a mensagem compactada em um arquivo, caso o arquivo original possua apenas 1 tipo de caractere da tabela ascii.
 * Cada caractere do arquivo original corresponderá ao bit 0 no arquivo compactado
 *
 * @param *input       o arquivo com os caracteres originais
 * @param *output      o arquivo compactado
 * @return             quantidade de bits de lixo no byte final do arquivo
 */
u_char write_one_ascii_char_doc(FILE *input, FILE *output);

/**
 * Escreve a mensagem compactada em um arquivo, com base no mapeamento recebido e retorna o tamanho do lixo de compactação
 *
 * @param *input       o arquivo com os caracteres originais
 * @param *output      o arquivo compactado
 * @param *paths       o novo mapeamento dos caracteres do arquivo de entrada
 * @return             quantidade de bits de lixo no byte final do arquivo
 */
u_char write_compress_doc(FILE *input, FILE *output, HASH *paths);


#endif //HUFFMAN_COMPRESS_H
