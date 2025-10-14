#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

Queue* initialize();
void tempDisplay(Queue* q);
void display(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int isEmpty(Queue* q);
int isFull(Queue* q);
int front(Queue* q);
int isPalindrome(Queue* q);


/**
 * INITIALIZE LIST
 */
Queue* initialize(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if(q!=NULL) q->front=1, q->rear=0;
    return q;
}


/**
 * DISPLAY LIST
 */
void display(Queue* q){
    Queue l = *q;
    printf("[");
    for(l; (l.rear+1)%MAX!=l.front;) printf("%d, ", dequeue(&l));
    printf("]\nF: [%d]  R: [%d]\n", q->front, q->rear);
}
void tempDisplay(Queue *q){
    printf("[ ");
    for(int i=q->front; i!=(q->rear+1)%MAX; i=(i+1)%MAX) printf("%d, ", q->items[i]);
    printf("]\nF: [%d]   R: [%d]\n", q->front, q->rear);
}



/**
 * ENQUEUE ELEMENT
 */
void enqueue(Queue* q, int value){
    if((q->rear+2)%MAX!=q->front){
        q->rear=(q->rear+1)%MAX;
        q->items[q->rear]=value;
    } else printf("Error: Full\n");
}


/**
 * DEQUEUE ELEMENT
 */
int dequeue(Queue* q){
    int retval;
    if((q->rear+1)%MAX==q->front) retval=-1;
    else {
        retval=q->items[q->front];
        q->front=(q->front+1)%MAX;
    }
    return retval;
}


/**
 * CHECKS EMPTY/FULL
 */
int isEmpty(Queue* q){
    return (q->rear+1)%MAX==q->front ? 1 : 0;
}
int isFull(Queue* q){
    return (q->rear+2)%MAX==q->front ? 1 : 0;
}


/**
 * RETURN FRONT ELEMENT
 */
int front(Queue* q){
    return q->items[q->front];
}



/**
 * EXPERIMENT!
 */
int isPalindrome(Queue* q){
    Queue x = *q, y, z;
    for(y.front=1, y.rear=0; 
        y.rear<(x.rear-x.front+(MAX+1))%MAX+1;
        enqueue(&y, dequeue(&x))
    ){}
    display(&x);
    display(&y);
}
