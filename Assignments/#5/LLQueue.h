#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "studtype.h"

typedef struct {
    List front;
    List rear;
} *Queue, QueueS;

void initQueue(Queue q); //
bool isEmptyQ(Queue q); //
bool isFullQ(Queue q); //
Studtype front(Queue q); //
void enq(Queue q, Studtype data); //
void deq(Queue q); //
void enqUnique(Queue q, Studtype data); //
void deqUnique(Queue q, Studtype data); //
void emptyQ(Queue q); //
void displayQueue(Queue q); //

void initQueue(Queue q){
    q->front = NULL;
    q->rear = q->front;
}
bool isEmptyQ(Queue q){
    return q->front==NULL ? true : false;
}
bool isFullQ(Queue q){
    return false;
}
Studtype front(Queue q){
    return q->front->stud;
}
void enq(Queue q, Studtype data){
    if(!isFullQ(q)){
        List temp = (List)malloc(sizeof(Node));
        if(temp){
            temp->stud = data;
            temp->link = NULL;
            if(isEmptyQ(q)){
                q->front = temp;
            } else {
                q->rear->link = temp;
            }
            q->rear = temp;
        }
    }
}
void deq(Queue q){
    if(!isEmptyQ(q)){
        List temp = q->front;
        q->front = q->front->link;
        free(temp);
    }
}
void enqUnique(Queue q, Studtype data){
    if(!isFullQ(q)){
        Queue trav = (Queue)malloc(sizeof(QueueS));
        initQueue(trav);
        for(;!isEmptyQ(q) && data.ID!=front(q).ID; enq(trav, front(q)), deq(q)){}
        if(isEmptyQ(q)) enq(trav, data);
        for(;!isEmptyQ(trav); enq(q, front(trav)), deq(trav)){}
    }
}
void deqUnique(Queue q, Studtype data){
    if(!isEmptyQ(q)){
        Queue trav = (Queue)malloc(sizeof(QueueS));
        initQueue(trav);
        for(; !isEmptyQ(q) && data.ID!=front(q).ID; enq(trav, front(q)), deq(q)){}
        if(!isEmptyQ(q)) deq(q);
        for(; !isEmptyQ(q); enq(trav, front(q)), deq(q)){}
        for(; !isEmptyQ(trav); enq(q, front(trav)), deq(trav)){}
    }
}
void emptyQ(Queue q){
    for(; !isEmptyQ(q); deq(q)){}
}
void displayQueue(Queue q){
    displayStudentHeader();
    int count = 0;
    Queue trav = (Queue)malloc(sizeof(QueueS));
    initQueue(trav);
    for(;!isEmptyQ(q); enq(trav, front(q)), deq(q), count++) displayStudent(front(q));
    for(;!isEmptyQ(trav); enq(q, front(trav)), deq(trav)){}
    printf("Front: [%d]  Rear: [%d]\n", 0, count);
}




