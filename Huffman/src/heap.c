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

void enqueue(heap *new_heap, tree *node)
{
	if(new_heap->size == 257)
	{
		printf("Overflow\n");
		return;
	}
	else{
		heap->size += 1; // atualiza o tamanho para inserir o nó
		new_heap->items[heap->size] = node; //Insere o nó na última posição da fila de prioridade;
		int parent_index = get_parent_index(heap->size); // Guarda o índice do pai;
		int new_size = heap->size; // Guarda o tamanho da heap;

		tree *parent = ((tree *)new_heap->items[parent_index]); // Guarda o item da posição pai em uma árvore;
		tree *item = ((tree *)new_heap->items[new_size]); // Guarda o item da última posição da heap em uma árvore;

		while((parent->frequency > item->frequency) && (parent_index > 0)) // Enquanto a frequencia do pai é maior que
		{																   // a frequencia do item(nó) inserido na fila;
			swap(heap, parent_index, new_size); // Troca a posição do nó pai com o nó da última posição;                       
			new_size = parent_index; // Atualiza o tamanho da heap
			parent_index = get_parent_index(new_size); // Atualiza a índice do pai
		}
	}
}
