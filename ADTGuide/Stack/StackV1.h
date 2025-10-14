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
int isPalindrome(Stack *s);
int getMax(Stack *s);


/**
 * INITIALIZE LIST
 */
Stack* initialize(){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    if(s!=NULL) {
        s->top = -1;
        // printf("Success: List initialized.\n");
    } else {
        printf("Error: Memory allocation failure.\n");
    }
    return s;
}


/**
 * DISPLAY LIST
 */
void display(Stack *s){
    int i;
    printf("Top:[%d][ ", s->top);
    for(i=s->top; i>-1; i--) printf("%d, ", s->items[i]);
    printf("]\n");
}


/**
 * PUSH ELEMENT
 */
void push(Stack *s,int data){
    if(s->top == MAX-1) printf("Error: List is full.\n");
    else {
        s->items[++s->top] = data;
        // printf("Success: %d pushed to top.\n", data);
    }
}


/**
 * POP ELEMENT
 */
int pop(Stack *s){
    if(s->top == -1) printf("Error: List is empty.\n");
    else {
        // printf("Success: %d popped from list.\n", s->items[s->top]);
        return s->items[s->top--];
    }
    return -1;
}


/**
 * PEEK ELEMENT
 */
int peek(Stack *s){
    if(s->top == -1) {
        printf("Error: List is empty.\n");
        return -1;
    } else {
        // printf("Success: [%d] Peeked from list.\n", s->items[s->top]);
        return s->items[s->top];
    }
}


/**
 * CHECKS IF LIST IS PALINDROME
 */
int isPalindrome(Stack *s){
    Stack *temp = initialize();
    Stack *first = initialize();
    Stack *second = initialize();

    int half = s->top/2, palindrome = 1;
    for(s->top; s->top>half; push(temp, pop(s))){}
    for(temp->top; temp->top > -1 && palindrome == 1; push(second, pop(s)), push(first, pop(temp))){
        if(peek(s)!=peek(temp)) palindrome = 0;
    }

    // display(s);
    // display(temp);
    // display(second);
    
    for(second->top; second->top > -1; push(s, pop(second))){}
    for(first->top; first->top > -1; push(second, pop(first))){}
    for(second->top; second->top > -1; push(s, pop(second))){}
    
    // printf("Success: List palindrome status checked.\n");
    
    return palindrome;
}


/**
 * FIND MAX ELEMENT
 */
int getMax(Stack *s){
    int max = s->items[s->top];
    Stack *temp = initialize();
    for(s->top; s->top > -1; push(temp, pop(s))){
        if(max < s->items[s->top]) max = s->items[s->top];
    }
    for(temp->top; temp->top > -1; push(s, pop(temp))){}
    return max;
}
