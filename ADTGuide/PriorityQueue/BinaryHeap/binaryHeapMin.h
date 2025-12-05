#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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
int peek(Heap h)      { return h.data[0]; }
int count(Heap h)     { return h.lastndx; }
bool isEmpty(Heap h)  { return h.lastndx == 0; }
bool isFull(Heap h)   { return h.lastndx == MAX; }

void displayList(Heap h){
   printf("------------BINARY HEAP------------\n");
   printf("Size: %2d/%2d\n", h.lastndx, MAX);
   int lvl=0, lvlMax=1, lvlCount=0, lvlFirst=0;
   for(int i=0; i<h.lastndx; i++){
      if(!lvlFirst) printf("Level %d: |", lvl), lvlFirst=1;
      printf("%2d|", h.data[i]);
      lvlCount++;
      if(lvlCount==lvlMax){
         lvl++;
         lvlMax *= 2;
         lvlCount = 0;
         lvlFirst = 0;
         printf("\n");
      }
      if(i==h.lastndx-1) printf("\n");
   }
   printf("-----------------------------------\n");
}
void display(Heap h){
   printf("-------LIST--------\n");
   printf(" |DX:DA| |LC:RC|\n");
   for(int i=0; i<h.lastndx; i++){
      int l = leftChild(i)<h.lastndx ? h.data[leftChild(i)] : -1, 
      r = rightChild(i)<h.lastndx ? h.data[rightChild(i)] : -1;
      printf(" |%2d:%2d| |%2d:%2d|\n", i, h.data[i], l, r);
   }
   printf("  Size: %2d/%2d\n", h.lastndx, MAX);
   printf("------------------\n");
}
void displayArray(Heap h){
   printf("-----------------ARRAY-----------------\n");
   for(int i=0; i<h.lastndx; i++){
      if(i==MAX/2) printf("\n");
      printf("%2d, ", h.data[i]);
   }
   printf("\n---------------------------------------\n");
}

void heapifyUp(Heap *h, int ndx){
   for(ndx; ndx>0 && h->data[ndx]<h->data[parent(ndx)]; ndx=parent(ndx)){
      int temp = h->data[ndx];
      h->data[ndx] = h->data[parent(ndx)];
      h->data[parent(ndx)] = temp;
   }
}
void insertSorted(Heap *h, int elem){
   if(!isFull(*h)){
      h->data[h->lastndx] = elem;
      heapifyUp(h, h->lastndx++);
   }
}
void insert(Heap *h, int elem){
   if(!isFull(*h)) h->data[h->lastndx++] = elem;
}

void heapifyDown(Heap *h, int ndx){
   int smallest, l, r, temp;
   do {
      smallest=ndx, l=leftChild(ndx), r=rightChild(ndx), temp=-1;
      if(l<h->lastndx && h->data[smallest]>h->data[l]) smallest = l;
      if(r<h->lastndx && h->data[smallest]>h->data[r]) smallest = r;
      if(smallest!=ndx){
         temp = h->data[ndx];
         h->data[ndx] = h->data[smallest];
         h->data[smallest] = temp;
         ndx = smallest;
      } 
   } while(temp!=-1);
}
int deleteMin(Heap *h){
   int retval = -1;
   if(!isEmpty(*h)){
      retval = h->data[0];
      h->data[0] = h->data[--h->lastndx];
      heapifyDown(h, 0);
   }
   // displayList(*h);
   return retval;
}

void heapify(Heap *h){
   for(int i=parent(h->lastndx); i>=0; i--) heapifyDown(h, i);
}
void heapSort(Heap *h){
   int originalSize = h->lastndx;
   for(--h->lastndx; h->lastndx>0; heapifyDown(h, 0)){
      int temp = h->data[0];
      h->data[0] = h->data[h->lastndx];
      h->data[h->lastndx] = temp;
      h->lastndx--;
   }
   h->lastndx = originalSize;
}

// int isMember(Heap h, int x){
   if(h){
      if(!isMember(h))
   }
}