#include "../inc/heap.h"

int get_parent_index(HEAP *heap, int i){return i/2;}
int get_left_index(HEAP *heap, int i){return 2*i;}
int get_right_index(HEAP *heap, int i){return 2*i + 1;}


HEAP *create_heap() {
    HEAP *heap = (HEAP*)malloc(sizeof(HEAP));
    int i;

    heap->size = 0;
    for (i = 0; i <= 256; ++i) {
        heap->data[i] = NULL;
    }

    return heap;
}

void swap_data(TREE** item1, TREE** item2){

  TREE* aux;
  aux = *item1;
  *item1 = *item2;
  *item2 = aux;

}

void create_priority_queue(long long int frequency[], HEAP *heap){
  int i;
  for(i=0;i<256;i++){
    if (frequency[i] != 0){
      enqueue(heap,create_node((unsigned char)i, frequency[i], NULL, NULL));
    }
  }
}

void enqueue(HEAP *heap, TREE *item){

  if (heap->size >= 256){
    printf("Heap overflow.\n");
  }
  else{

    heap->data[++heap->size] = item; //Insere o nó na última posição na fila de prioridade;
    int key_index = heap->size; // Guarda o índice atual
    int parent_index =get_parent_index(heap,key_index); // Guarda o índice do pai;

    //Enquanto a frequência do índice atual for maior que a do seu pai, troque suas posições.
    while(parent_index >= 1 && (heap->data[key_index])->frequency < (heap->data[parent_index])->frequency){
        swap_data(&heap->data[parent_index],&heap->data[key_index]);
        key_index = parent_index; //Atualiza o índice;
        parent_index = get_parent_index(heap, key_index); //Guarda o índice do novo pai;
    }

  }

}


void min_heapify(HEAP *heap, int i)
{
  int smallest;
  int left_index = get_left_index(heap, i);
  int right_index = get_right_index(heap, i);

  if (left_index <= heap->size && (heap->data[left_index])->frequency < (heap->data[i])->frequency) {
    smallest = left_index;
  } else {
    smallest = i;
  }
  if (right_index <= heap->size && (heap->data[right_index])->frequency < (heap->data[smallest])->frequency) {
    smallest = right_index;
  }
  if ((heap->data[i])->frequency != (heap->data[smallest])->frequency) {
    swap_data(&heap->data[i], &heap->data[smallest]);
    min_heapify(heap, smallest);
  }
}

long long int *frequency_counter(FILE *file){

    long long int *frequency = calloc(256, sizeof(long long int));
	  unsigned char item;

    while(fscanf(file,"%c", &item) != EOF){
      frequency[(int)item]++;
    }

    return frequency;
}
