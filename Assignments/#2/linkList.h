
//linked list implementation
#ifndef LINKLIST_H
#define LINKLIST_H
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

typedef struct node {
    Studtype data;
    struct node *next;
} Node, *NodePtr;

typedef struct {
    NodePtr head;
} List, *ListPtr;

void initList(ListPtr *l){
    //initialize list with fallback
    *l = malloc(sizeof(List));
    if(*l){
        (*l)->head = NULL;
    } else {
        printf("Failed to allocte, did not initlaize list!'\n");
        exit;
    }
}
void addToList(ListPtr l, Studtype s){
    //adding to list with a fallback
    Node **a = &l->head;
    while(*a){
        a = &(*a)->next;
    }
    *a = malloc(sizeof(Node));
    if(!(*a)){
        printf("Failed to allocate, cannot add node!\n");
        exit;
    } else {
        (*a)->data = s;
        (*a)->next = NULL;
        printf("Successfully added to list!\n");
    }
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
    NodePtr a = l->head;
    printf("\n------------------------------------------------------------------------\n");
    printf("Name                                | ID         | Course   | Year Level\n");
    for(;a;a=a->next){
        printNode(a->data);
    }
    printf("------------------------------------------------------------------------\n");
}
void delNode(ListPtr L, unsigned int ID){
	//add code function here
    NodePtr *trav;
    for(trav=&L->head; *trav!=NULL && (*trav)->data.ID!=ID; trav=&(*trav)->next){}
    if(*trav!=NULL){
        NodePtr temp = *trav;
        *trav = temp->next;
        free(temp);
        printf("Student %d Deleted Successfully.\n", ID);
    } else {
        printf("Student %d Not Found.\n", ID);
    }
}


#endif 


