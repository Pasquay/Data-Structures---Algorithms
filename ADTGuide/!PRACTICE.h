#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    char items[MAX];
    int front;
    int rear;
} List;

List* initialize();
void tempDisplay(List* q);
void display(List* q);
void enqueue(List* q, char x);
char dequeue(List* q);
int isFull(List* q);
int isEmpty(List* q);


List* initialize(){
    List* q = (List*)malloc(sizeof(List));
    if(q!=NULL) q->front=1, q->rear=0;
    return q;
}
void tempDisplay(List* q){
    printf("[ ");
    for(int i=q->front; i!=(q->rear+1)%MAX; i=(i+1)%MAX) printf("%c ", q->items[i]);
    printf("]\nF:[%d]  R:[%d]\n", q->front, q->rear);
}
void display(List* q){
    printf("[ ");
    for(List x=*q; !isEmpty(&x); printf("%c ", dequeue(&x))){}
    printf("]\nF:[%d]  R:[%d]\n", q->front, q->rear);
}
void enqueue(List* q, char x){
    if(!isFull(q)){
        q->rear=(q->rear+1)%MAX;
        q->items[q->rear]=x;
    }
}
char dequeue(List* q){
    char retval = '\0';
    if(!isEmpty(q)){
        retval=q->items[q->front];
        q->front=(q->front+1)%MAX;
    }
    return retval;
}
int isFull(List* q){
    return ((q->rear+2)%MAX==q->front) ? 1 : 0;
}
int isEmpty(List* q){
    return ((q->rear+1)%MAX==q->front) ? 1 : 0;
}
