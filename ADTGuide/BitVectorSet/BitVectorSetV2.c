#include <stdio.h>
#include "BitVectorSetV2.h"

int main(){
    printf("=====INITIALIZE SET=====\n");
    Set x;
    initialize(&x);
    displayBits(x);
    displaySet(x);
    printf("\n\n\n");



    printf("=====INSERT ELEMENT=====\n");
    insertElem(&x, -1);
    insertElem(&x, 8);
    insertElem(&x, 1);
    insertElem(&x, 7);
    insertElem(&x, 2);
    insertElem(&x, 4);
    insertElem(&x, 4);
    insertElem(&x, 6);
    displayBits(x);
    displaySet(x);
    printf("\n\n\n");



    printf("=====DELETE ELEMENT=====\n");
    deleteElem(&x, -1);
    deleteElem(&x, 8);
    deleteElem(&x, 6);
    deleteElem(&x, 6);
    deleteElem(&x, 1);
    displayBits(x);
    displaySet(x);
    printf("\n\n\n");



    printf("=====FIND ELEMENT=====\n");
    for(int i=0; i<8; i++) printf("Bit %d: [%d]\n", i+1, find(x, i));
    displayBits(x);
    displaySet(x);
    printf("\n\n\n");



    printf("=====SET UNION=====\n");
    Set y;
    x.field = 41; 
    y.field = 98;
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
}