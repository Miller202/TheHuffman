#include <stdio.h>
#include <stdlib.h>
#include "abb.h"
#include "list.h"

int main()
{
    node* list = create_linked_list();
    bs_tree* bt = create_empty_bst();

    int range, q_sorted,num, i;

    range = 60000;
    q_sorted = 10000;

    FILE *out = fopen("out.txt", "w+b");

    for (i = 0; i < q_sorted; i++)
	{
        num = rand() % range;
        list = add_ending(list, num);
        bt = add_bst(bt, num);

    }

    int find_bst, find_list, n_comp_list = 0, n_comp_bst = 0;
    for (i = 0; i < q_sorted; i++)
    {
        find_bst = 0;
        find_list = 0;
        num = rand() % range;

        n_comp_list = search_list(list, num, &find_list);
        n_comp_bst = search_bst(bt, num, &find_bst);

        if (n_comp_list != -1 && n_comp_bst != -1)
            fprintf(out, "%d %d %d\n", num, find_list, find_bst);

    }

    fclose(out);
    
    return 0;
}