//astar.c
#include "astar.h"
#include <stdlib.h>

PriorityQueue* initializePriorityQueue(int maxSize){
    PriorityQueue* heap = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    if(heap == NULL){
        exit(EXIT_FAILURE);
    }

    heap->maxSize=maxSize; // asigning value to maxsize variable of heap.
    heap->size=0;           // Initial size
    // Asigning value to nodes, (memory allocated to all the nodes)
    heap->nodes=(PriorityQueueNode*)malloc(maxSize * sizeof(PriorityQueueNode));
    if(heap->nodes==NULL){
        free(heap);
        exit(EXIT_FAILURE);
    }
    return heap;
}
