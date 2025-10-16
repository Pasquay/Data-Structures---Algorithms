#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
    int data;
    int prio;
} Elem;

typedef struct node {
    Elem data;
    struct node *next;
} Node, *List;

void initList(List *l){
    *l = NULL;
    printf("Success: Init List\n");
}
void display(List l){
    List trav = l;
    printf("========LIST========\n");
    printf(" [POS] [DATA][PRIO]\n");
    int i=0;
    for(; trav!=NULL; trav=trav->next, i++) 
        printf(" [%3d] [%4d][%4d]\n", i, trav->data.data, trav->data.prio);
    printf("Count: [%d]\n", i);
    printf("====================\n");
}
void insertLast(List *l, int data, int prio){
    List temp = malloc(sizeof(Node));
    if(!temp) printf("Error: Memory Failure\n");
    else {
        *temp = (Node){{data, prio}, NULL};
        if(*l==NULL){
            *l = temp;
            printf("Success: Insert Last [H]\n");
        } else {
            List *trav = l;
            for(; *trav!=NULL; trav=&(*trav)->next){}
            *trav = temp;
            printf("Success: Insert Last [T]\n");
        }
    }
}
void insertPrio(List *l, int data, int prio){
    List temp = malloc(sizeof(Node));
    if(!temp) printf("Error: Memory Failure\n");
    else {
        if(*l==NULL){
            *temp = (Node){{data, prio}, NULL};
            *l = temp;
            printf("Success: Insert First [H]\n");
        } else {
            List *trav = l;
            for(; *trav!=NULL && prio<(*trav)->data.prio; trav=&(*trav)->next){}
            *temp = (Node){{data, prio}, *trav};
            *trav = temp;
            printf("Success: Insert First [P]\n");
        }
    }
}
void deleteMax(List *l){
    if(*l==NULL) printf("Error: List Empty\n");
    else {
        List temp = *l;
        *l = (*l)->next;
        printf("Success: Delete Max [%d]\n", temp->data.data);
        free(temp);
    }
}
void deleteMin(List *l){
    if(*l==NULL) printf("Error: List Empty\n");
    else {
        if((*l)->next==NULL){
            List temp = *l;
            *l = (*l)->next;
            printf("Success: Delete Min [%d]\n", temp->data.data);
            free(temp);
        } else {
            List *trav = l;
            for(; (*trav)->next!=NULL; trav=&(*trav)->next){}
            List temp = *trav;
            *trav = (*trav)->next;
            printf("Success: Delete Min [%d]\n", temp->data.data);
            free(temp);
        }
    }
}
