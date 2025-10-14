#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "linklistV1.h"

int main(){
    /**
     * Task 1: Initialize the list then display
     */

    printf("\n\n\n\n=====Task #1=====\n\n");

    List *L = initialize();
    display(L);

    /**
     * Task 2: Insert data
     */

    printf("\n\n\n\n=====Task #2=====\n\n");

    insertLast(L, 300);
    insertFirst(L, 1);
    insertFirst(L, 2);
    insertLast(L, 100);
    insertLast(L, 100);
    insertPos(L, 10, 4);
    display(L);

    /**
     * Task 3: Delete data
     */

    printf("\n\n\n\n=====Task #3=====\n\n");

    display(L);
    // deleteStart(L);
    // deleteLast(L);
    // deletePos(L, 0);
    // deletePos(L, 5);
    // deletePos(L, 5);
    deletePos(L, 1);
    display(L);

    /**
     * Task 4: Retrieve and Locate data
     */

    printf("\n\n\n\n=====Task #4=====\n\n");

    display(L);
    int data = retrieve(L, 4);
    data = retrieve(L, 9);
    int ndx = locate(L, 1000);
    ndx = locate(L, 2);

    /**
     * Task 5: Empty List
     */

    printf("\n\n\n\n=====Task #5=====\n\n");
    
    display(L);
    empty(L);
    display(L);
}