#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct {
    int *elemPtr;
    int count;
    int max;
} List;

void initialize(List *L);
void display(List *L);
void insertPos(List *L, int data, int position);
void resize(List *L);
void removePos(List *L, int position);
int locate(List *L, int data);
int retrieve(List *L, int position);
void sortAsc(List *L);
void sortDesc(List *L);
void insertSorted(List *L, int data);

/**
 * INITIALIZE LIST
 */
void initialize(List *L) {
    L->max = LENGTH;
    L->elemPtr = (int*)malloc(sizeof(int)*L->max);
    L->count = 0;
}

/**
 * DISPLAY LIST
 */
void display(List *L) {
    int i;
    printf("[ ");
    for(i=0; i<L->count; i++) printf("%d, ", L->elemPtr[i]);
    printf("]\nCount: [%d]\tMax: [%d]\n", L->count, L->max);
}

/**
 * INSERT ELEMENT
 */
void insertPos(List *L, int data, int position) {
    if(position < 0 || position > L->count) printf("Error: Index is out of bounds.\n");
    else {
        if (L->count == L->max) resize(L);
        int i;
        for(i=L->count; i>position; i--){
            L->elemPtr[i] = L->elemPtr[i-1];
        }
        L->elemPtr[i] = data;
        L->count++;
        printf("Success: %d inserted to [%d].\n", data, position);
    }
}
void insertSorted(List *L, int data) {
    if(L->count == L->max) resize(L);
    int i;
    for(i=L->count-1; i>=0 && data<L->elemPtr[i]; i--){
        L->elemPtr[i+1] = L->elemPtr[i];
    }
    L->elemPtr[i+1] = data;
    L->count++;
    printf("Success: %d inserted.\n", data);
}

/**
 * RESIZE LIST
 */
void resize(List *L) {
    L->max *= 2;
    L->elemPtr = (int*)realloc(L->elemPtr, sizeof(int)*L->max);
}

/**
 * DELETE ELEMENT
 */
void removePos(List *L, int position) {
    if(L->count == 0) printf("Error: List is empty.\n");
    else if(position < 0 || position >= L->count) printf("Error: Index is out of bounds.\n");
    else {
        int i;
        for(i=0; i<position; i++){}
        L->count--;
        for(i=i; i<L->count; i++){
            L->elemPtr[i] = L->elemPtr[i+1];
        }
        printf("Success: Deleted from [%d].\n", position);
    }
}

/**
 * LOCATE ELEMENT
 */
int locate(List *L, int data) {
    int i;
    for(i=0; i<L->count && L->elemPtr[i]!=data; i++){}
    return (i == L->count) ? -1 : i;
}

/**
 * RETRIEVE ELEMENT
 */
int retrieve(List *L, int position) {
    if(position < 0 || position > L->count) printf("Error: Index is out of bounds.\n");
    int i;
    for(i=0; i<position; i++){}
    return (i==L->count) ? -1 : L->elemPtr[i];
}

/**
 * SORT LIST
 */
void sortAsc(List *L) {
    int out, in, min, temp;
    for(out=0; out<L->count-1; out++){
        min = out;
        for(in=out; in<L->count; in++){
            if(L->elemPtr[min] > L->elemPtr[in]) min = in;
        }
        if(min!=out){
            temp = L->elemPtr[min];
            L->elemPtr[min] = L->elemPtr[out];
            L->elemPtr[out] = temp;
        }
    }
    printf("Success: List sorted.\n");
}
void sortDesc(List *L) {
    int out, in, max, temp;
    for(out=0; out<L->count-1; out++){
        max = out;
        for(in=out; in<L->count; in++){
            if(L->elemPtr[max] < L->elemPtr[in]) max = in;
        }
        if(max!=out){
            temp = L->elemPtr[max];
            L->elemPtr[max] = L->elemPtr[out];
            L->elemPtr[out] = temp;
        }
    }
    printf("Success: List sorted.\n");
}
