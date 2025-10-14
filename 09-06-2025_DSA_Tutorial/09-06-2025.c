#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
    Stack s;
    initialize(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    display(s);
    
}