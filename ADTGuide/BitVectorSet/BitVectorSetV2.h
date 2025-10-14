#include <stdio.h>
#include <stdbool.h>

typedef struct {
    // "field : 8" sets field to be 8 bits wide
    unsigned int field : 8;
} Set;

void initialize(Set *set);
void insertElem(Set *set, int element);
void deleteElem(Set *set, int element);
bool find(Set set, int element);
Set setUnion(Set A, Set B);
Set setIntersection(Set A, Set B);
Set setDifference(Set A, Set B);
void displayBits(Set set);
void displaySet(Set set);


void initialize(Set *set){
    set->field = 0;
}
void insertElem(Set *set, int element){
    if(element<0 || element>7) printf("Error  : Position out of bit range.\n");
    else {
        if(!(set->field&1<<element)){
            set->field |= 1<<element;
            printf("Success: inserted [%d].\n", element);
        } else printf("Warning: [%d] already in set.\n", element);
    }
}
void deleteElem(Set *set, int element){
    if(element<0||element>7) printf("Error  : Position out of bit range.\n");
    else {
        if(!(set->field&1<<element)) printf("Warning: [%d] not in set.\n", element);
        else {
            set->field &= ~(1<<element);
            printf("Success: Deleted [%d].\n", element);
        }
    }
}
bool find(Set set, int element){
    return set.field&1<<element;
}
Set setUnion(Set A, Set B){
    return (Set){A.field|B.field};
}
Set setIntersection(Set A, Set B){
    return (Set){A.field&B.field};
}
Set setDifference(Set A, Set B){
    return (Set){A.field&~B.field};
}
void displayBits(Set set){
    int mask=1<<8-1, gap=1;
    for(;mask>0; mask>>=1, gap++){
        printf("%d", set.field&mask?1:0);
        if(gap%4==0) printf(" ");
    }
    printf("\n");
}
void displaySet(Set set){
    int mask=1, first=0, value=0;
    printf("{ ");
    for(; mask<=1<<8-1; mask<<=1, value++){
        if(!first && set.field&mask) printf("%d", value), first = 1;
        else if(set.field&mask) printf(", %d", value);
    }
    printf(" }\n");
}