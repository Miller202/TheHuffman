#ifndef HUFFMAN_HASH_H
#define HUFFMAN_HASH_H

/* Hash Table - to store the bits*/
typedef struct HASH{
    void *table[256];
} HASH;


/*create_hash -> função para alocar memória para criar a tabela hash*/
HASH *create_hash();

/* put -> função para armazenar os bits dos caracteres do arquivo a ser compactado*/
void put(HASH *new_hash, int i, char *representation);

#endif //HUFFMAN_HASH_H
