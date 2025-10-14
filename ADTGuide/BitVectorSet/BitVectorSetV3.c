#include <stdio.h>
#include "BitVectorSetV3.h"

int main(){
    printf("=====INITIALIZE SET=====\n");
    Set x;
    initialize(x);
    displayBits(x);
    displaySet(x);
    printf("\n\n\n");



    printf("=====INSERT ELEMENT=====\n");
    insertElem(x, -1);
    insertElem(x, 8);
    insertElem(x, 1);
    insertElem(x, 7);
    insertElem(x, 2);
    insertElem(x, 4);
    insertElem(x, 4);
    insertElem(x, 6);
    displayBits(x);
    displaySet(x);
    printf("\n\n\n");



    printf("=====DELETE ELEMENT=====\n");
    deleteElem(x, -1);
    deleteElem(x, 8);
    deleteElem(x, 6);
    deleteElem(x, 6);
    deleteElem(x, 1);
    displayBits(x);
    displaySet(x);
    printf("\n\n\n");



    printf("=====FIND ELEMENT=====\n");
    for(int i=0; i<8; i++) printf("Bit %d: [%d]\n", i+1, find(x, i));
    displayBits(x);
    displaySet(x);
    printf("\n\n\n");



    printf("=====SET UNION=====\n");
    Set y = {0,0,1,1,0,1,1,0}, result;

    printf("Set X: ");
    displaySet(x);
    printf("Set Y: ");
    displaySet(y);
    
    setUnion(x, y, result);
    printf("Union: ");
    displaySet(result);

    printf("Set X: ");
    displayBits(x);
    printf("Set Y: ");
    displayBits(y);
    printf("Union: ");
    displayBits(result);
    printf("\n\n\n");


    
    printf("=====SET INTERSECTION=====\n");
    printf("Set X: ");
    displaySet(x);
    printf("Set Y: ");
    displaySet(y);
    
    setIntersection(x, y, result);
    printf("Intersection: ");
    displaySet(result);
    
    printf("Set X: ");
    displayBits(x);
    printf("Set Y: ");
    displayBits(y);
    printf("Intersection: ");
    displayBits(result);
    printf("\n\n\n");


    
    printf("=====SET DIFFERENCE=====\n");
    printf("[ X - Y ]\n");
    printf("Set X: ");
    displaySet(x);
    printf("Set Y: ");
    displaySet(y);
    
    setDifference(x, y, result);
    printf("X - Y: ");
    displaySet(result);
    
    printf("Set X: ");
    displayBits(x);
    printf("Set Y: ");
    displayBits(y);
    printf("X - Y: ");
    displayBits(result);
    
    printf("\n[ Y - X ]\n");
    printf("Set X: ");
    displaySet(x);
    printf("Set Y: ");
    displaySet(y);
    
    setDifference(y, x, result);
    printf("Y - X: ");
    displaySet(result);
    printf("Set X: ");
    displayBits(x);
    printf("Set Y: ");
    displayBits(y);
    printf("Y - X: ");
    displayBits(result);
    printf("\n\n\n");
}