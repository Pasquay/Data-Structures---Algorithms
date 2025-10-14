#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"studtype.h"

typedef struct {
    VHeap *vh;
    int top;
} *Stack, StackS;

void initStack(Stack s); 
bool isEmptyS(Stack s); 
bool isFullS(Stack s); 
Studtype top(Stack s); 
int allocS(Stack s);
void deallocS(Stack s, int ndx);
void emptyS(Stack s); 
void push(Stack s, Studtype data); 
void pop(Stack s);
void pushUnique(Stack s, Studtype data); 
void popUnique(Stack s, Studtype data); 
void displayStack(Stack s); 
void displayStackTemp(Stack s); 


void initStack(Stack s){
    s->vh = malloc(sizeof(VHeap));
    int ndx;
    for(ndx=MAX-1; ndx>-1; ndx--){
        s->vh->arr[ndx].next = ndx-1;
    }
    s->vh->avail = MAX-1;
    s->top = -1;
}
bool isEmptyS(Stack s){
    return (s->vh->avail==MAX-1) ? true : false;
}
bool isFullS(Stack s){
    return (s->vh->avail==-1) ? true : false;
}
Studtype top(Stack s){
    return s->vh->arr[s->top].data;
}
void emptyS(Stack s){
    for(; !isEmptyS(s); pop(s)){}
}
int allocS(Stack s){
    int retval = s->vh->avail;
    if(retval!=-1) s->vh->avail = s->vh->arr[retval].next;
    return retval;
}
void deallocS(Stack s, int ndx){
    s->vh->arr[ndx].next = s->vh->avail;
    s->vh->avail = ndx;
}
void push(Stack s, Studtype data){
    if(!isFullS(s)){
        int temp = allocS(s);
        if(temp!=-1){
            s->vh->arr[temp].data = data;
            s->vh->arr[temp].next = s->top;
            s->top = temp;
            // printf("Success: Pushed\n");
        } //else printf("Error: Full VHeap\n");
    } //else printf("Error: Full list\n");
}
void pop(Stack s){
    if(!isEmptyS(s)){
        int temp = s->top;
        s->top =s->vh->arr[s->top].next;
        deallocS(s, temp);
    }
}
void pushUnique(Stack s, Studtype data){
    if(!isFullS(s)){
        StackS temp;
        initStack(&temp);
        for(;!isEmptyS(s) && data.ID!=top(s).ID; push(&temp, top(s)), pop(s)){}
        if(isEmptyS(s)) push(&temp, data);
        else for(;!isEmptyS(s); push(&temp, top(s)), pop(s)){}
        for(;!isEmptyS(&temp); push(s, top(&temp)), pop(&temp)){}
    }
} 
void popUnique(Stack s, Studtype data){
    if(!isEmptyS(s)){
        StackS temp;
        initStack(&temp);
        for(; !isEmptyS(s) && data.ID!=top(s).ID; push(&temp, top(s)), pop(s)){}
        if(!isEmptyS(s)) pop(s);
        for(; !isEmptyS(s); push(&temp, top(s)), pop(s)){}
        for(; !isEmptyS(&temp); push(s, top(&temp)), pop(&temp)){}
    }
}
void displayStack(Stack s){
    displayStudentHeader();
    StackS temp;
    initStack(&temp);
    for(; !isEmptyS(s); push(&temp, top(s)), pop(s)) displayStudent(top(s));
    for(; !isEmptyS(&temp); push(s, top(&temp)), pop(&temp)){}
    printf("Top: [%d]  Avail: [%d]\n", s->top, s->vh->avail);
}
void displayStackTemp(Stack s){
    displayStudentHeader();
    int ndx = s->top;
    for(; ndx!=-1; ndx=s->vh->arr[ndx].next) {
        displayStudent(s->vh->arr[ndx].data);
        // printf("\t%d ====> %d\n", ndx, s->vh->arr[ndx].next);
    }
    printf("Top: [%d]  Avail: [%d]\n", s->top, s->vh->avail);
}