#ifndef HUFFMAN_HUFF_TREE_H
#define HUFFMAN_HUFF_TREE_H

#include "heap.h"
#include "hash.h"

/* Huffman Tree */
typedef struct TREE{
    long long int frequency;
    unsigned char c;
    struct TREE *left;
    struct TREE *right;
} TREE;

//Functions

/**
*	Verifica se a árvore está vazia
*   @param: árvore binária
* 	@return: 1 para verdadeiro e 0 para falso
**/
int empty_tree(TREE *tree);

/**
*	Verifica se a árvore é uma folha (não tem filho à esquerda nem à direita)
*   @param: árvore binária
* 	@return: 1 para verdadeiro e 0 para falso
**/
int is_leaf(TREE *tree);

/**
*	Verifica se a árvore é uma folha e se o caracter é igual a '*' ou '\'
*   @param: árvore binária
*   @param: character
* 	@return: 1 para verdadeiro e 0 para falso
**/
int escape_char(TREE *tree, unsigned char c);

/**
*   @param: árvore binária
* 	@return: tamanho da árvore
**/
short tree_size(TREE *tree);


/**
*	Libera o espaço utilizado pela árvore binária
*   @param: árvore binária
**/
void free_tree(TREE *tree);

/**
*	Aloca e preenche o nó de uma árvore binária
*   @param: caracter
*   @param: frequência (do caracter)
*   @param: árvore filha à esquerda
*   @param: árvore filha à direita
* 	@return: nó de árvore binária
**/
TREE *create_node(unsigned char character, long long int frequency, TREE *left, TREE *right);


/**
*	Percorre e armazena todos os caminhos da árvore de huffman
*   @param: árvore binária
*   @param: hash table para armazenar todos os caminhos
*   @param: character que armazena 1 caminho temporariamente
**/
void map_paths(TREE *tree, HASH *hash, char *path, int i);

/**
*	Cria e preenche uma árvore de Huffman
*   @param: heap com os bytes para preencher a árvore de Huffman
*   @return: árvore de Huffman
**/
TREE *create_huffman_tree(HEAP *heap);

/**
*	Lê uma árvore binária escrita em pré-ordem num arquivo
*   @param: árvore binária
*   @param: arquivo onde está escrita a árvore binária
*   @param: tamanho da árvore binária
*   @return: árvore binária
**/
TREE *read_pre_order_tree(TREE *tree, FILE *input, int *tree_size);

/**
*	Escreve uma árvore binária em pré-ordem num arquivo
*   @param: árvore binária
*   @param: arquivo de saída da árvore
**/
void write_pre_order_tree(TREE *tree, FILE *output);


#endif //HUFFMAN_HUFF_TREE_H
