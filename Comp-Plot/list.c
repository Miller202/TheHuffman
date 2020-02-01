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
node* add_ending(node *head, int item)
{
    node *n_node = create_node_list(item);

    node *current = head;

    if (head == NULL)
        return n_node;

    while (current->next != NULL)
        current = current->next;

    current->next = n_node;

    return head;
}

int search_list(node *head, int item, int *comp)
{
    if (head == NULL)
    {
        (*comp)++;
        return -1;
    }
    while (head->next != NULL)
    {
        (*comp)++;
        if (head->item == item)
        {
            return 1;
        }
        head = head->next;
    }

    return -1;

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