#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"
#include "heap.h"
#include "huff_tree.h"

#ifndef HUFFMAN_HASH_H
#define HUFFMAN_HASH_H

/*create_hash -> função para alocar memória para criar a tabela hash*/
hash *create_hash();

/* put -> função para armazenar os bits dos caracteres do arquivo a ser compactado*/
void put(hash *new_hash, int i, char *representation);

#endif //HUFFMAN_HASH_H
