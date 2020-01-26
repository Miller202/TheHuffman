#ifndef HUFFMAN_COMPRESS_H
#define HUFFMAN_COMPRESS_H

#include "heap.h"
#include "hash.h"
#include "huff_tree.h"


/**
*   Transforma um bit de um caracter  em 1
* 	@param: recebe um caracter e a posição do bit no caracter (0-7 contando do final ao inicio)
*	@return: O caracter com o bit atualizado
**/
unsigned char set_bit(unsigned char c, int i);

/**
*   Comprime um arquivo
*   @param: arquivo a ser comprimido
*   @param: arquivo onde será escrita a compactação
**/
void compress_file(FILE *input, FILE *output);

/**
*   Abre o arquivo a ser comprimido e o arquivo em que será escrita a compactação
*   @param: diretório do arquivo a ser comprimido
*   @param: arquivo onde será escrita a compactação
**/
void open_files (char *input_name);

/**
*   Escreve o tamanho de árvore binária em um arquivo
*   @param: árvore binária
*   @param: arquivo onde será escrita o tamanho
**/
void write_tree_size(TREE *tree, FILE *file);

/**
*   Escreve o tamanho do lixo nos 3 primeiros bits de um arquivo
*   @param: tamanho do lixo
*   @param: arquivo onde será escrita o tamanho
**/
void write_trash(unsigned char trash, FILE *file);

/**
*   Escreve a mensagem compactada em um arquivo, com base no mapeamento recebido e retorna o tamanho do lixo
*   @param: novo mapeamento dos caracteres do arquivo de entrada
*   @param: arquivo com os caracteres originais
*   @param: arquivo compactado
*   @return: quantidade de bits de lixo no byte final do arquivo
**/
unsigned char write_compress_doc(FILE *input, FILE *output, HASH *paths);


#endif //HUFFMAN_COMPRESS_H
