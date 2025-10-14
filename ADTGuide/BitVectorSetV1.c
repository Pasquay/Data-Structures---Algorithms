#include <stdio.h>
#include "BitVectorSetV1.h"

int main(){
    printf("=====INITIALIZE SET=====\n");
    set x;
    initialize(&x);
    displayBits(x);
    displaySet(x);
    printf("\n\n\n");



    printf("=====INSERT ELEMENT=====\n");
    // insert(&x, -1);
    // insert(&x, 8);
    insert(&x, 1);
    insert(&x, 7);
    insert(&x, 2);
    insert(&x, 4);
    insert(&x, 6);
    displayBits(x);
    displaySet(x);
    printf("\n\n\n");



    printf("=====DELETE ELEMENT=====\n");
    delete(&x, 6);
    delete(&x, 1);
    displayBits(x);
    displaySet(x);
    printf("\n\n\n");



    printf("=====FIND ELEMENT=====\n");
    for(int i=0; i<8; i++) printf("Bit %d: [%d]\n", i+1, find(x, i));
    displayBits(x);
    displaySet(x);
    printf("\n\n\n");



    printf("=====SET UNION=====\n");
    x = 41; set y = 98;
    displaySet(x);
    displaySet(y);
    displaySet(setUnion(x, y));
    displayBits(x);
    displayBits(y);
    displayBits(setUnion(x, y));
    printf("\n\n\n");


    
    printf("=====SET INTERSECTION=====\n");
    displaySet(x);
    displaySet(y);
    displaySet(setIntersection(x, y));
    displayBits(x);
    displayBits(y);
    displayBits(setIntersection(x, y));
    printf("\n\n\n");


    
    printf("=====SET DIFFERENCE=====\n");
    printf("[ X - Y ]\n");
    displaySet(x);
    displaySet(y);
    displaySet(setDifference(x, y));
    displayBits(x);
    displayBits(y);
    displayBits(setDifference(x, y));
    printf("\n[ Y - X ]\n");
    displaySet(x);
    displaySet(y);
    displaySet(setDifference(y, x));
    displayBits(x);
    displayBits(y);
    displayBits(setDifference(y, x));
    printf("\n\n\n");

    // char mask = 1<<8-1;
    displayBits(247);
    displayBits(8);
    displayBits(247|8);
    displayBits(255);
}
/*
1111 0111
0000 1000 OR
1111 1111

*/