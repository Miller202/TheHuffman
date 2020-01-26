#include <stdio.h>
#include <stdlib.h>

#include "hash.h"
#include "utils.h"

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

void print_hash(HASH *ht)
{
	for (int i = 0; i < MAX_HASH_ADDRESS_SIZE; ++i) {
		printf("%d: %s %c\n", i, get(ht, i), i);
	}
}