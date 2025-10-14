#include <stdio.h>
#include "arrayV4.h"

int main(){
    /**
     * Task 1: Initialize the list
     */
    printf("\n\n\n\n=====Task #1=====\n\n");
    List *L;
    initialize(L);
    display(L);


    /**
     * Task 2: Insert at position
     */
    printf("\n\n\n\n=====Task #2=====\n\n");
    display(L);
    insertPos(L, 0, 0);
    insertPos(L, -1, 0);
    insertPos(L, 10, 2);
    insertPos(L, 8, 11);
    insertPos(L, 4, 3);
    insertPos(L, 6, 3);
    // for(int i=0; i<20; i++) insertPos(L, i*2*2, 0);
    display(L);


    /**
     * Task 3: Delete at position
     */
    printf("\n\n\n\n=====Task #3=====\n\n");
    display(L);
    // removePos(L, 5);
    // removePos(L, 4);
    // removePos(L, 2);
    // removePos(L, 0);
    // removePos(L, -1);
    display(L);


    /**
     * Task 4: Locate data
     */
    printf("\n\n\n\n=====Task #4=====\n\n");
    display(L);
    printf("%d in position [%d].\n", 0, locate(L, 0));
    printf("%d in position [%d].\n", -1, locate(L, -1));
    printf("%d in position [%d].\n", 4, locate(L, 4));
    printf("%d in position [%d].\n", 2, locate(L, 2));
    printf("%d in position [%d].\n", 20, locate(L, 20));
    display(L);
    printf("[%d] contains %d.\n", 0, retrieve(L, 0));
    printf("[%d] contains %d.\n", 4, retrieve(L, 4));
    printf("[%d] contains %d.\n", 2, retrieve(L, 2));
    printf("[%d] contains %d.\n", 5, retrieve(L, 5));
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
     * Task 6: Insert sorted
     */
    printf("\n\n\n\n=====Task #6=====\n\n");
    display(L);
    insertSorted(L, 5);
    insertSorted(L, 15);
    insertSorted(L, 30);
    insertSorted(L, 25);
    insertSorted(L, 5);
    insertSorted(L, 2);
    insertSorted(L, -2);
    display(L);
}