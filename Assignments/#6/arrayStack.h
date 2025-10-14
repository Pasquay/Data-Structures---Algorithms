#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define STACK_MAX 5
#define STR_MAX 50

typedef struct {
    int container[STACK_MAX];
    int top;
} Stack;

void initialize(Stack *s){
    s->top = -1;
}
bool isFull(Stack *s){
    return s->top==STACK_MAX-1 ? true : false;
}
bool isEmpty(Stack *s){
    return s->top==-1 ? true : false;
}
void push(Stack *s, int value){
    if(!isFull(s)) s->container[++s->top] = value;
}
int pop(Stack *s){
    return isEmpty(s) ? -1 : s->container[s->top--];
}
int top(Stack *s){
    return s->container[s->top];
}
void display(Stack* s){
    Stack d = *s;
    printf("Stack: ");
    for(; !isEmpty(&d); printf("%d ", pop(&d))){}
    printf("\nTop: [%d]\n", s->top);
}
