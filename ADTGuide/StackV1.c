#include <stdio.h>
#include "stackV1.h"

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
    for(int i=0; i<13; i++) push(S, data[i]);
    display(S);


    /**
     * Task 3: Pop data
     */
    printf("\n\n\n\n=====Task #3=====\n\n");

    display(S);
    for(int i=0; i<2; i++) {
        // printf("[%d] Popped\n", pop(S)); // For testing the retval
        pop(S); // For testing functionality
    }
    display(S);


    /**
     * Task 4: Peek data
     */
    printf("\n\n\n\n=====Task #4=====\n\n");
    display(S);
    for(int i=0; i<2; i++){
        // printf("%d Peeked.\n", peek(S)); // For retval
        peek(S); // For functionality
        pop(S);
    }
    display(S);


    /**
     * Task #5: Check palindrome
     */
    printf("\n\n\n\n=====Task #5=====\n\n");

    Stack *D = initialize();
    int data2[6] = {1,2,3,3,2,1};
    for(int i=0; i<6; i++) push(D, data2[i]);

    display(S);
    printf("List %s a palindrome.\n", (isPalindrome(S)==1) ? "is" : "is not");
    display(S);
    display(D);
    printf("List %s a palindrome.\n", (isPalindrome(D)==1) ? "is" : "is not");
    display(D);

    
    /**
     * Task #6: Find max element
     */
    printf("\n\n\n\n=====Task #6=====\n\n");
    display(S);
    printf("Max: [%d]\n", getMax(S));
    display(S);
    printf("\n");
    display(D);
    printf("Max: [%d]\n", getMax(D));
    display(D);

}