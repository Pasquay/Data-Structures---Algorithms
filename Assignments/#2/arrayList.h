//array implementaion
#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include<stdio.h>
#include<stdlib.h>
#define size 30

typedef struct{
    char LName[16];
    char FName[24];
    char Mi;
} Nametype;

typedef struct {
    Nametype name;
    unsigned int ID;
    char Course[8];
    int YrLvl;
} Studtype, *StudPtr;

typedef struct {
    Studtype StudArray[size];
    int count;
} StudList, *ListPtr;

void initList(ListPtr *l){
    //for arrays, initialize count only
    *l = (ListPtr)malloc(sizeof(StudList));
    if(*l){
        (*l)->count = 0;
    } else {
        printf("Failed to allocte, did not initlaize list!'\n");
        exit;
    }
}
void addToList(ListPtr l, Studtype s){
    //populates list via array implementation
    l->StudArray[l->count++] = s;
    printf("Successfully added to list!\n");
}
void printNode(Studtype s){
    //separate function for printing Studtype
    printf("%-16s %-16s %c | %-10u | %-8s | %d\n",
       s.name.LName,
       s.name.FName,
       s.name.Mi,
       s.ID,
       s.Course,
       s.YrLvl);
}
void printList(ListPtr l){
    //printing list
    printf("\n------------------------------------------------------------------------\n");
    printf("Name                                | ID         | Course   | Year Level\n");
    for(int ndx = 0; ndx < l->count; ndx++){
        printNode(l->StudArray[ndx]);
    }
    printf("------------------------------------------------------------------------\n");
}
void delNode(ListPtr L, unsigned int ID){
	//add code function here
    int i;
    for(i=0; i<L->count && L->StudArray[i].ID!=ID; i++){}
    if(i<(L->count-1)){
        for(i=i; i<(L->count-1); i++){
            L->StudArray[i] = L->StudArray[i+1];
        }
        L->count--;
        printf("Student %d Deleted Successfully.\n", ID);
    } else {
        printf("Student %d Not Found.\n", ID);
    }
}

#endif