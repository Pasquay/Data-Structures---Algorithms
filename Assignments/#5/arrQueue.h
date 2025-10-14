#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "studtype.h"

typedef struct {
    Studtype studlist[MAX];
    int front;
    int rear;
} *Queue, QueueS;

void initQueue(Queue q); //
bool isEmptyQ(Queue q); //
bool isFullQ(Queue q); //
Studtype front(Queue q); //
void emptyQ(Queue q); //
void enq(Queue q, Studtype data); //
void deq(Queue q); //
void enqUnique(Queue q, Studtype data); //
void deqUnique(Queue q, Studtype data); //
void displayQueue(Queue q); //


void initQueue(Queue q){
    q->front=1;
    q->rear=0;
}
bool isEmptyQ(Queue q){
    return (q->rear+1)%MAX==q->front ? true : false;
}
bool isFullQ(Queue q){
    return (q->rear+2)%MAX==q->front ? true : false;
}
Studtype front(Queue q){
    return q->studlist[q->front];
}
void emptyQ(Queue q){
    q->front=1;
    q->rear=0;
}
void enq(Queue q, Studtype data){
    if(!isFullQ(q)){
        q->rear = (q->rear+1)%MAX;
        q->studlist[q->rear] = data;
    }
}
void deq(Queue q){
    if(!isEmptyQ(q)) q->front = (q->front+1)%MAX;
}
void enqUnique(Queue q, Studtype data){
    if(!isFullQ(q)){
        QueueS x = *q;
        for(;!isEmptyQ(&x) && data.ID!=front(&x).ID; deq(&x)){}
        if(isEmptyQ(&x)) enq(q, data);
    }
}
void deqUnique(Queue q, Studtype data){
    if(!isEmptyQ(q)){
        QueueS x;
        initQueue(&x);
        for(; !isEmptyQ(q) && data.ID!=front(q).ID; enq(&x, front(q)), deq(q)){}
        if(!isEmptyQ(q)) deq(q);
        // for(; !isEmptyQ(&x); enq(q, front(&x)), deq(&x)){}
        for(; !isEmptyQ(q); enq(&x, front(q)), deq(q)){}
        *q = x;
    }
}
void displayQueue(Queue q){
    QueueS x = *q;
    displayStudentHeader();
    for(;!isEmptyQ(&x); deq(&x)) displayStudent(front(&x));
    printf("Front: [%d] Rear: [%d]\n", q->front, q->rear);
}








