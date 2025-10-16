#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 10

typedef struct {
    int data;
    int prio;
} Node;

typedef struct {
    Node* data[MAX];
    int front;
    int rear;
} Queue;

// enqueue(): This function is used to insert new 
//            data into the queue sorted by prio (desc).
// dequeue(): This function removes the element with 
//            the highest priority from the queue.
// peek()/top(): This function is used to get the 
//               highest priority element in the queue 
//               without removing it from the queue.

bool isEmpty(Queue q){
    return ((q.rear+1)%MAX)==q.front ? true:false;
}

bool isFull(Queue q){
    return ((q.rear+2)%MAX)==q.front ? true:false;
}

Node front(Queue q){
    return *q.data[q.front];
}

void initQueue(Queue *q){
    q->front = 1;
    q->rear = 0;
}

Node dequeue(Queue *q){
    Node retval = {-1,-1};
    if(((q->rear+1)%MAX)!=q->front){
        retval = *q->data[q->front];
        q->front = (q->front+1)%MAX;
    }
    return retval;
}

void enqueue(Queue *q, int data, int prio){
    if(isFull(*q)) printf("Error: Full\n");
    else {
        Node *elem = malloc(sizeof(Node));
        if(!elem) printf("Error: Memory Failure\n");
        else {
            *elem = (Node){data,prio};
            q->rear = (q->rear+1)%MAX;
            q->data[q->rear] = elem;
            // printf("Success: Enqueue\n");
        }
    }
}

void enqueuePrio(Queue *q, int data, int prio){
    if(isFull(*q)) printf("Error: Full\n");
    else {
        Queue temp; initQueue(&temp);
        while(!isEmpty(*q) && prio<=front(*q).prio){
            Node node = dequeue(q);
            enqueue(&temp, node.data, node.prio);
        }
        enqueue(&temp, data, prio);
        while(!isEmpty(*q)){
            Node node = dequeue(q);
            enqueue(&temp, node.data, node.prio);
        }
        while(!isEmpty(temp)){
            Node node = dequeue(&temp);
            enqueue(q, node.data, node.prio);
        }
    }
}

void display(Queue q){
    printf("=======QUEUE=======\n");
    printf(" [NDX][DATA][PRIO]\n");
    int i=1; Node node;
    for(Queue temp=q; !isEmpty(temp); i++){
        node = dequeue(&temp);
        printf(" [%3d][%4d][%4d]\n", 
            temp.front, node.data, node.prio);
    }
    printf("Count: [%2d]\n", i);
    printf("===================\n");
}