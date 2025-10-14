#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char set;

void initialize(set *var);
void displayBits(set var);
void displaySet(set var);
void insert(set *var, int element);
void delete(set *var, int element);
bool find(set var, int element);
set setUnion(set A, set B);
set setIntersection(set A, set B);
set setDifference(set A, set B);

void initialize(set *var){
    *var = 0;
}
void displayBits(set var){
    int mask=1<<sizeof(set)*8-1, gap=1;
    for(;mask>0; mask>>=1, gap++){
        printf("%d", var&mask?1:0);
        if(gap%4==0) printf(" ");
    }
    printf("\n");
}
void displaySet(set var){
    printf("{ ");
    int mask=1, val=0, first = 0;
    for(; mask<=(1<<8-1); val++, mask<<=1){
        if(!first && var&mask) printf("%d", val), first=1;
        else if(var&mask) printf(", %d", val);
    }
    printf(" }\n");
}
void insert(set *var, int element){
    if(element<0 || element>7) printf("Error  : [%d] outside of bit range [0-7]\n", element);
    else {
        *var |= (1<<element);
        printf("Success: Inserted [%d]\n", element);
    }
}
void delete(set *var, int element){
    if(element<0 || element>7) printf("Error  : [%d] outside of bit range [0-7]\n", element);
    else {
        if(*var&(1<<element)){
            *var &= ~(1<<element);
            printf("Success: deleted [%d]\n", element);
        } else {
            printf("Warning: [%d] not in set\n", element);
        }
    }
}
bool find(set var, int element){
    return (element>-1 && element<8) ? var&(1<<element) : 0;
}
set setUnion(set A, set B){
    return A|B;
}
set setIntersection(set A, set B){
    return A&B;
}
set setDifference(set A, set B){
    return A&~B;
}
