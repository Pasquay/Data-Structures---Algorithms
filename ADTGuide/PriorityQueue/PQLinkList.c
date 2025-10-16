#include<stdio.h>
#include"PQLinkList.h"

int main(){
    int data[10] = {22,45,50,14,8,10,35,99,98, 0};
    int prio[10] = { 1, 0, 2, 1,1, 0, 2, 4, 0,10};
    List q;
    initList(&q);
    display(q);
    // for(int i=0; i<10; i++) insertLast(&q, data[i], prio[i]);
    for(int i=0; i<10; i++) insertPrio(&q, data[i], prio[i]);
    display(q);
    // for(int i=0; i<10; i++) deleteMax(&q);
    display(q);
    for(int i=0; i<11; i++) deleteMin(&q);
    display(q);
}