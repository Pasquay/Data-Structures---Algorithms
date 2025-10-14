#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initialize(Stack *s);
void push(Stack *s, int x);
void pop(Stack *s);
void display(Stack s);


void initialize(Stack *s){
    s->top = 0;
}

void push(Stack *s, int x){
    if(s->top >= MAX) printf("Error: List is full.\n");
    else {
        s->data[s->top++] = x;
    }
}

void pop(Stack *s){
    if(s->top == 0) printf("Error: List is empty.\n");
    else {
        
    }
}

void display(Stack s){
    int i;
    printf("[ ");
    for(i=0; i<s.top; i++) printf("%d, ", s.data[i]);
    printf("]\n");
}