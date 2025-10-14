#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int items[MAX];
    int top;
} Stack; 

Stack* initialize();
void display(Stack *s);
void push(Stack *s,int data);
int pop(Stack *s);
int peek(Stack *s);


/**
 * INITIALIZE LIST
 */
Stack* initialize(){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    if(s==NULL) printf("Error: Memory allocation failure.\n");
    else {
        s->top = MAX;
        printf("Success: List initialized.\n");
    }
    return s;
}


/**
 * DISPLAY LIST
 */
void display(Stack *s){
    if(s->top == MAX) printf("Error: List is empty.\nTop: [%d]\n", s->top);
    else {
        int i;
        printf("[ ");
        for(i=s->top; i<MAX; i++) printf("%d, ", s->items[i]);
        printf("]\nTop: [%d]\n", s->top);
    }
}


/**
 * PUSH ELEMENT
 */
void push(Stack *s,int data){
    if(s->top == 0) printf("Error: List is full.\n");
    else {
        s->items[--s->top] = data;
        printf("Success: %d pushed to list.\n", data);
    }
}


/**
 * POP ELEMENT
 */
int pop(Stack *s){
    if(s->top == MAX) {
        printf("Error: List is empty.\n");
        return -1;
    } else {
        printf("Success: %d popped from list.\n", s->items[s->top]);
        return s->items[s->top++];
    }
}


/**
 * PEEK ELEMENT
 */
int peek(Stack *s){
    if(s->top == MAX) {
        printf("Error: List is empty.\n");
        return -1;
    }
    else {
        printf("Success: %d peeked from list.\n", s->items[s->top]);
        return s->items[s->top];
    }
}