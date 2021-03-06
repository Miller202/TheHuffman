#ifndef HUFFMAN_HASH_H
#define HUFFMAN_HASH_H

#define MAX_HASH_ADDRESS_SIZE 256

/** Hash Table - Mapeamento de bits **/
typedef struct HASH{
    void *table[MAX_HASH_ADDRESS_SIZE];
} HASH;


/**
 * Aloca memória para criar a tabela hash
 *
 * @return     a hash table com as posições da tabela iniciadas como NULL
 */
HASH *create_hash();

/** 
 * Armazena dados no índice key da tabela hash
 *
 * @param *new_hash            a tabela hash
 * @param key                  a key da tabela hash
 * @param *representation      os dados
 * @return                     Salva a nova representação do bit representado por key na tabela hash
 */
void put(HASH *new_hash, int key, char *representation);

/**
 * Obtém o item da hash table de acordo com a key
 *
 * @param *ht      o ponteiro para hash table
 * @param key      a key da hash table
 * @return         os dados do item da hash table que tem a key igual à passada como argumento
 */
void* get(HASH *ht, int key);

/**
 * Desaloca a hash table da memória
 *
 * @param *ht      a hash table a ser destruída
 */
void free_hash(HASH *ht);

#endif //HUFFMAN_HASH_H
