#ifndef HUFFMAN_HUFF_TREE_H
#define HUFFMAN_HUFF_TREE_H

#include "heap.h"
#include "hash.h"

/** Árvore de Huffman **/
typedef struct TREE{
    long long int frequency;
    unsigned char c;
    struct TREE *left;
    struct TREE *right;
} TREE;

/**
 * Verifica se a árvore está vazia
 *
 * @param: *tree árvore binária
 * @return: 1 para verdadeiro e 0 para falso
 */
int is_empty(TREE *tree);

/**
 * Verifica se a árvore é uma folha (não tem filho à esquerda nem à direita)
 *
 * @param: *tree árvore binária
 * @return: 1 para verdadeiro e 0 para falso
 */
int is_leaf(TREE *tree);

/**
 * Verifica se a árvore é uma folha e se o caracter é igual a '*' ou '\'
 *
 * @param: *tree árvore binária
 * @param: c character
 * @return: 1 para verdadeiro e 0 para falso
 */
int is_escape_char(TREE *tree, unsigned char c);

/**
 * Obtém o tamanho da árvore
 *
 * @param: *tree árvore binária
 * @return: tamanho da árvore
 */
unsigned short get_tree_size(TREE *tree);

/**
 * Desaloca a árvore binária da memória
 *
 * @param: *tree árvore binária
 */
void free_tree(TREE *tree);

/**
 * Aloca e preenche o nó de uma árvore binária
 *
 * @param: character caractere
 * @param: frequency frequência do caractere
 * @param: *left árvore filha à esquerda
 * @param: *right árvore filha à direita
 * @return: nó de árvore binária
 */
TREE *create_node(unsigned char character, long long int frequency, TREE *left, TREE *right);

/**
 * Percorre e armazena todos os caminhos da árvore de huffman
 *
 * @param: *tree árvore binária
 * @param: *hash hash table para armazenar todos os caminhos
 * @param: *path armazena um caminho temporariamente
 */
void map_paths(TREE *tree, HASH *hash, char *path, int i);

/**
 * Cria e preenche uma árvore de Huffman
 *
 * @param: *heap heap com os bytes para preencher a árvore de Huffman
 * @return: árvore de Huffman
 */
TREE *create_huffman_tree(HEAP *heap);

/**
 * Escreve uma árvore binária em pré-ordem em um arquivo
 *
 * @param: *tree árvore binária
 * @param: *output arquivo de saída da árvore
 */
void write_pre_order_tree(TREE *tree, FILE *output);


void print_tree_node(TREE *t);
void print_tree_pre_order(TREE *t);
void print_tree_pre_order_char(TREE *t);


#endif //HUFFMAN_HUFF_TREE_H
