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
	node *new_node = create_node_list(item); // cria o novo nó;node *new_node = (node*) malloc(sizeof(node));

    new_node->next = head;

    return new_node;
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

void print_linked_list(node *head) // imprime a lista
{
    if (head == NULL) // imprimir enquanto a lista nao acabar
    {
        return;
    }
    printf("%d\n", head->item);
    print_linked_list(head->next); // recursao para chamar o proximo head
}