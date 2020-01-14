#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/hash.h"

HASH *create_hash()
{
	HASH *new_hash = malloc(sizeof(HASH));

	int i;
	for(i=0; i < 256; i++)
	{
		new_hash->table[i] = NULL;
	}

	return new_hash;
}

void put(HASH *new_hash, int i, char *representation)
{
	new_hash->table[i] = representation;
}
