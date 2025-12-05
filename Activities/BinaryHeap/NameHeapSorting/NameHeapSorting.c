#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parent(int i);
int leftChild(int i);
int rightChild(int i);
void heapify(char *arr[], int n, int i);
void heapSort(char *arr[], int n);

void printArray(char *arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("\n\t%02d | %s ", i, arr[i]);
    }
    printf("\n");
}

int main() {
    char *arr[] = {"Charlie", "Alice", "Bob", "Eve", "David", "Frank"};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array of names: ");
    printArray(arr, n);

    // Perform Heap Sort (sorts alphabetically A-Z)
    heapSort(arr, n);

    printf("Sorted array of names:   ");
    printArray(arr, n);

    return 0;
}

// write your functions here
int parent(int i)    { return (i-1)/2; }
int leftChild(int i) { return (i*2)+1; }
int rightChild(int i){ return (i*2)+2; }

void heapify(char *arr[], int n, int i){
    int largest, l, r;
    do {
        largest=i, l=leftChild(i), r=rightChild(i);
        if(l<n && strcmp(arr[largest], arr[l])<0) largest = l;
        if(r<n && strcmp(arr[largest], arr[r])<0) largest = r;
        if(largest!=i){
            char *temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            i = largest;
        }
    } while(largest!=i);
}

void heapSort(char *arr[], int n){
    for(int i=parent(n-1); i>=0; i--) heapify(arr,n,i);
    for(int i=n-1; i>0; i--){
        char *temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr,i,0);
    }
}