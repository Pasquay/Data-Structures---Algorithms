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
    // display(list);
    displayList(list);

    printf("\n\n=====Pushing=====\n");
    for(int i=0; i<21; i++) insertSorted(&list, arr[i]); // Normal
    // for(int i=0; i<21; i++) insert(&list, arr[i]); // To test sorting
    display(list);
    displayList(list);
    // displayArray(list);
    
    printf("\n\n=====Popping=====\n");
    for(int i=0; i<21; i++) printf("Popped: [%2d]\n", deleteMax(&list));
    // display(list);
    // displayList(list);
    // displayArray(list);
    
    // printf("\n\n=====Heapify=====\n");
    // // uncomment insert and comment insertSorted
    // heapify(&list);
    // // display(list);
    // displayList(list);
    // // displayArray(list);
    
    // printf("\n\n=====Sorting=====\n");
    // heapSort(&list);
    // // display(list);
    // displayList(list);
    // // displayArray(list);
}