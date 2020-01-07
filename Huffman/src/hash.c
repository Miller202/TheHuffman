#include "../inc/hash.h"

hash *create_hash()
{
	hash *new_hash = malloc(sizeof(hash));

	int i;
	for(i=0; i < 256; i++)
	{
		new_hash->table[i] = NULL;
	}

	return new_hash;
}

void put(hash *new_hash, int i, char *representation)
{
	new_hash->table[i] = representation;
}
