/*
## Objective
Create the three functions that is necessary in decoding the message in the file decode.c

- `int* bitmaskToArray(short int word[])` - this function takes the array of integers and returns a a bit vector array
- `char* decodeString(int arr[])` - this function takes the bit vector array and returns the 8 letter string
- `void displayBitPattern(int arr[])` - this function displays the bit pattern of the bit vector array

---

## Notes
- Remember to terminate the end of the string with \0
- Bit vector array is where each index of the array represents a boolean value: 0 or 1
- Remember one character is 8 bits, given a binary 01011001 is 89 in decimal, it represents the character 'Y' 

---

## Decoding Guide
Given the short integer value 22863, it is represented in bits as 0101100101001111. Those bits are then stored in a bit vector array and then converted to represent 2 letters.

short int val = 22863

bit representation: 01011001 01001111
           letters: YO

---
*/

#include<stdio.h>
#include<stdlib.h>

int* bitmaskToArray(short int word[]);
char* decodeString(int arr[]);
void displayBitPattern(int arr[]);

// Write your functions here...
int* bitmaskToArray(short int word[]){
    int *retval = malloc(sizeof(int)*16*4);
    if(retval){
        for(int i=0; i<4; i++)
            for(int j=0, mask=1<<15; mask>0; mask>>=1, j++)
                retval[(16*i)+j] = word[i]&mask?1:0;
    }
    return retval;
}

char* decodeString(int arr[]){
    // prep retval to be an 8 char string + '\0'
    char *retval = calloc(9, sizeof(char));
    if(retval){
        for(int i=7; i>=0; i--){
            char letter = 0;
            for(int j=0; j<8; j++){
                letter = ((1<<8)-1)&
            }
        }
        // last char is '\0'
        retval[8] = '\0';
    }
    return retval;
}


void displayBitPattern(int arr[]){
    for(int i=0; i<4; i++){
        for(int j=0; j<16; j++){
            printf("%d", arr[(16*i)+j]);
        }
        printf("\n");
    }
}


/* 
 0 - 1
 1 - 2
 2 - 4
 3 - 8
 4 - 16
 5 - 32
 6 - 64
 7 - 128
 8 - 256
 9 - 512
10 - 1024
11 - 2048
12 - 4096
13 - 8192
14 - 16384
15 - 32768
*/


// int* bitmaskToArray(short int word[]){
//     int *retval = malloc(4*sizeof(int));
//     for(int i=0; i<4; i++){ 
//         retval[i] = 0|word[i];
//     }
//     return retval;
// }

// char* decodeString(int arr[]){
    
// }

// void displayBitPattern(int arr[]){
//     for(int i=0; i<4; i++){
//         for(int j=0; j<16; j++) printf("%d", arr[i][j]?1:0);
//         printf(" ");
//     }
// }