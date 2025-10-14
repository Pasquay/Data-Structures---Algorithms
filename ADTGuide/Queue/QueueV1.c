#include <stdio.h>
#include <stdlib.h>
#include "queueV1.h"

int main(){
    /**
     * Task 1: Initialize the queue
     */
    printf("\n\n\n\n=====Task #1=====\n\n");
    Queue *Q = initialize();
    display(Q);
    
    
    /**
     * Task 2: Enqueue data
     */
    printf("\n\n\n\n=====Task #2=====\n\n");
    display(Q);
    Q->front = 5;
    Q->rear = 5;
    for(int i=0; i<10; i++) enqueue(Q, i);
    display(Q);
    
    
    /**
     * Task 3: Dequeue data
     */
    printf("\n\n\n\n=====Task #3=====\n\n");
    display(Q);
    for(int i=0; i<10; i++) dequeue(Q);
    display(Q);

    
    /**
     * Task 4: Front data
     */
    printf("\n\n\n\n=====Task #4=====\n\n");
    display(Q);
    printf("Front data: [%d]\n", front(Q));
    
    
    /**
     * Task 5: Check if queue is empty
     */
    printf("\n\n\n\n=====Task #5=====\n\n");
    display(Q);
    printf("Is empty: [%d]", isEmpty(Q));
    
    
    /**
     * Task 6: Check if queue is full
     */
    printf("\n\n\n\n=====Task #6=====\n\n");
    display(Q);
    printf("Is full: [%d]", isFull(Q));
}