#include<stdio.h>
#include<stdlib.h>
#include"CursorBased.h"

int main(){
    VHeap *vh = malloc(sizeof(VHeap));
    init(vh);
    int *list1 = malloc(sizeof(int));
    initList(list1);
    int *list2 = malloc(sizeof(int));
    initList(list2);
    // tempDisplay(vh, list1);
    // tempDisplay(vh, list2);
    // printf("\n");



    char data1[13] = "dgyfv";
    for(int i=0; i<5; i++){
        // insertFirst(vh, list1, data1[i]);
        insertLast(vh, list1, data1[i]);
    }
    for(int i=5; i<9; i++){
        // insertFirst(vh, list2, data1[i]);
        // insertLast(vh, list2, data1[i]);
    }
    // tempDisplay(vh, list1);
    // tempDisplay(vh, list2);
    // printf("\n");
 


    for(int i=0; i<1; i++){
        // deleteFirst(vh, list1);
        // deleteLast(vh, list2);
    }    
    // tempDisplay(vh, list1);
    // tempDisplay(vh, list2);
    display(vh, list1);
    printf("\n");
    // display(vh, list2);



    sortAsc(vh, list1);
    display(vh, list1);
    // sortDesc(vh, list1);
    // display(vh, list1);



    insertSorted(vh, list1, 'z');
    // display(vh, list1);
    insertSorted(vh, list1, 'i');
    // display(vh, list1);
    insertSorted(vh, list1, 'h'); //after g
    display(vh, list1);


    deleteValue(vh, list1, 'd');
    // display(vh, list1);
    deleteValue(vh, list1, 'h');
    // display(vh, list1);
    deleteValue(vh, list1, 'z');
    display(vh, list1);
}