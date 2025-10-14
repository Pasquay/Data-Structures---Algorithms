#include <stdio.h>

int main(){
    char data; STACK S; //Queue Q; VirtualHeap VH; CBList L;

    initStack(S); //Stack header file
    // initQueue(Q); //Queue header file

    pushUnique(S, data); //push if unique
    // enqueueUnique(Q, data); //enqueue if unique

    displayStack(S); 
    // displayQueue(Q);

    popUnique(S, data);
    // dequeueUnique(Q, data);


}