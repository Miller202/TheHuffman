#include "../inc/heap.h"
#include "../inc/huff_tree.h"

HEAP *create_heap() 
{
    HEAP *heap = (HEAP*)malloc(sizeof(HEAP));
    int i;

    heap->size = 0;
    for (i = 0; i <= 256; ++i){
        heap->data[i] = NULL;
    }

    return heap;
}

int get_parent_index(int i){return i/2;}
int get_left_index(int i){return 2*i;}
int get_right_index(int i){return 2*i + 1;}

void swap_data(TREE** item_1, TREE** item_2)
{

  TREE* aux;
  aux = *item_1;
  *item_1 = *item_2;
  *item_2 = aux;

}

void enqueue(HEAP *heap, TREE *item)
{

  if (heap->size >= 256){
    printf("Heap overflow.\n");
  }
  else{
    heap->data[++heap->size] = item; //Insere o nó na última posição na fila de prioridade;
    int key_index = heap->size; // Guarda o índice atual
    int parent_index = get_parent_index(key_index); // Guarda o índice do pai;

    //Enquanto a frequência do índice atual for maior que a do seu pai, troque suas posições.
    while(parent_index >= 1 && (heap->data[key_index])->frequency < (heap->data[parent_index])->frequency){
        swap_data(&heap->data[parent_index],&heap->data[key_index]); // troca as posições
        key_index = parent_index; //Atualiza o índice;
        parent_index = get_parent_index(key_index); //Guarda o índice do novo pai;
    }
  }
}

void create_priority_queue(long long int frequency[], HEAP *heap)
{
  int i;
  for(i=0; i < 256; i++){
    if (frequency[i] != 0){
      enqueue(heap, create_node((unsigned char)i, frequency[i], NULL, NULL));
    }
  }
}

void min_heapify(HEAP *heap, int i)
{
  int smallest;
  int left_index = get_left_index(i);
  int right_index = get_right_index(i);

  if (left_index <= heap->size && (heap->data[left_index])->frequency < (heap->data[i])->frequency){
    smallest = left_index;
  } else {
    smallest = i;
  }
  if (right_index <= heap->size && (heap->data[right_index])->frequency < (heap->data[smallest])->frequency){
    smallest = right_index;
  }
  if ((heap->data[i])->frequency != (heap->data[smallest])->frequency){
    swap_data(&heap->data[i], &heap->data[smallest]);
    min_heapify(heap, smallest);
  }
}

long long int *frequency_counter(FILE *file)
{

    long long int *frequency = calloc(256, sizeof(long long int));
	  unsigned char item;

    while(fscanf(file,"%c", &item) != EOF){
      frequency[(int)item]++;
    }

    return frequency;
}
