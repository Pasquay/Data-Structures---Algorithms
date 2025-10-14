#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} Etype, *EPtr;

void initialize(EPtr L);
void display(EPtr L);
void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);
int locate(EPtr L, int data);
void sortAsc(EPtr L);
void sortDesc(EPtr L);
void makeNULL(EPtr L);

/**
 * INITIALIZE LIST
 */
void initialize(EPtr L){
    L->count = 0;
}


/**
 * DISPLAY LIST
 */
void display(EPtr L){
    int i;
    printf("[ ");
    for(i=0; i<L->count; i++){
        printf("%d, ", L->elem[i]);
    }
    printf("]\n");
    printf("Count: [%d]\n", L->count);
}


/**
 * INSERT ELEMENT
 */
void insertPos(EPtr L, int data, int position){
    if(L->count == MAX) printf("Error: List is full.\n");
    else if(position>L->count || position<0) printf("Error: Index is out of bounds.\n");
    else {
        int i;
        for(i=L->count-1; i>=position; i--){
            L->elem[i+1] = L->elem[i];
        }
        L->elem[position] = data;
        L->count++;
        printf("Success: %d inserted at [%d].\n", data, position);
    }
}


/**
 * DELETE ELEMENT
 */
void deletePos(EPtr L, int position){
    if(L->count == 0) printf("Error: List is empty.\n");
    else if(position > L->count-1 || position < 0) printf("Error: Index is out of bounds.\n");
    else {
        int i;
        for(i=0; i<position; i++){}
        L->count--;
        for(i=i; i<L->count; i++){
            L->elem[i] = L->elem[i+1];
        }
        printf("Success: Deleted from [%d].\n", position);
    }
}


/**
 * LOCATE ELEMENT
 */
int locate(EPtr L, int data){
    int i;
    for(i=0; i<L->count && L->elem[i]!=data; i++){}
    return (i==L->count) ? -1 : i;
}
int retrieve(EPtr L, int position){
    if(position > L->count-1 || position < 0) printf("Error: Index is out of bounds.\n");
    else {
        return L->elem[position];
    }
}


/**
 * SORT LIST
 */
void sortAsc(EPtr L){
    if(L->count == 0) printf("Error: List is empty.\n");
    else {
        int out, in, min, temp;
        for(out=0; out<L->count-1; out++){
            min = out;
            for(in=out; in<L->count; in++){
                if(L->elem[min] > L->elem[in]) min = in;
            }
            if(min != out){
                temp = L->elem[min];
                L->elem[min] = L->elem[out];
                L->elem[out] = temp;
            }
            printf("Success: List sorted.\n");
        }
    }
}
void sortDesc(EPtr L){
    if(L->count == 0) printf("Error: List is empty.\n");
    else {
        int out, in, max, temp;
        for(out=0; out<L->count-1; out++){
            max = out;
            for(in=out; in<L->count; in++){
                if(L->elem[max] < L->elem[in]) max = in;
            }
            if(max != out){
                temp = L->elem[max];
                L->elem[max] = L->elem[out];
                L->elem[out] = temp;
            }
            printf("Success: List sorted.\n");
        }
    }
}


/**
 * EMPTY LIST
 */
void makeNULL(EPtr L){
    L->count = 0;
    printf("Success: List emptied.\n");
}
