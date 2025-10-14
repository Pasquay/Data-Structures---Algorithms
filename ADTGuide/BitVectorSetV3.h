#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ARRAY_SIZE 8

typedef bool Set[ARRAY_SIZE];

void initialize(Set set);
void displayBits(Set set);
void displaySet(Set set);
void insertElem(Set set, int element);
void deleteElem(Set set, int element);
bool find(Set set, int element);
void setUnion(Set A, Set B, Set C);
void setIntersection(Set A, Set B, Set C);
void setDifference(Set A, Set B, Set C);


void initialize(Set set){
    for(int i=0; i<ARRAY_SIZE; i++){
        set[i] = 0;
    }
}
void displayBits(Set set){
    int i=0, gap=1;
    for(; i<ARRAY_SIZE; i++, gap++){
        printf("%d", set[i]);
        if(gap%4==0) printf(" ");
    }
    printf("\n");
}
void displaySet(Set set){
    printf("{ ");
    int first=0, i=0;
    for(; i<ARRAY_SIZE; i++){
        if(!first && set[i]) printf("%d", i), first=1;
        else if(set[i]) printf(", %d", i);
    }
    printf(" }\n");
}
void insertElem(Set set, int element){
    if(element<0||element>7) printf("Error  : [%d] is out of bounds\n", element);
    else {
        if(set[element]) printf("Warning: [%d] already in set\n", element);
        else {
            set[element] = 1;
            printf("Success: Inserted [%d]\n", element);
        }
    }
}
void deleteElem(Set set, int element){
    if(element<0 || element>7) printf("Error  : [%d] is out of bounds\n", element);
    else {
        if(!set[element]) printf("Warning: [%d] not in set\n", element);
        else {
            set[element] = 0;
            printf("Success: Removed [%d]\n", element);
        }
    }
}
bool find(Set set, int element){
    return (element>-1&&element<8) ? set[element] : 0 ;
}
void setUnion(Set A, Set B, Set C){
    for(int i=0; i<ARRAY_SIZE; i++) C[i] = (A[i]|B[i]);
}
void setIntersection(Set A, Set B, Set C){
    for(int i=0; i<ARRAY_SIZE; i++) C[i] = (A[i]&B[i]);
}
void setDifference(Set A, Set B, Set C){
    for(int i=0; i<ARRAY_SIZE; i++) C[i] = (A[i]&~B[i]);
}