#include <stdio.h>
#include <stdlib.h>
#include "abb.h"
#include "list.h"

int main()
{
    node* list = create_linked_list();
    bs_tree* bt = create_empty_bst();

    int final, num, i;

    printf("Digite o numero final do intervalo (0 - numero)\n");
    scanf("%d", &final);

    FILE *out = fopen("../ot.txt", "w+b");

    int sorted_numbers[100];
    for (i = 0; i < 100; i++)
	{
        num = rand() % final;
        sorted_numbers[i] = num;
        list = add_ending(list, num);
        bt = add_bst(bt, num);

    }


    int comp_list = 0, comp_bst = 0;
    for (i = 0; i < 100; i++)
    {
            num = rand() % 100;
            comp_list = search_list(list, sorted_numbers[num]);
            comp_bst = search_bst(bt, sorted_numbers[num]);

            if (comp_list != -1)
                fprintf(out, "%d %d %d\n", sorted_numbers[num], comp_list, comp_bst);

    }

    fclose(out);

    printf("blz andre\n");
    return 0;
}