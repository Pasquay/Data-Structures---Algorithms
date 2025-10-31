#include <stdio.h>
#include <stdlib.h>

#define MAX 15
#define EMPTY '\0'
#define DELETED '~'

typedef struct node{
    char data;
    int link;
}NODE_T;

typedef struct{
    NODE_T synonyms[MAX];
    int avail;
}virtualHeap;

typedef struct{
    NODE_T elems[MAX];
    virtualHeap VH;
}*dictionary, DICT_T;

dictionary *GLOBAL_DICT;

//main functions (do not touch)
void SIGHANDLER(int signal);
int HASH_FUNC(char SRC);
void appendHandler(dictionary D);
void deleteHandler(dictionary D);
void finderHandler(dictionary D);
void checkHash();
void switcher(dictionary D, int choice);
void looper(dictionary D);
void displayDataStructure(dictionary D);
void initVirtualHeap(virtualHeap *VH);
void initHashTable(NODE_T *SRC);
void initDictionary(dictionary *D);
int allocSpace(virtualHeap *VH);
void deallocSpace(virtualHeap *VH, int ndx);
//--------------------------------
//|---user functions (modify)----|
//--------------------------------
void insertAuto(dictionary D, char elem);
void deleteAuto(dictionary D, char TARG);
void finder(dictionary D, char elem);



void insertAuto(dictionary D, char elem){
    int ELEM_NDX = HASH_FUNC(elem);
    NODE_T *ptr;

    //----implementation here---------
}

void deleteAuto(dictionary D, char TARG){
    int ELEM_NDX = HASH_FUNC(TARG);
    NODE_T *ptr;

    //----implementation here---------
}

void finder(dictionary D, char elem){
    int ELEM_NDX = HASH_FUNC(elem);
    NODE_T *ptr;

    //----implementation here---------
}

int main(){
    dictionary D;
    initDictionary(&D);

    GLOBAL_DICT = &D;
    looper(D);
    return 0;
}
//--------------------------------
//|---DO NOT MODIFY!!!!!!!!!!!---|
//--------------------------------
void displayDataStructure(dictionary D){
    NODE_T *HPTR = D->elems;
    NODE_T *VPTR = D->VH.synonyms;

    printf("\nDICTIONARY STATUS");
    printf("\n%-32s", "--------------------------------------------");
    printf("\n| %-4s | %-15s | %-15s |", "BASE", "Prime Table", "Synonym Table");
    printf("\n| %-4s | %-7s %-7s | %-7s %-7s |", "NDX", "Data", "Link", "Data", "Link");
    for(int i = 0; i < MAX; i++){
        printf("\n| %-4d | %-7c %-7d | %-7c %-7d |",
            i, 
            (HPTR[i].data == EMPTY || HPTR[i].data == DELETED) ? ' ' : HPTR[i].data,
            HPTR[i].link,
            (VPTR[i].data == EMPTY || HPTR[i].data == DELETED) ? ' ' : VPTR[i].data,
            VPTR[i].link
        );
    }
    printf("\n%-32s", "--------------------------------------------");
}

void initVirtualHeap(virtualHeap *VH){
    for(int i = 0; i < MAX; i++){
        VH->synonyms[i].link = i - 1;
        VH->synonyms[i].data = EMPTY;
    }
    VH->avail = MAX - 1;
}

void initHashTable(NODE_T *SRC){
    for(int i = 0; i < MAX; i++){
        SRC[i].data = EMPTY;
        SRC[i].link = -1; 
    }
}

void initDictionary(dictionary *D){
    *D = (dictionary)malloc(sizeof(DICT_T));
    initVirtualHeap(&(*D)->VH);
    initHashTable((*D)->elems);
}

int allocSpace(virtualHeap *VH){
    int ndx = VH->avail;
    if(ndx != -1){
        VH->avail = VH->synonyms[ndx].link;
    }
    return ndx;
}

void deallocSpace(virtualHeap *VH, int ndx){
    if(ndx > -1 && ndx < MAX){
        VH->synonyms[ndx].link = VH->avail;
        VH->synonyms[ndx].data = DELETED;
        VH->avail = ndx;
    }
}

void SIGHANDLER(int signal){
    if(signal){
        printf("\nSIGINT - Premature termination!");
    }
    printf("\nFreeing dictionary with [%lu] bytes", (unsigned long)sizeof(DICT_T));
    free(*GLOBAL_DICT);
}

int HASH_FUNC(char SRC){
    return ((unsigned char)SRC * 31) % MAX;
}

void appendHandler(dictionary D){
    char elem;

    printf("Enter the element to append: ");
    scanf(" %c", &elem);
    insertAuto(D, elem);
}

void deleteHandler(dictionary D){
    char elem;

    printf("Enter the element to delete: ");
    scanf(" %c", &elem);
    deleteAuto(D, elem);
}

void finderHandler(dictionary D){
    char TARGET;

    printf("Enter what element to search: ");
    scanf(" %c", &TARGET);
    finder(D, TARGET);
}

void checkHash(){
    char elem;
    int hash;

    printf("\nEnter an element to check hash: ");
    scanf(" %c", &elem);
    hash = HASH_FUNC(elem);
    printf("\nReturned hash: [%c] -> [%d]", elem, hash);
}

void switcher(dictionary D, int choice){
    switch(choice){
        case 0:
            printf("\nProgram terminated.");
            displayDataStructure(D);
            SIGHANDLER(0);
            break;
        case 1:
            appendHandler(D);
            break;
        case 2:
            deleteHandler(D);
            break;
        case 3:
            finderHandler(D);
            break;
        case 4:
            checkHash();
            break;
        default:
            printf("\nInvalid choice!");
            break;
    }
}

void looper(dictionary D){
    int choice = -1;

    while(choice != 0){
        scanf("%d", &choice);
        switcher(D, choice);
    }
}
