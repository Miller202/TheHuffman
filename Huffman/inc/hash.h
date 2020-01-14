#ifndef HUFFMAN_HASH_H
#define HUFFMAN_HASH_H

/* Hash Table - to store the bits*/
typedef struct HASH{
    void *table[256];
} HASH;


/**
*	Alocar memória para criar a tabela hash
*	@return: posições da tabela são iniciadas em NULL
**/
HASH *create_hash();

/** 
*	Armazenar os bits dos caracteres do arquivo a ser compactado
	@param: recebe a tabela hash, a posição e a representação binária
	@return: salva a nova representação no arquivo que vai ser compactado
**/
void put(HASH *new_hash, int i, char *representation);

#endif //HUFFMAN_HASH_H
