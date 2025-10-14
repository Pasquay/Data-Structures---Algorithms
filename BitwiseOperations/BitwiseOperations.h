#include<stdio.h>
#include<stdlib.h>

void displayBits(short int x);
int count1s(short int x);
void swapXOR(short int *x, short int *y);
void swapBits(short int *x, int pos1, int pos2);


void displayBits(short int x){
    int mask=1<<sizeof(x)*8-1, gap=1;
    for(; mask>0; mask>>=1, gap++){
        printf("%d", x&mask?1:0);
        if(gap%4==0) printf(" ");
    }
    printf("\n");
}
int count1s(short int x){
    int retval = 0, mask;
    for(mask=1<<sizeof(x)*8-1; mask>0; mask>>=1) if(x&mask) retval++;
    return retval;
}
void swapXOR(short int *x, short int *y){
    /**
     * 5 - 0101, 3 - 0011
     * 5 = 5^3 = 0110
     * 3 = 5^3 = 0101
     * 5 = 5^3 = 0011
     */
    *x = *x^*y;
    *y = *x^*y;
    *x = *x^*y;
}
void swapBits(short int *x, int pos1, int pos2){
    int mask1=1<<pos1, mask2=1<<pos2;
    int bit1 = *x&mask1?1:0;
    int bit2 = *x&mask2?1:0;

    *x = *x&~mask1;
    *x = *x&~mask2;

    if(bit2) *x = *x|mask1;
    if(bit1) *x = *x|mask2;
}
