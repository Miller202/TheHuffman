#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node
{
	int item;
	node *next;
};

node* create_linked_list(); // criar lista vazia
node* create_node_list(int item); // criar um novo nó
node* add_list(node *head, int item); // adicionar um item na lista
int search_list(node *head, int item, int *comp_list); // buscar um item na lista
void print_linked_list(node *head); // imprime a lista

