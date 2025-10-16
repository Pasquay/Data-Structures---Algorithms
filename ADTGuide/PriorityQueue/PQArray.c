#include<stdio.h>
#include<stdbool.h>
#include"PQArray.h"

int main(){
    int data[10] = {22,45,50,14,8,10,35,99,98};
    int prio[10] = { 1, 0, 2, 1,1, 0, 2, 4, 0};
    Queue q;
    initQueue(&q);
    display(q);
    // for(int i=0; i<7; i++) enqueue(&q, data[i], prio[i]);
    for(int i=0; i<10; i++) enqueuePrio(&q, data[i], prio[i]);
    display(q);
    display(q);
}
