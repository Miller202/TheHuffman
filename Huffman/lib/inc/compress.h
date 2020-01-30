#ifndef HUFFMAN_COMPRESS_H
#define HUFFMAN_COMPRESS_H


#include "hash.h"
#include "huff_tree.h"


/**
 *  Transforma um bit de um caracter em 1
 * 	@param: c caracter
 * 	@param: i a quantidade de bits que o último bit do byte 1 será deslocado
 * 	da esquerda pra direita(0-7 contando do final ao inicio)
 *  @return: O caracter com o bit atualizado
**/
unsigned char set_bit(unsigned char c, int i);

/**
 *  Comprime um arquivo
 *  @param: *input arquivo a ser comprimido
 *  @param: *output arquivo onde será escrita a compactação
**/
void compress_file(FILE *input, FILE *output);

/**
 *  Escreve o tamanho de uma árvore binária em um arquivo
 *  @param: *tree árvore binária
 *  @param: *file arquivo onde será escrita o tamanho
**/
void write_tree_size(TREE *tree, FILE *file);

/**
 *  Escreve o tamanho do lixo de compressão nos 3 primeiros bits de um arquivo
 *  @param: trash tamanho do lixo
 *  @param: *file arquivo onde será escrito o tamanho
**/
void write_trash(unsigned char trash, FILE *file);

/**
 *  Escreve a mensagem compactada em um arquivo, com base no mapeamento recebido e retorna o tamanho do lixo de compactação
 *  @param: *input arquivo com os caracteres originais
 *  @param: *output arquivo compactado
 *  @param: *paths novo mapeamento dos caracteres do arquivo de entrada
 *  @return: quantidade de bits de lixo no byte final do arquivo
**/
unsigned char write_compress_doc(FILE *input, FILE *output, HASH *paths);


#endif //HUFFMAN_COMPRESS_H
