#include <stdio.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node *head;
    int count;
} List;

List* initialize();
void empty(List *list);
void display(List *list);
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
int retrieve(List *list, int index);
int locate(List *list, int data);

List* initialize(){
    List *l = (List*)malloc(sizeof(List));
    if(l!=NULL){
        l->head = NULL;
        l->count = 0;
        printf("Success: List initalized.\n");
        return l;
    } else {
        printf("Error: Memory allocation error.\n");
        return NULL;
    }
}
void empty(List *list){
    if(list->head == NULL) printf("Error: List is empty.\n");
    else {
        for(list->head; list->head!=NULL;){
            Node *temp = list->head;
            list->head = temp->next;
            free(temp);
        }
        list->head = NULL;
        list->count = 0;
        printf("Success: List emptied.\n");
    }
}
void display(List *list){
    // current - head
    printf("List: ");
    Node *current;
    for(current=list->head; current!=NULL; current=current->next) {
        printf("%d -> ", current->data);
    }
    printf("NULL\nCount: %d\n", list->count);
}
void insertFirst(List *list, int data){
    Node *temp = (Node*)malloc(sizeof(Node));
    if(temp==NULL) printf("Error: Memory allocation failure.\n");
    else {
        temp->data = data;
        temp->next = list->head;
        list->head = temp;
        list->count++;
        printf("Success: %d inserted to head.\n", data);
    }
}
void insertLast(List *list, int data){
    Node *temp = (Node*)malloc(sizeof(Node));
    if(temp==NULL) printf("Error: Memory allocation failure.\n");
    else {
        temp->data = data;
        temp->next = NULL;
        if(list->head==NULL) {
            list->head = temp;
            printf("Success: %d inserted to head.\n", data);
        } else {
            Node *current;
            for(current=list->head; current->next!=NULL; current=current->next){}
            current->next = temp;
            printf("Success: %d inserted to tail.\n", data);
        }
        list->count++;
    }
}
void insertPos(List *list, int data, int index){
    if(index > list->count) printf("Error: Index is out of bounds.\n");
    else {
        if(index == 0) insertFirst(list, data);
        else if(index == list->count) insertLast(list, data);
        else {
            Node *current;
            int count;
            for(current=list->head, count=1; current!=NULL && count<index; current=current->next, count++){}
            Node *temp = (Node*)malloc(sizeof(Node));
            if(temp==NULL) printf("Error: Memory allocation failure.\n");
            else {
                temp->data = data;
                temp->next = current->next;
                current->next = temp;
                printf("Success: %d inserted to [%d].\n", data, index);
                list->count++;
            }
        }
    }
}
void deleteStart(List *list){
    if(list->head == NULL) printf("Error: List is empty.\n");
    else {
        Node *temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->count--;
        printf("Success: Head deleted.\n");
    }
}
void deleteLast(List *list){
    if(list->head == NULL) printf("Error: List is empty.\n");
    else {
        if(list->head->next == NULL){
            deleteStart(list);
        } else {
            int count;
            Node *current;
            for(current=list->head, count=0; count<(list->count)-2; count++, current=current->next){}
            Node *temp = current->next;
            current->next = temp->next;
            free(temp);
            list->count--;
            printf("Success: Deleted from tail.\n");
        }
    }
}
void deletePos(List *list, int index){
    if(index > list->count) printf("Error: Index is out of bounds.\n");
    else {
        if(index == 0) deleteStart(list);
        else if (index == list->count) deleteLast(list);
        else {
            Node *current;
            int count;
            for(current=list->head, count=1; current->next!=NULL && count<index; current=current->next, count++){}
            Node *temp = current->next;
            current->next = temp->next;
            free(temp);
            list->count--;
            printf("Success: Deleted from [%d].\n", index);
        }
    }
}
int retrieve(List *list, int index){
    if(index > list->count-1) printf("Error: Index is out of bounds.\n");
    else {
        Node *current;
        int count;
        for(current=list->head, count=0; current!=NULL && count<index; current=current->next, count++){}
        printf("Success: %d found at [%d].\n", current->data, index);
        return current->data;
    }
}
int locate(List *list, int data){
    if(list->head == NULL) printf("Error: List is empty.\n");
    else {
        Node *current;
        int index;
        for(current=list->head, index=0; current!=NULL && current->data!=data; current=current->next, index++){}
        if(current == NULL) printf("Error: %d not found in list.\n", data);
        else printf("Success: %d found in [%d].\n", data, index);
        return (current == NULL) ? -1 : index;
    }
}