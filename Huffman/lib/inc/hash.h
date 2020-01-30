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
 *	Armazena um elemento char * no índice key da tabela hash
 *
 *	@param: *new_hash a tabela hash
 *	@param: key a key da tabela hash
 *	@param: representation
 *	@return: salva a nova representação no arquivo que vai ser compactado
**/
void put(HASH *new_hash, int key, char *representation);

/**
 *  Obtém o item da hash table de acordo com a key
 *
 *  @param: *ht o ponteiro para hash table
 *  @param: key a key da hash table
 *  @return: os dados do item da hash table que tem a key igual à passada como argumento
**/
void* get(HASH *ht, int key);

/**
 *  Desaloca a hash table da memória
 *
 *  @param: Recebe a hash table a ser destruída
 **/
void free_hash(HASH *ht);

#endif //HUFFMAN_HASH_H
