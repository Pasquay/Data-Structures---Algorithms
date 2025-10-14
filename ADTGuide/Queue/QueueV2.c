#include <stdio.h>
#include <stdlib.h>
#include "queueV2.h"

int main(){
    /**
     * Task 1: Initialize the queue
     */
    printf("\n\n\n\n=====Task #1=====\n\n");
 
    Queue *Q = initialize();
 
    tempDisplay(Q);
    
    
    
    /**
     * Task 2: Enqueue data
     */
    printf("\n\n\n\n=====Task #2=====\n\n");
    tempDisplay(Q);

    int x = 0;
    Q->front=x+1, Q->rear=x;

    for(int i=0; i<9; i++) enqueue(Q, i);

    tempDisplay(Q);

    
    /**
     * Task 3: Dequeue data
     */
    printf("\n\n\n\n=====Task #3=====\n\n");
    tempDisplay(Q);

    for(int i=0; i<0; i++) printf("Dequeue: [%d]\n", dequeue(Q));

    display(Q);
    
    
    /**
     * Task 4: Front data
     */
    printf("\n\n\n\n=====Task #4=====\n\n");
    display(Q);
    printf("Front: [%d]\n", front(Q));
    
    
    /**
     * Task 5: Check if queue is empty
     */
    printf("\n\n\n\n=====Task #5=====\n\n");
    display(Q);
    printf("Empty: [%d]\n", isEmpty(Q));
    
    
    /**
     * Task 6: Check if queue is full
     */
    printf("\n\n\n\n=====Task #6=====\n\n");
    display(Q);
    printf("Full: [%d]\n", isFull(Q));
    
    
    /**
     * Task 7: Experiment!
     */
    printf("\n\n\n\n=====Task #7=====\n\n");
    // display(Q);
    isPalindrome(Q);
}