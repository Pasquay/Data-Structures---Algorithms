#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#define MAX 20

typedef struct {
    int data[MAX];
    int lastndx;
} Heap;

void initHeap(Heap *h){ h->lastndx = 0; }
void clear(Heap *h)   { h->lastndx = 0; }
int parent(int n)     { return (n-1)/2; }
int leftChild(int n)  { return (n*2)+1; }
int rightChild(int n) { return (n*2)+2; }
int peek(Heap h)      { return h.lastndx ? h.data[h.lastndx] : -1; }
int count(Heap h)     { return h.lastndx; }
bool isEmpty(Heap h)  { return h.lastndx == 0; }
bool isFull(Heap h)   { return h.lastndx == MAX; }

int find(Heap h, int x){
    int i;
    for(i=0; i<h.lastndx && h.data[i]!=x; i++){}
    return (i==h.lastndx) ? -1 : i;
}

void displayList(Heap h){
    printf("---------LIST---------\n");
    printf(" [DX:DA] [LC:RC]\n");
    for(int i=0; i<h.lastndx; i++) 
        printf(" [%2d:%2d] [%2d:%2d]\n", 
            i, h.data[i], 
            (leftChild(i))>=h.lastndx ? -1 : h.data[leftChild(i)], 
            (rightChild(i))>=h.lastndx ? -1 : h.data[rightChild(i)]
        );
    printf(" Size: %2d/%2d\n", h.lastndx, MAX);
    printf("----------------------\n");
}
void display(Heap h){
    printf("=============BINARY HEAP=============\n");
    printf("Size: %2d/%2d\n", h.lastndx, MAX);
    int level = 0;
    int levelSize = 1;
    for(int i=0; i<h.lastndx; level++, i+=levelSize, levelSize*=2){
        printf("Level %d: |", level);
        for(int j=i; j<h.lastndx && j<i+levelSize; j++) printf("%2d|", h.data[j]);
        printf("\n");
    }
    printf("=====================================\n");
}
void displayArray(Heap h){
    for(int i=0; i<h.lastndx; i++){
        if(i==MAX/2) printf("\n");
        printf("%d, ", h.data[i]);
    } 
}

void heapifyUp(Heap *h, int ndx){
    for(int i=ndx; i>0 && h->data[i]>h->data[parent(i)]; i=parent(i)){
        int temp = h->data[i];
        h->data[i] = h->data[parent(i)];
        h->data[parent(i)] = temp;
    }
}
void insert(Heap *h, int elem){
    if(!isFull(*h)){
        h->data[h->lastndx++] = elem;
    }
}
void insertSorted(Heap *h, int elem){
    if(!isFull(*h)){
        h->data[h->lastndx] = elem;
        heapifyUp(h, h->lastndx++);
    }
}

void heapifyDown(Heap *h, int ndx){
    int largest, l, r, temp;
    do {
        largest=ndx, l=leftChild(ndx), r=rightChild(ndx), temp=-1;
        if(l<h->lastndx && h->data[largest]<h->data[l]) largest = l;
        if(r<h->lastndx && h->data[largest]<h->data[r]) largest = r;
        if(largest!=ndx){
            temp = h->data[ndx];
            h->data[ndx] = h->data[largest];
            h->data[largest] = temp;
            ndx = largest;
        }
    } while(temp!=-1);
}
int deleteMax(Heap *h){
    int retval = -1;
    if(!isEmpty(*h)){
        retval = h->data[0];
        h->data[0] = h->data[--h->lastndx];
        heapifyDown(h, 0);
    }
    // display(*h);
    return retval;
}
void deleteElem(Heap *h, int x){
    int ndx = find(*h, x);
    if(ndx==-1) printf("Error: [%2d] Not found\n", x);
    else {
        printf("Deleting %d...\n", x);
        h->data[ndx] = h->data[--h->lastndx];
        heapifyDown(h, ndx);
    }
}

void heapify(Heap *h){
    // Sort Heap -> All parent > children
    for(int i=parent(h->lastndx); i>=0; i--) heapifyDown(h, i);
}

void heapSort(Heap *h){
    // Sort heap into descending array -> Largest to smallest
    for(int i=h->lastndx-1; i>=0; i--) heapifyDown(h, i);
    int originalIndex = h->lastndx;
    for(h->lastndx; h->lastndx>0; heapifyDown(h, 0)){
        int temp = h->data[0];
        h->data[0] = h->data[--h->lastndx];
        h->data[h->lastndx] = temp;
    }
    h->lastndx = originalIndex;
}