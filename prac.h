#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#define BITS 8

typedef char Set;

void initialize(Set *s){ *s = 0; }
void displayBits(Set s){
    for(int mask=1<<sizeof(Set)*BITS-1, gap=0; mask>0; mask>>=1, gap++){
        if(gap%4==0 && gap) printf(" ");
        printf("%d", mask&s?1:0);
    }
    printf("\n");
}
void displaySet(Set s){
    printf("{");
    for(int mask=1, first=0, value=1; mask<sizeof(Set)<<BITS-1; mask<<=1, value++){
        if(!first && mask&s) printf(" %d", value), first=1;
        else if(first && mask&s) printf(", %d", value);
    }
    printf(" }\n");
}
void insert(Set *s, int elem){
    if(elem>7 || elem<0) printf("E: [%d] Out of Bounds\n", elem);
    else {
        if(*s&1<<sizeof(Set)*elem-1) printf("E: [%d] Alread inserted\n", elem);
        else {
            *s |= 1<<sizeof(Set)*elem-1;
            printf("S: [%d] Inserted\n", elem);
        }
    }
}
void delete(Set *s, int elem){
    if(elem>7 || elem<0) printf("E: [%d] Out of Bounds\n", elem);
    else {
        if(*s&1<<sizeof(Set)*elem-1){
            *s &= ~(1<<sizeof(Set)*elem-1);
            printf("S: [%d] Delete\n", elem);
        } else printf("E: [%d] Already Deleted\n", elem);
    }
}
bool find(Set s, int elem){ return (elem>7 || elem<0) ? false : s&1<<sizeof(Set)*elem; }
Set setUnion(Set x, Set y){ return x|y; }
Set setIntersection(Set x, Set y){ return x&y; }
Set setDifference(Set x, Set y){ return x&~y; }


