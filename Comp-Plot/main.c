#include <stdio.h>
#include <stdlib.h>
#include "abb.h"
#include "list.h"

int main()
{
	int num = 0, comp_list = 0, comp_bt = 0;

    node* list = create_linked_list();
    bs_tree* bt = create_empty_bst();

	FILE* file = fopen("numbers.txt", "r");

	while(fscanf(file, "%d", &num) != EOF)
	{
		list = add_list(list, num);
		bt = add_bst(bt, num);

        fscanf(file, "%d", &num);
    }
	fclose(file);

	int value = 0;
	while(value != -1)
	{
        printf("Digite um número entre (1 - 10000) para ser buscado: \n");
		scanf("%d", &value);

		int n_list = search_list(list, value, &comp_list);
		int n_bt = search_bst(bt, value, &comp_bt);

		if(n_list != 0 && n_bt != 0)
		{
			printf("%d foi encontrado\n", value);
		}
		else{
			printf("%d nao foi encontrado\n", value);
		}

		printf("Quantidade de comparacoes na Lista: %d\n", comp_list);
		printf("Quantidade de comparacoes na ABB: %d\n", comp_bt);

		FILE *out = fopen("out.txt", "w+b");
        fprintf(out, "%d %d %d\n", value, comp_list, comp_bt);
        fclose(out);

		comp_list = 0;
		comp_bt = 0;
	}
}