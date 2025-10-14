#include <stdio.h>
#include "arrayV3.h"

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
    display(L);
    L = insertPos(L, 0, 0);
    L = insertPos(L, 1, 1);
    L = insertPos(L, -1, 0);
    L = insertPos(L, 4, 2);
    L = insertPos(L, 4, 7);
    display(L);
    for(int i=0; i<7; i++) L = insertPos(L, i*2*2, 0);
    display(L);
    
    
    /**
     * Task 3: Delete at position
     */
    printf("\n\n\n\n=====Task #3=====\n\n");
    display(L);
    L = removePos(L, 10);
    L = removePos(L, 3);
    L = removePos(L, 0);
    L = removePos(L, 10);
    // for(int i=0; i<9; i++) L = removePos(L, 0);
    display(L);
    
    
    /**
     * Task 4: Locate data
     */
    printf("\n\n\n\n=====Task #4=====\n\n");
    display(L);
    printf("%d in position [%d].\n", 0, locate(L, 0));
    printf("%d in position [%d].\n", 20, locate(L, 20));
    printf("%d in position [%d].\n", 4, locate(L, 4));
    printf("%d in position [%d].\n", 43, locate(L, 43));
    

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
    L = insertSorted(L, -3);
    display(L);
}