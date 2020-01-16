#include "utils.h"

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
}

long long int *frequency_counter(FILE *file) {

    long long int *frequency = calloc(256, sizeof(long long int));
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