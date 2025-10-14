#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int items[MAX];
    int count;
} List;

typedef struct {
    List list;
    int front;
    int rear;
} Queue;

Queue* initialize();
void display(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int isEmpty(Queue* q);
int isFull(Queue* q);
int front(Queue* q);


/**
 * INITIALIZE LIST
 */
Queue* initialize(){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    if(q == NULL) printf("Error: Memory allocation failure.\n");
    else {
        q->list.count = 0;
        q->front = 0;
        q->rear = 0;
        printf("Success: List initialized.\n");
    }
    return q;
}


/**
 * DISPLAY LIST
 */
void display(Queue* q){
    Queue l = *q;
    int i;
    printf("[ ");
    for(i=0; i!=q->list.count; i++){
        if(i==MAX) i=0;
        printf("%d, ", dequeue(&l));
    }
    printf("]\n");
    printf("Count: [%d]  Front: [%d]  Rear: [%d]\n", q->list.count, q->front, q->rear);
}


/**
 * ENQUEUE ELEMENT
 */
void enqueue(Queue* q, int value){
    if(q->list.count == MAX) printf("Error: Queue is full.\n");
    else {
        if(q->rear == MAX) q->rear = 0;
        q->list.items[q->rear++] = value;
        q->list.count++;
    }
}


/**
 * DEQUEUE ELEMENT
 */
int dequeue(Queue* q){
    if(q->list.count == 0) printf("Error: List is empty.\n");
    else {
        if(q->front == MAX) q->front = 0;
        q->list.count--;
        return q->list.items[q->front++];
    }
}


/**
 * CHECKS EMPTY/FULL
 */
int isEmpty(Queue* q){
    return (q->list.count == 0) ? 1 : 0;
}
int isFull(Queue* q){
    return (q->list.count == MAX) ? 1 : 0;
}


/**
 * RETURN FRONT ELEMENT
 */
int front(Queue* q){
    if(q->list.count == 0) printf("Error: List is empty.\n");
    Queue l = *q;
    return (q->list.count==0) ? -1 : dequeue(&l);
}
