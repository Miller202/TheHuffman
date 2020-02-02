#include "utils.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "huff_tree.h"

void create_priority_queue(lli frequency[], HEAP *heap) {
    int i;
    for (i = 0; i < 256; i++) {
        if (frequency[i] != 0) {
            enqueue(heap, frequency[i], create_node((u_char) i, frequency[i], NULL, NULL));
        }
    }
}

lli *frequency_counter(FILE *file) {

    lli *frequency = calloc(256, sizeof(lli));
    check_malloc(frequency);

    u_char item;

    while (fscanf(file, "%c", &item) != EOF) {
        frequency[(int) item]++;
    }

    return frequency;
}

HEAP *mount_heap(FILE *file)
{
    HEAP *heap = create_heap();
    lli *frequency = frequency_counter(file);
    create_priority_queue(frequency, heap);

    return heap;
}

void  check_malloc(void *mem)
{
    if (!mem)
    {
        printf("Erro de alocacao de memoria!\n");
        exit(1);
    }
}

char* concat(char *s1, char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    check_malloc(result);

    strcpy(result, s1);
    strcat(result, s2);

    return result;
}

void print_tree_node_heap(void *tree)
{
    print_tree_node((TREE *) tree);
}