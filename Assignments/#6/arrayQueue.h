#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_CUSTOMER 10

typedef struct {
    int customer[MAX_CUSTOMER];
    int front;
    int rear;
} Queue;

Queue* initialize(){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    if(q){
        q->front = 1;
        q->rear = 0;
    }
    return q;
}
bool isFull(Queue* q){
    return (q->rear+2)%MAX_CUSTOMER==q->front ? true : false;
}
bool isEmpty(Queue* q){
    return (q->rear+1)%MAX_CUSTOMER==q->front ? true : false;
}
void enqueue(Queue* q, int value){
    if(!isFull(q)){
        q->rear = (q->rear+1)%MAX_CUSTOMER;
        q->customer[q->rear] = value;
    }
}
int dequeue(Queue* q){
    int retval = -1;
    if(!isEmpty(q)){
        retval = q->customer[q->front];
        q->front = (q->front+1)%MAX_CUSTOMER;
    }
    return retval;
}
void display(Queue* q){
    printf("List: ");
    Queue r = *q;
    for(; !isEmpty(&r); printf("%d ", dequeue(&r))){}
    printf("\nFront: [%d] Rear: [%d]\n", q->front, q->rear);
}