#include <stdlib.h>
#include <string.h>
#include "student.h"

typedef struct node {
    Student stud;
    struct node* link;
} Node, *List;
 
Node* initialize();
void empty(Node* List);
void displayList(List A);
void insertLast(List *A, Student stud);
void insertFirst(List *A, Student stud);
void insertAt(List *A, Student stud, int pos);
void insertSorted(List *A, Student stud); //Add this once i have sort List
void deleteFirst(List *A);
void deleteLast(List *A);
void deleteAt(List *A, int pos);
void deleteId(List *A, char id[]);
Student findStudent(List A, char id[]);
void updateFname(List *A, char id[]);
void updateId(List *A, char id[]);
void updateGpa(List *A, char id[]);
void updateStatus(List *A, char id[]);


/**
 * DISPLAY LIST
 */
void displayList(List A){
    displayStudentHeader();
    for(; A!=NULL; A=A->link) displayStudent(A->stud);
    printf("-----------------------------------------------------------------------------------\n");
}


/**
 * INITIALIZE & DELETE LIST
 */
Node* initialize(){
    List L = NULL;
    return L;
}
void empty(Node* l){
    List *trav;
}

/**
 * INSERTING ELEMENT
 */
void insertLast(List *A, Student stud){
    List temp = (List)malloc(sizeof(Node));
    if(temp!=NULL){
        List *trav;
        for(trav=A; *trav!=NULL; trav=&(*trav)->link){}
        temp->stud = stud;
        temp->link = NULL;
        *trav = temp;
        printf("Student %s added to the end of list.\n", stud.id);
    } else printf("Error: Memory allocation failure.\n");
}
void insertFirst(List *A, Student stud){
    List temp = (List)malloc(sizeof(Node));
    if(temp!=NULL){
        temp->stud = stud;
        temp->link = *A;
        *A = temp;
        printf("Student %s added to the beginning of list.\n", stud.id);
    } else printf("Error: Memory allocation failure.\n");
}
void insertAt(List *A, Student stud, int pos){
    List temp = (List)malloc(sizeof(Node));
    if(temp!=NULL){
        List *trav;
        int count;
        for(trav=A, count=0; *trav!=NULL && count<pos; trav=&(*trav)->link, count++){}
        if(*trav!=NULL){
            temp->stud = stud;
            temp->link = *trav;
            *trav = temp;
            printf("Student %s added to position %d of list.\n", stud.id, pos);
        } else {
            printf("Error: Out of bounds.\n");
        }
    } else printf("Error: Memory allocation error.\n");
}
void insertSorted(List *A, Student stud){

}


/**
 * DELETING ELEM
 */
void deleteFirst(List *A){
    if(*A!=NULL){
        List temp = *A;
        *A = (*A)->link;
        free(temp);
        printf("Student at beggining of list deleted.\n");
    } else printf("Error: List is empty.\n");
}
void deleteLast(List *A){
    List *trav;
    for(trav = A; (*trav)->link != NULL; trav = &(*trav)->link) {}
    if (*trav != NULL) {
        List temp = *trav;
        *trav = NULL;
        free(temp);
        printf("Student at the end of list deleted.\n");
    } else {
        printf("Error: List is empty.\n");
    }
}
void deleteAt(List *A, int pos){
    if(*A!=NULL){
        List *trav;
        int count;
        for(trav=A, count=0; *trav!=NULL && count<pos; trav=&(*trav)->link, count++){}
        if(*trav!=NULL){
            List temp = *trav;
            *trav = temp->link;
            free(temp);
            printf("Student at position %d deleted.\n", pos);
        } else printf("Error: Out of bounds.\n");
    } else printf("Error: List is empty.\n");
}
void deleteId(List *A, char id[]){
    if(*A!=NULL){
        List *trav;
        for(trav=A; *trav!=NULL && strcmp((*trav)->stud.id, id); trav=&(*trav)->link){}
        if(*trav!=NULL){
            List temp = *trav;
            *trav = temp->link;
            free(temp);
            printf("Student %s deleted.\n", id);
        } else printf("Error: Student %s not found.\n", id);
    } else printf("Error: List is empty.\n");
}


/**
 * FINDING ELEMENT
 */
Student findStudent(List A, char id[]){
    List trav;
    for(trav=A; trav!=NULL && strcmp(trav->stud.id, id); trav=trav->link){}
    return (trav==NULL) ? 
        (Student){{"", "", '\0'}, "", "", 0, 0, "", 0.0, 0} :
        trav->stud ;
}


/**
 * UPDATING ELEMENT
 */
void updateFname(List *A, char id[]){
    if(*A!=NULL){
        List *trav;
        for(trav=A; *trav!=NULL && strcmp((*trav)->stud.id, id)!=0; trav=&(*trav)->link){
            printf("%s\t%s\n", (*trav)->stud.id, id);
        }
        if(*trav!=NULL){
            printf("New FName: ");
            char fname[NAME_MAX];
            scanf("%[^\n]s", &fname);
            strcpy((*trav)->stud.name.fname, fname);
            printf("Student FName Updated.\n");
        } else printf("Error: Student %s not found.\n", id);
    } else printf("Error: List is empty.\n");
}
void updateId(List *A, char id[]){
    // FIX TS UY
    if(*A!=NULL){
        List *trav;
        for(trav=A; *trav!=NULL && strcmp((*trav)->stud.id, id)!=0; trav=&(*trav)->link){}
        if(*trav!=NULL){
            displayStudentHeader();
            displayStudent((*trav)->stud);
            printf("Enter ID: ");
            char id[9]; scanf("%[^\n]s", id);
            List *trav2; 
            int unique = 1;
            for(trav2=A; *trav2!=NULL && unique==1; trav2=&(*trav2)->link){
                if(strcmp((*trav)->stud.id, id)!=0)
                unique = 0;
            }
            if(unique==1){
                strcpy((*trav)->stud.id, id);
                displayStudentHeader();
                displayStudent((*trav)->stud);
            } else printf("Error: ID already exists.\n");
        } else printf("Error: Student not found.\n");
    } else printf("Error: List is empty.\n");
}
void updateGpa(List *A, char id[]){
    if(*A!=NULL){
        List *trav;
        for(trav=A; *trav!=NULL && strcmp((*trav)->stud.id, id)!=0; trav=&(*trav)->link){}
        if(*trav!=NULL){
            
        } else printf("Error: Student not found.\n");
    } else printf("Error: List is empty.\n");
}
void updateStatus(List *A, char id[]){
    if(*A!=NULL){
        List *trav;
        for(trav=A; *trav!=NULL && strcmp((*trav)->stud.id, id)!=0; trav=&(*trav)->link){}
        if(*trav!=NULL){
            
        } else printf("Error: Student not found.\n");
    } else printf("Error: List is empty.\n");
}



