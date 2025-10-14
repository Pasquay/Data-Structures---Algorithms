#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"arrayQueue.h"

void enterQueue(Queue *regular, Queue *priority);
void leaveQueue(Queue *regular, Queue *priority);

int queueNum = 1;

int main(){
    // TASK 1: Write the code to declare and initialize the two queues
    Queue *regular = initialize(), *priority = initialize();
    printf("Regular ");
    display(regular);
    printf("Priority ");
    display(priority);
    printf("\n\n");

    // TASK 2: Write the code for entering the regular queue
    enterQueue(regular, priority);
    printf("Regular ");
    display(regular);
    printf("Priority ");
    display(priority);
    printf("\n\n");

    
    // TASK 3: Write the code for entering the priority queue
    enterQueue(regular, priority);
    enterQueue(regular, priority);
    enterQueue(regular, priority);
    enterQueue(regular, priority);
    printf("Regular ");
    display(regular);
    printf("Priority ");
    display(priority);
    printf("\n\n");
    
    // TASK 4: Write the code for calling the next customer
    leaveQueue(regular, priority);
    leaveQueue(regular, priority);
    leaveQueue(regular, priority);
    printf("Regular ");
    display(regular);
    printf("Priority ");
    display(priority);
    printf("\n\n");
}

void enterQueue(Queue *regular, Queue *priority){
    int input = 0;
    while(input!=1 && input!=2){
        printf("Regular/Priority [1/2]: "); scanf("%d", &input);
    }
    if(input==2) enqueue(priority, queueNum++);
    else enqueue(regular, queueNum++);
}
void leaveQueue(Queue *regular, Queue *priority){
    if(!isEmpty(priority)) dequeue(priority);
    else if(!isEmpty(regular)) dequeue(regular);
}
