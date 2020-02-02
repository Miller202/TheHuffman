#include <stdio.h>
#include <stdlib.h>
#include <utils.h>

#include "hash.h"

HASH *create_hash()
{
	HASH *new_hash = malloc(sizeof(HASH));
    check_malloc(new_hash);

	int i;
	for(i = 0; i < MAX_HASH_ADDRESS_SIZE; i++)
	{
		new_hash->table[i] = NULL;
	}

	return new_hash;
}

void put(HASH *new_hash, int key, char *representation)
{
	new_hash->table[key % MAX_HASH_ADDRESS_SIZE] = representation;
}

void* get(HASH *ht, int key)
{
    return ht->table[key % MAX_HASH_ADDRESS_SIZE];
}

void free_hash(HASH *ht)
{
    for (int i = 0; i < MAX_HASH_ADDRESS_SIZE; ++i)
    {
        free(ht->table[i]);
    }

    free(ht);
}