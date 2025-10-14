#include <stdio.h>
#include <stdlib.h>
#include "arrayV1.h"

int main(){
    /**
     * Task 1: Initialize the list
     */
    printf("\n\n\n\n=====Task #1=====\n\n");

    List L = initialize(L);
    display(L);


    /**
     * Task 2: Insert at position
     */
    printf("\n\n\n\n=====Task #2=====\n\n");

    L = insertPos(L, 99, 0);
    display(L);
    L = insertPos(L, 1, 0); //head
    L = insertPos(L, 2, 2); //tail
    L = insertPos(L, 5, 6); //out of bounds
    L = insertPos(L, 7, 1); //middle
    for(int i=0; i<7; i++){
        L = insertPos(L, i*3, 0);
    }
    display(L);



    /**
     * Task 3: Delete at position
     */
    printf("\n\n\n\n=====Task #3=====\n\n");

    display(L);
    L = deletePos(L, 11);
    L = deletePos(L, 0);
    L = deletePos(L, 8);
    L = deletePos(L, 8);
    display(L);


    /**
     * Task 4: Locate data
     */
    printf("\n\n\n\n=====Task #4=====\n\n");

    display(L);
    printf("%d is in [%d].\n", 1, locate(L, 1));
    printf("%d is in [%d].\n", 12, locate(L, 12));
    printf("%d is in [%d].\n", 99, locate(L, 99));
    printf("%d is in [%d].\n", 3, locate(L, 3));


    /**
     * Task 5: Sort list
     */
    printf("\n\n\n\n=====Task #5=====\n\n");

    display(L);
    L = sortDesc(L);
    display(L);
    L = sortAsc(L);
    display(L);


    /**
     * Task 6: Insert sorted
     */
    printf("\n\n\n\n=====Task #6=====\n\n");

    display(L);
    L = insertSorted(L, 1);
    L = insertSorted(L, 50);
    display(L);
}