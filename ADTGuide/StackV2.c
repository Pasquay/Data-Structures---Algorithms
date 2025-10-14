#include <stdio.h>
#include "stackV2.h"

int main(){
    /**
     * Task 1: Initialize the stack
     */
    printf("\n\n\n\n=====Task #1=====\n\n");

    Stack *S = initialize();
    display(S);


    /**
     * Task 2: Push data
     */
    printf("\n\n\n\n=====Task #2=====\n\n");

    int data[13] = {1,2,3,4,5,-1,7,91,-51,2,0,0,0};
    display(S);
    for(int i=0; i<12; i++) push(S, data[i]);
    display(S);


    /**
     * Task 3: Pop data
     */
    printf("\n\n\n\n=====Task #3=====\n\n");

    display(S);
    for(int i=0; i<10; i++) {
        // printf("[%d] Popped\n", pop(S)); // For testing the retval
        pop(S); // For testing functionality
    }
    display(S);


    /**
     * Task 4: Peek data
     */
    printf("\n\n\n\n=====Task #4=====\n\n");
    display(S);
    for(int i=0; i<1; i++){
        printf("%d Peeked.\n", peek(S)); // For retval
        // peek(S); // For functionality
        // pop(S);
    }
    display(S);
}