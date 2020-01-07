#include "../inc/heap.h"

heap *create_heap()
{
	heap *new_heap = malloc(sizeof(heap));

	new_heap->size = 0;

	int i;
	for(i=1; i <= 257; i++)
	{
		new_heap->items[i] = NULL;
	}

	return new_hash;
}

int get_left_index(int i)
{
	return i * 2;
}

int get_right_index(int i)
{
	return (i * 2) + 1;
}

int get_parent_index(int i)
{
	return i/2;
}

void swap(heap *new_heap, int index_1, int index_2)
{
	int *aux;
	aux = new_heap->items[index_1];
	new_heap->items[index_1] = new_heap->items[index_2];
	new_heap->items[index_2] = aux;
}
