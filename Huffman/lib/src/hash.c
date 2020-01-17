#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

HASH *create_hash()
{
	HASH *new_hash = malloc(sizeof(HASH));

	if (!new_hash)
	{
	    printf("Memory allocation error!\n");
        return NULL;
	}

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

void print_hash(HASH *ht)
{
	for (int i = 0; i < MAX_HASH_ADDRESS_SIZE; ++i) {
		printf("%d: %s\n", i, get(ht, i));
	}
}