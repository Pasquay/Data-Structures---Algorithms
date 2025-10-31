#include<stdio.h>
#include<stdlib.h>

int* bitmaskToArray(short int word[]);
char* decodeString(int arr[]);
void displayBitPattern(int arr[]);

// Write your functions here...

int* bitmaskToArray(short int word[]){
    int *retval = malloc(4*sizeof(int));
    for(int i=0; i<4; i++){ 
        retval[i] = 0|word[i];
    }
    return retval;
}

char* decodeString(int arr[]){
    
}

void displayBitPattern(int arr[]){
    for(int i=0; i<4; i++){
        // for(int j=0; j<16; j++) printf("%d", arr[i][j]?1:0);
        printf(" ");
    }
}