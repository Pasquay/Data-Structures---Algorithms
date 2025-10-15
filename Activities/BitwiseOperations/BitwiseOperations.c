#include<stdio.h>
#include<stdlib.h>
#include"BitwiseOperations.h"

/**
 * | - OR
 * & - AND
 * ^ - XOR
 * << - LEFT SHIFT
 * >> - RIGHT SHIFT
 * ~ - NOT
 */

int main(){
    short int x=27, y=14;
    printf("27    : ");
    displayBits(x);
    printf("14    : ");
    displayBits(y);
    printf("\n");
    printf("OR  %d: ", x|y);
    displayBits(x|y);
    printf("AND %d: ", x&y);
    displayBits(x&y);
    printf("XOR %d: ", x^y);
    displayBits(x^y);
    printf("NOT 27: ");
    displayBits(~x);
    printf("NOT 14: ");
    displayBits(~y);
    printf("NOT 27 = [%d] NOT 14 = [%d]\n", ~x, ~y);
    printf("\n\n\n");


    short int data1[5] = {9, 124, 522, 18, 92};
    for(int i=0; i<5; i++) {
        printf("Elem %d: %d\n", i+1, count1s(data1[i]));
        displayBits(data1[i]);
    }
    printf("\n\n\n");
    

    short int data2[2] = {29375, 30282};
    for(int i=0; i<2; i++) {
        printf("%d\t: ", data2[i]);
        displayBits(data2[i]);
    }
    printf("=============SWAP=============\n");
    swapXOR(&data2[0], &data2[1]);
    for(int i=0; i<2; i++) {
        printf("%d\t: ", data2[i]);
        displayBits(data2[i]);
    }
    printf("\n\n\n");


    short int data3 = 19;
    printf("%d\t: ", data3);
    displayBits(data3);
    swapBits(&data3, 3, 0);
    printf("%d\t: ", data3);
    displayBits(data3);
}