#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "studtype.h"

typedef struct {
    Studtype studlist[MAX];
    int top;
} *Stack, StackS;

void initStack(Stack s); //
bool isEmptyS(Stack s); //
bool isFullS(Stack s); //
Studtype top(Stack s); //
void emptyS(Stack s); //
void push(Stack s, Studtype data); //
void pop(Stack s); //
void pushUnique(Stack s, Studtype data); //
void popUnique(Stack s, Studtype data); //
void displayStack(Stack s); //

void initStack(Stack s){
    s->top = -1;
}
bool isEmptyS(Stack s){
    return s->top==-1? true : false;
}
bool isFullS(Stack s){
    return s->top==MAX-1? true : false;
}
Studtype top(Stack s){
    return s->studlist[s->top];
}
void push(Stack s, Studtype data){
    if(!isFullS(s)) s->studlist[++s->top] = data;
}
void pop(Stack s){
    if(!isEmptyS(s)) s->top--;
}
void  emptyS(Stack s){
    s->top=-1;
}
void pushUnique(Stack s, Studtype data){
    if(!isFullS(s)){
        StackS x = *s;
        for(;!isEmptyS(&x) && data.ID!=top(&x).ID; pop(&x)){}
        if(isEmptyS(&x)) push(s, data);
    }
}
void popUnique(Stack s, Studtype data){
    if(!isEmptyS(s)){
        Stack x = malloc(sizeof(StackS));
        initStack(x);
        for(;!isEmptyS(s) && data.ID!=top(s).ID; pop(s)) push(x, top(s));
        if(!isEmptyS(s)) pop(s);
        for(;!isEmptyS(x); pop(x)) push(s, top(x));
    }
}
void displayStack(Stack s){
    StackS x = *s;
    displayStudentHeader();
    for(; !isEmptyS(&x); x.top--) displayStudent(top(&x));
    printf("Top: [%d]\n", s->top);
}







