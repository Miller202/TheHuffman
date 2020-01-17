#ifndef HUFFMAN_HASH_H
#define HUFFMAN_HASH_H

#define MAX_HASH_ADDRESS_SIZE 256

/* Hash Table - to store the bits*/
typedef struct HASH{
    void *table[MAX_HASH_ADDRESS_SIZE];
} HASH;


/**
*	Alocar memória para criar a tabela hash
*	@return: posições da tabela são iniciadas em NULL
**/
HASH *create_hash();

/** 
*	Armazenar os bits dos caracteres do arquivo a ser compactado
*	@param: recebe a tabela hash, a posição e a representação binária
*	@return: salva a nova representação no arquivo que vai ser compactado
**/
void put(HASH *new_hash, int key, char *representation);


/**
 *
 *	@param: a tabela hash onde irá realizar-se a busca e a key
 *	@return: os dados do item que tem a key igual à passada como argumento
 *
**/
void* get(HASH *ht, int key);

void print_hash(HASH *ht);

#endif //HUFFMAN_HASH_H
