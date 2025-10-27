#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#define MAX 20

typedef struct {
    int data[MAX];
    int lastndx;
} Heap;

void initHeap(Heap *h)         { h->lastndx = 0; }
void clear(Heap *h)            { h->lastndx = 0; }
int parent(Heap h, int ndx)    { return (ndx>0) ? (ndx-1)/2 : -1; }
int leftChild(Heap h, int ndx) { return ((ndx*2)+1<h.lastndx) ? (ndx*2)+1: -1; }
int rightChild(Heap h, int ndx){ return ((ndx*2)+2<h.lastndx) ? (ndx*2)+2: -1; }
int peek(Heap h)               { return (!h.lastndx) ? -1 : h.data[0]; }
int count(Heap h)              { return h.lastndx; }
bool isEmpty(Heap h)           { return h.lastndx == 0; }
bool isFull(Heap h)            { return h.lastndx == MAX; }

void displayList(Heap h){
    printf("---------LIST---------\n");
    printf(" [DX:DA] [LC:RC]\n");
    for(int i=0; i<h.lastndx; i++) 
        printf(" [%2d:%2d] [%2d:%2d]\n", 
            i, h.data[i], 
            (leftChild(h,i))==-1 ? -1 : h.data[leftChild(h,i)], 
            (rightChild(h,i))==-1 ? -1 : h.data[rightChild(h,i)]
        );
    printf(" Size: %2d/%2d\n", h.lastndx, MAX);
    printf("----------------------\n");
}

void display(Heap h){
    printf("===============BINARY HEAP===============\n");
    printf("Size: %2d/%2d\n", h.lastndx, MAX);
    int level = 0;
    int levelSize = 1;
    for(int i=0; i<h.lastndx; level++, i+=levelSize, levelSize*=2){
        printf("Level %d: ", level);
        for(int j=i; j<h.lastndx && j<i+levelSize; j++) printf("[%2d:%2d] ", j, h.data[j]);
        printf("\n");
    }
    printf("=========================================\n");
}

void push(Heap *h, int x){
    if(h->lastndx==MAX) printf("Error: List Full\n");
    else {
        h->data[h->lastndx++] = x;
        for(int i=h->lastndx-1; h->data[i]>h->data[parent(*h,i)] && i>0; i=parent(*h, i)){
            int temp = h->data[i];
            h->data[i] = h->data[parent(*h,i)];
            h->data[parent(*h,i)] = temp;
        }
        printf("Success: Push [%d]\n", x);
    }
}

int pop(Heap *h){
    int retval = -1, child;
    if(h->lastndx!=0){
        retval = h->data[0];
        h->data[0] = h->data[--h->lastndx];
        for(int i=0; h->data[i]<h->data[leftChild(*h,i)] || h->data[i]<h->data[rightChild(*h,i)]; i=child){
            child = (h->data[leftChild(*h,i)]>h->data[rightChild(*h,i)]) ? leftChild(*h,i) : rightChild(*h,i);
            int temp = h->data[i];
            h->data[i] = h->data[child];
            h->data[child] = temp;
        }
    }
    return retval;
}

void siftDown(Heap *h, int i){
    int largest = -1;
    while(largest != i){  // ← Use while(true) for cleaner logic
        largest = i;
        int leftIdx = leftChild(*h, i);
        int rightIdx = rightChild(*h, i);
        
        // Find largest among parent and existing children
        if(leftIdx != -1 && h->data[leftIdx] > h->data[largest])
            largest = leftIdx;
        if(rightIdx != -1 && h->data[rightIdx] > h->data[largest])
            largest = rightIdx;
            
        // If parent is already largest, we're done
        if(largest == i) break;
        
        // Swap with largest child
        int temp = h->data[i];
        h->data[i] = h->data[largest];
        h->data[largest] = temp;
        i = largest;  // Continue from swapped position
    }
}


// void siftDown(Heap *h, int i){
//     for(int largest=i+1; largest!=i; i=largest){
//         largest = i;
//         if(leftChild(*h,i)!=-1 && h->data[largest]<h->data[leftChild(*h,i)]) 
//             largest = leftChild(*h,i);
//         if(rightChild(*h,i)!=-1 && h->data[largest]<h->data[rightChild(*h,i)]) 
//             largest = rightChild(*h,i);
//         if(largest!=i){
//             int temp = h->data[i];
//             h->data[i] = h->data[largest];
//             h->data[largest] = temp;
//         }
//     }
// }

void heapify(Heap *h){
    for(int i=(h->lastndx-1)/2; i>=0; i--) siftDown(h, i);
}