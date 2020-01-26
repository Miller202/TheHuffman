#include "utils.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "huff_tree.h"

void create_priority_queue(long long int frequency[], HEAP *heap) {
    int i;
    for (i = 0; i < 256; i++) {
        if (frequency[i] != 0) {
            enqueue(heap, frequency[i], create_node((unsigned char) i, frequency[i], NULL, NULL));
        }
    }
    print_heap(heap, print_tree_node_heap);
    printf("\n");
}

long long int *frequency_counter(FILE *file) {

    long long int *frequency = calloc(256, sizeof(long long int));
    check_malloc(frequency);

    unsigned char item;

    while (fscanf(file, "%c", &item) != EOF) {
        frequency[(int) item]++;
    }

    return frequency;
}

HEAP *mount_heap(FILE *file)
{
    HEAP *heap = create_heap();
    long long int *frequency = frequency_counter(file);
    create_priority_queue(frequency, heap);

    return heap;
}

void check_malloc(void *mem)
{
    if (mem == NULL)
    {
        printf("Erro de alocacao de memoria!");
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