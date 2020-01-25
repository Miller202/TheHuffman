#include "list.h"

node* create_linked_list()
{
	return NULL;
}

node* create_node_list(int item)
{
	node *head = (node*) malloc(sizeof(node));
	head->item = item;
	head->next = NULL;
	return head;
}

node* add_list(node *head, int item)
{
	node *new_node = create_node_list(item); // cria o novo nó;
	node *aux = head; // // aux aponta para head para nao perder o ponteiro da cabeça

	if(head == NULL) // quando a lista for nula, retorna o novo nó;
	{
		return new_node;
	}

	while(aux->next != NULL) // enquanto nao for o ultimo item, chama o proximo.
	{
		aux = aux->next;
	}

	aux->next = new_node;
	return head;
}

int search_list(node *head, int item, int *comp_list)
{
    *comp_list += 1;

	if (head != NULL)
	{
		if (head->item == item)
		{
			return 1; // item encontrado
		}
		return search_list(head->next, item, comp_list); // chama o proximo
	}
	return 0; // item nao encontrado
}