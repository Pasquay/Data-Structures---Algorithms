#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX 10

typedef struct {
    char data;
    int next;
} stype, HeapSpace[MAX];

typedef struct {
    HeapSpace arr;
    int avail;
} VHeap;

void tempDisplay(VHeap *vh, int *head);
void init(VHeap *vh);
void initList(int *head);
int alloc(VHeap *vh);
void dealloc(VHeap *vh, int ndx);
bool isEmpty(int *head);
void insertFirst(VHeap *vh, int *head, char data);
void insertLast(VHeap *vh, int *head, char data);
void insertSorted(VHeap *vh, int *head, char data);
void deleteFirst(VHeap *vh, int *head);
void deleteLast(VHeap *vh, int *head);
void deleteValue(VHeap *vh, int *head, int data);
void sortAsc(VHeap *vh, int *head);
void sortDesc(VHeap *vh, int *head);
void display(VHeap *vh, int *head);



void tempDisplay(VHeap *vh, int *head){
    for(int i=*head; i!=-1; i=vh->arr[i].next){
        printf(" %c ", vh->arr[i].data);
    }
    printf("\n");
    for(int i=*head; i!=-1; i=vh->arr[i].next){
        printf("[%d]", vh->arr[i].next);
    }
    printf("\n");
    printf("Head: [%d] Avail: [%d]\n", *head, vh->avail);
}
void init(VHeap *vh){
    int ndx;
    for(ndx=MAX-1; ndx>-1; ndx--) vh->arr[ndx].next = ndx-1;
    vh->avail = MAX-1;
}
void initList(int *head){
    *head = -1;
}
int alloc(VHeap *vh){
    int retval = vh->avail;
    if(retval!=-1) vh->avail = vh->arr[retval].next;
    return retval;
}
void dealloc(VHeap *vh, int ndx){
    if(vh->avail!=MAX-1){
        vh->arr[ndx].next = vh->avail;
        vh->avail = ndx;
    }
}
bool isEmpty(int *head){
    return (*head==-1) ? true : false;
}
void insertFirst(VHeap *vh, int *head, char data){
    int temp = alloc(vh);
    if(temp!=-1){
        vh->arr[temp].data = data;
        vh->arr[temp].next = *head;
        *head = temp;
    }
}
void insertLast(VHeap *vh, int *head, char data){
    if(*head==-1) insertFirst(vh, head, data);
    else {
        int temp = alloc(vh);
        if(temp!=-1){
            int ndx = *head;
            for(; vh->arr[ndx].next!=-1; ndx = vh->arr[ndx].next){}
            vh->arr[temp].data = data;
            vh->arr[ndx].next = temp;
            vh->arr[temp].next = -1;
        }
    }
}
void insertSorted(VHeap *vh, int *head, char data){
    if(data<=vh->arr[*head].data) insertFirst(vh, head, data);
    else{
        int temp = alloc(vh);
        if(temp!=-1){
            int ndx = vh->arr[*head].next, prev=*head;
            for(; ndx!=-1 && data>vh->arr[ndx].data; prev=ndx, ndx=vh->arr[ndx].next){}
            vh->arr[temp].next = ndx;
            vh->arr[prev].next = temp;
            vh->arr[temp].data = data;
        }
    }
}
void deleteFirst(VHeap *vh, int *head){
    if(*head!=-1){
        int temp = *head;
        *head = vh->arr[*head].next;
        dealloc(vh, temp);
        printf("Success: Delete first\n");
    } else printf("Error: Empty list\n");
}
void deleteLast(VHeap *vh, int *head){
    if(*head!=-1){
        if(vh->arr[*head].next==-1) deleteFirst(vh, head);
        else {
            int ndx = *head;
            for(;  vh->arr[vh->arr[ndx].next].next!=-1; ndx=vh->arr[ndx].next){}
            dealloc(vh, vh->arr[ndx].next);
            vh->arr[ndx].next = -1;
            printf("Success: Delete last\n");
        }
    } else printf("Error: Empty list\n");
}
void deleteValue(VHeap *vh, int *head, int data){
    if(!isEmpty(head)){
        if(vh->arr[*head].data==data) deleteFirst(vh, head);
        else {
            int curr=vh->arr[*head].next, prev=*head;
            for(; curr!=-1 && vh->arr[curr].data!=data; prev=curr, curr=vh->arr[curr].next){}
            if(curr!=-1){
                vh->arr[prev].next = vh->arr[curr].next;
                dealloc(vh, curr);
            }
        }
    }
}
void sortAsc(VHeap *vh, int *head){
    if(!isEmpty(head)){
        int out, in, min; char temp;
        for(out=*head; vh->arr[out].next!=-1; out=vh->arr[out].next){
            min = out;
            for(in=vh->arr[out].next; in!=-1; in=vh->arr[in].next){
                if(vh->arr[min].data > vh->arr[in].data) min = in;
                // printf(" %c ", vh->arr[in].data);
                // printf("[%d]\n", vh->arr[in].next);
            }
            if(min != out){
                temp = vh->arr[min].data;
                vh->arr[min].data = vh->arr[out].data;
                vh->arr[out].data = temp;
            }
        }
    }
}
void sortDesc(VHeap *vh, int *head){
    if(!isEmpty(head)){
        int out, in, max; char temp;
        for(out=*head; vh->arr[out].next!=-1; out=vh->arr[out].next){
            max = out;
            for(in=vh->arr[out].next; in!=-1; in=vh->arr[in].next){
                if(vh->arr[max].data < vh->arr[in].data) max = in;
                // printf(" %c ", vh->arr[in].data);
                // printf("[%d]\n", vh->arr[in].next);
            }
            if(max != out){
                temp = vh->arr[max].data;
                vh->arr[max].data = vh->arr[out].data;
                vh->arr[out].data = temp;
            }
        }
    }
}
void display(VHeap *vh, int *head){
    if(*head!=-1){
        for(int ndx=*head; ndx!=-1; ndx=vh->arr[ndx].next){
            printf("[%d]", ndx);
        }
        printf(" -NDX\n");
        for(int ndx=*head; ndx!=-1; ndx=vh->arr[ndx].next){
            printf(" %c ", vh->arr[ndx].data);
        }
        printf(" -LIST\n");
        for(int ndx=*head; ndx!=-1; ndx=vh->arr[ndx].next){
            printf("[%d]", vh->arr[ndx].next);
        }
        printf("-NEXT\n");
    }
    printf("Head: [%d] Avail: [%d]\n\n", *head, vh->avail);
}