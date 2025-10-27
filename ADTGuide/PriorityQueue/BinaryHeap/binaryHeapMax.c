#include<stdio.h>
#include"binaryHeapMax.h"

int main(){
    int arr[21] = {
        47, 23, 89, 12, 56, 
        78, 34, 91, 15, 67,
        29, 83, 41, 72, 18,
        95, 26, 64, 37, 58,
        100,
    };

    Heap list;
    initHeap(&list);
    display(list);

    printf("=====Pushing=====\n");
    for(int i=0; i<21; i++) push(&list, arr[i]);
    // display(list);
    displayList(list);
    
    printf("\n\n=====Popping=====\n");
    for(int i=0; i<21; i++) printf("Popped: [%2d]\n", pop(&list));
    // display(list);
    displayList(list);

    printf("\n\n=====Pre-Heapify=====\n");
    Heap list2;
    initHeap(&list2);
    for(int i=0; i<MAX; i++) list2.data[list2.lastndx++] = arr[i];
    // display(list2);
    displayList(list2);
    printf("\n\n=====Post-Heapify=====\n");
    heapify(&list2);
    // display(list2);
    displayList(list2);
}