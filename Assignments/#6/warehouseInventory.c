#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"arrayStack.h"

void pushToStack(Stack s[], int value);
void popFromStack(Stack s[]);

int main(){
    Stack s[3];

    // TASK 1: Write the code to create and initialize the three stacks
    for(int i=0; i<3; i++) initialize(&s[i]);

    // TASK 2: Write the code for adding a container to the next available stack
    for(int i=0; i<15; i++) pushToStack(s, i);
    for(int i=0; i<3; i++){
        printf("%d ", i+1); 
        display(&s[i]);
    }
    printf("\n\n");

    // TASK 3: Write the code for removing a container from the latest stack
    for(int i=0; i<6; i++) popFromStack(s);
    printf("\n");
    for(int i=0; i<3; i++){
        printf("%d ", i+1); 
        display(&s[i]);
    }
    printf("\n\n");
    
    // TASK 4: Write the code for checking if a container exists
    for(int i=0; i<3; i++) printf("Container %d exists? [%s]\n", i+1, !isEmpty(&s[i])?"YES":"NO");
}

void pushToStack(Stack s[], int value){
    int i;
    for(i=0; i<3 && isFull(&s[i]); i++){}
    if(i<3) push(&s[i], value);
}
void popFromStack(Stack s[]){
    int i;
    for(i=2; i>-1 && isEmpty(&s[i]); i--){}
    if(i>-1) printf("Popped: [%d]\n", pop(&s[i]));
}
