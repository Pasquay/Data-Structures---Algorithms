#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "studtype.h"

typedef struct {
    List top;
} *Stack, StackS;

void initStack(Stack s); //
bool isEmptyS(Stack s); //
bool isFullS(Stack s); //
Studtype top(Stack s); //
void push(Stack s, Studtype data); //
void pop(Stack s); //
void pushUnique(Stack s, Studtype data); //
void popUnique(Stack s, Studtype data); //
void emptyS(Stack s); //
void displayStack(Stack s); //

void initStack(Stack s){
    s->top = NULL;
}
bool isEmptyS(Stack s){
    return (s->top==NULL) ? true : false;
}
bool isFullS(Stack s){
    return false;
}
Studtype top(Stack s){
    return s->top->stud;
}
void push(Stack s, Studtype data){
    if(!isFullS(s)){
        List elem = (List)malloc(sizeof(Node));
        if(elem){
            elem->stud = data;
            elem->link = s->top;
            s->top = elem;
        }
    }
}
void pop(Stack s){
    if(!isEmptyS(s)){
        List temp = s->top;
        s->top = s->top->link;
        free(temp);
    }
}
void pushUnique(Stack s, Studtype data){
    if(!isFullS(s)){
        StackS x; initStack(&x);
        for(;!isEmptyS(s) && data.ID!=top(s).ID; push(&x, top(s)), pop(s)){}
        if(isEmptyS(s)) push(&x, data);
        else for(;!isEmptyS(s); push(&x, top(s)), pop(s)){}
        // *s = x;
        for(;!isEmptyS(&x); push(s, top(&x)), pop(&x)){}
    }
}
void popUnique(Stack s, Studtype data){
    if(!isEmptyS(s)){
        StackS x;
        initStack(&x);
        for(; !isEmptyS(s) && data.ID!=top(s).ID; push(&x, top(s)), pop(s)){}
        if(!isEmptyS(s)) pop(s);
        for(; !isEmptyS(s); push(&x, top(s)), pop(s)){}
        for(; !isEmptyS(&x); push(s, top(&x)), pop(&x)){}
    }
}
void emptyS(Stack s){
    for(;!isEmptyS(s); pop(s)){}
}
void displayStack(Stack s){
    displayStudentHeader();
    int count=-1;
    Stack x = (Stack)malloc(sizeof(StackS)); 
    initStack(x);
    for(; !isEmptyS(s); push(x, top(s)), pop(s), count++) displayStudent(top(s));
    for(; !isEmptyS(x); push(s, top(x)), pop(x)){}
    printf("Top: [%d]\n", count);
}