#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
    VHeap *vh;
    int front;
    int rear;
} *Queue, QueueS;

void initQueue(Queue q); 
bool isEmptyQ(Queue q); 
bool isFullQ(Queue q); 
Studtype front(Queue q); 
int allocQ(Queue q);
void deallocQ(Queue q, int ndx);
void enq(Queue q, Studtype data); 
void deq(Queue q); 
void enqUnique(Queue q, Studtype data); 
void deqUnique(Queue q, Studtype data); 
void emptyQ(Queue q); 
void displayQueue(Queue q); 
void displayQueueTemp(Queue q);

void initQueue(Queue q){
    q->vh = malloc(sizeof(VHeap));
    int ndx = MAX-1;
    for(; ndx>-1; ndx--){
        q->vh->arr[ndx].next = ndx-1;
    }
    q->vh->avail = MAX-1;
    q->rear = q->front = -1;
}
bool isEmptyQ(Queue q){
    return (q->front==-1) ? true : false;
}
bool isFullQ(Queue q){
    return (q->vh->avail==-1) ? true : false;
}
Studtype front(Queue q){
    return q->vh->arr[q->front].data;
}
int allocQ(Queue q){
    int retval = q->vh->avail;
    if(retval!=-1) q->vh->avail = q->vh->arr[retval].next;
    return retval;
}
void deallocQ(Queue q, int ndx){
    q->vh->arr[ndx].next = q->vh->avail;
    q->vh->avail = ndx;
}
void enq(Queue q, Studtype data){
    if(!isFullQ(q)){
        int temp = allocQ(q);
        if(temp!=-1){
            q->vh->arr[temp].data = data;
            q->vh->arr[temp].next = -1;
            if(isEmptyQ(q)) q->front = temp;
            else q->vh->arr[q->rear].next = temp;
            q->rear = temp; 
        }
    }
}
void deq(Queue q){
    if(!isEmptyQ(q)){
        int temp = q->front;
        q->front = q->vh->arr[q->front].next;
        deallocQ(q, temp);
    }
}
void enqUnique(Queue q, Studtype data){
    if(!isFullQ(q)){
        QueueS temp;
        initQueue(&temp);
        for(;!isEmptyQ(q) && data.ID!=front(q).ID; enq(&temp, front(q)), deq(q)){}
        if(isEmptyQ(q)) enq(&temp, data);
        for(;!isEmptyQ(q); enq(&temp, front(q)), deq(q)){}
        for(;!isEmptyQ(&temp); enq(q, front(&temp)), deq(&temp)){}
    }
}
void deqUnique(Queue q, Studtype data){
    if(!isEmptyQ(q)){
        QueueS temp;
        initQueue(&temp);
        for(; !isEmptyQ(q) && data.ID!=front(q).ID; enq(&temp, front(q)), deq(q)){}
        if(!isEmptyQ(q)) deq(q);
        for(; !isEmptyQ(q); enq(&temp, front(q)), deq(q)){}
        for(; !isEmptyQ(&temp); enq(q, front(&temp)), deq(&temp)){}
    }
}
void emptyQ(Queue q){
    for(; !isEmptyQ(q); deq(q)){}
}
void displayQueue(Queue q){
    displayStudentHeader();
    QueueS temp;
    initQueue(&temp);
    for(;!isEmptyQ(q); enq(&temp, front(q)), deq(q)) displayStudent(front(q));
    for(;!isEmptyQ(&temp); enq(q, front(&temp)), deq(&temp)){}
    printf("Front: [%d]  Rear: [%d]  Avail: [%d]\n", q->front, q->rear, q->vh->avail);
}
void displayQueueTemp(Queue q){
    displayStudentHeader();
    int ndx = q->front;
    for(; ndx!=-1; ndx=q->vh->arr[ndx].next) displayStudent(q->vh->arr[ndx].data);
    printf("Front: [%d]  Rear: [%d]  Avail: [%d]\n", q->front, q->rear, q->vh->avail);
}








 