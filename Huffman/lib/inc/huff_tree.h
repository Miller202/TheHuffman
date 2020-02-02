#ifndef HUFFMAN_HUFF_TREE_H
#define HUFFMAN_HUFF_TREE_H

#include "heap.h"
#include "hash.h"

/** Árvore de Huffman **/
typedef struct TREE{
    lli frequency;
    u_char c;
    struct TREE *left;
    struct TREE *right;
} TREE;

/**
 * Verifica se a árvore está vazia
 *
 * @param *tree        árvore binária
 * @return             1 para verdadeiro e 0 para falso
 */
int is_empty(TREE *tree);

/**
 * Verifica se a árvore é uma folha (não tem filho à esquerda nem à direita)
 *
 * @param *tree        árvore binária
 * @return             1 para verdadeiro e 0 para falso
 */
int is_leaf(TREE *tree);

/**
 * Verifica se a árvore é uma folha e se o caractere é igual a '*' ou '\'
 *
 * @param *tree        a árvore binária
 * @param c            o caractere
 * @return             1 para verdadeiro e 0 para falso
 */
int is_escape_char(TREE *tree, u_char c);

/**
 * Obtém o tamanho da árvore
 *
 * @param *tree        a árvore binária
 * @return             o tamanho da árvore
 */
u_short get_tree_size(TREE *tree);

/**
 * Desaloca a árvore binária da memória
 *
 * @param *tree        árvore binária
 */
void free_tree(TREE *tree);

/**
 * Aloca e preenche o nó de uma árvore binária
 *
 * @param character        o caractere
 * @param frequency        a frequência do caractere
 * @param *left            a árvore filha à esquerda
 * @param *right           a árvore filha à direita
 * @return                 o nó de árvore binária criado
 */
TREE *create_node(u_char character, lli frequency, TREE *left, TREE *right);

/**
 * Percorre e armazena todos os caminhos da árvore de huffman
 *
 * @param *tree        a árvore binária
 * @param *hash        a hash table para armazenar todos os caminhos
 * @param *path        uma string que armazena um caminho temporariamente
 */
void map_paths(TREE *tree, HASH *hash, char *path, int i);

/**
 * Cria e preenche uma árvore de Huffman
 *
 * @param *heap        a heap com os bytes para preencher a árvore de Huffman
 * @return             a árvore de Huffman criada
 */
TREE *create_huffman_tree(HEAP *heap);

/**
 * Escreve uma árvore binária em pré-ordem em um arquivo
 *
 * @param *tree        a árvore binária
 * @param *output      o arquivo de saída da árvore
 */
void write_pre_order_tree(TREE *tree, FILE *output);


#endif //HUFFMAN_HUFF_TREE_H
