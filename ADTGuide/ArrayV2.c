#include <stdio.h>
#include "arrayV2.h"

int main(){
    /**
     * Task 1: Initialize the list
     */
    printf("\n\n\n\n=====Task #1=====\n\n");
    
    EPtr L;
    initialize(L);
    display(L);
    
    /**
     * Task 2: Insert at position
     */
    printf("\n\n\n\n=====Task #2=====\n\n");

    display(L);
    insertPos(L, 0, 0);
    insertPos(L, -1, 0);
    insertPos(L, 39, 2);
    insertPos(L, 1, 2);
    insertPos(L, 99, 5);
    insertPos(L, 0, 3);
    insertPos(L, 20, 5);
    insertPos(L, 12, 6);
    insertPos(L, 2, 7);
    insertPos(L, 9, 8);
    insertPos(L, -5, 9);
    display(L);
    
    
    /**
     * Task 3: Delete at position
     */
    printf("\n\n\n\n=====Task #3=====\n\n");
    
    display(L);
    deletePos(L, 9);
    deletePos(L, 1);
    deletePos(L, 0);
    display(L);
    
    /**
     * Task 4: Locate data
     */
    printf("\n\n\n\n=====Task #4=====\n\n");

    display(L);
    printf("%d is in [%d].\n", 0, locate(L, 0));
    printf("%d is in [%d].\n", 1, locate(L, 1));
    printf("%d is in [%d].\n", 3, locate(L, 3));
    printf("%d is in [%d].\n", 6, locate(L, 6));
    printf("%d is in [%d].\n", 7, locate(L, 7));
    printf("%d is in [%d].\n", 9, locate(L, 9));

    display(L);

    printf("[%d] contains %d.\n", 0, retrieve(L, 0));
    printf("[%d] contains %d.\n", 2, retrieve(L, 2));
    printf("[%d] contains %d.\n", 6, retrieve(L, 6));
    printf("[%d] contains %d.\n", 7, retrieve(L, 7));
    display(L);
    
    
    /**
     * Task 5: Sort list
     */
    printf("\n\n\n\n=====Task #5=====\n\n");

    display(L);
    sortDesc(L);
    display(L);
    sortAsc(L);
    display(L);
    
    
    /**
     * Task 6: Empty List
     */
    printf("\n\n\n\n=====Task #6=====\n\n");

    display(L);
    makeNULL(L);
    display(L);
}