#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define STR_MAX 32
#define DICT_SIZE 64
#define BUCKET_SIZE 2
#define DICT_MAX DICT_SIZE*BUCKET_SIZE

typedef struct {
    char name[STR_MAX];
    int rgb[3];
} Color;

typedef Color Dictionary[DICT_MAX];
 
void initDict(Dictionary d){
    for(int i=0; i<DICT_MAX; i++) d[i] = (Color){"",{-1,-1,-1}};
}
int hash(Color x){
    return ((x.rgb[0]*5)+(x.rgb[1]*7)+(x.rgb[2]*13))%DICT_SIZE; 
}
void displayColor(Color x){
    printf("%-15s: RGB(%3d, %3d, %3d)\n", 
           x.name, 
           x.rgb[0], 
           x.rgb[1], 
           x.rgb[2]);
}
void displayDict(Dictionary d){
    printf("================== DICTIONARY ==================\n");
    int count=0;
    for(int i=0; i<DICT_SIZE; i++){
        int displayed = 0;
        for(int j=0; j<BUCKET_SIZE; j++){
            if(strcmp(d[i*2+j].name, "")){
                if(!displayed) printf("[%-2d][%c] ", i, j?'B':'A'), displayed=1;
                else printf("    [%c] ", j?'B':'A');
                displayColor(d[i*2+j]);
                count++;
            }
        }
    }
    printf("Colors in Pallete: [%d]\n", count);
    printf("================================================\n");
}
void insertFirst(Dictionary d, Color elem){
    int ndx = hash(elem)*BUCKET_SIZE;
    if(!strcmp(d[ndx].name, "")){
        d[ndx] = elem;
        printf("Success: Insert First\n");
    } else if (strcmp(d[ndx].name, "") && !strcmp(d[ndx+1].name, "")){
        d[ndx+1] = d[ndx];
        d[ndx] = elem;
        printf("Success: Insert First\n");
    } else {
        printf("Error: Bucket Full\n");
    }
}
void insertLast(Dictionary d, Color elem){
    int ndx = hash(elem)*BUCKET_SIZE;
    if(!strcmp(d[ndx+1].name, "")){
        d[ndx+1] = elem;
        printf("Success: Insert Last\n");
    } else if(!strcmp(d[ndx].name, "") && strcmp(d[ndx+1].name, "")){
        d[ndx] = d[ndx+1];
        d[ndx+1] = elem;
        printf("Success: Insert Last\n");
    } else {
        printf("Error: Bucket Full\n");
    }
}
void deleteFirst(Dictionary d, Color elem){
    int ndx = hash(elem)*2;
    if(strcmp(d[ndx].name, "")){
        d[ndx] = (Color){"", {-1,-1,-1}};
        printf("Success: Delete First\n");
    } else {
        printf("Error: First is Empty\n");
    }
}
void deleteLast(Dictionary d, Color elem){
    int ndx = hash(elem)*2;
    if(strcmp(d[ndx+1].name, "")){
        d[ndx+1] = (Color){"",{-1,-1,-1}};
        printf("Success: Delete Last\n");
    } else {
        printf("Error: Last is Empty\n");
    }
}
Color searchColor(Dictionary d, Color elem){
    Color retval = (Color){"",{-1,-1,-1}};
    int ndx = hash(elem)*2, j;
    for(j=0; j<2 && (
        strcmp(d[ndx+j].name, elem.name) ||
        d[ndx+j].rgb[0] != elem.rgb[0] ||
        d[ndx+j].rgb[1] != elem.rgb[1] ||
        d[ndx+j].rgb[2] != elem.rgb[2]
    ); j++){}
    if(j<2) retval = d[ndx+j];
    return retval;
}
Color searchViaString(Dictionary d, char str[]){
    Color retval = (Color){"",{-1,-1,-1}};
    int i=0;
    for(; i<DICT_MAX && strcmp(d[i].name, str); i++){}
    if(i<DICT_MAX) retval = d[i];
    return retval;
}
Color searchViaRGB(Dictionary d, int rgb[]){
    Color retval = (Color){"",{-1,-1,-1}};
    int ndx = ((rgb[0]*5)+(rgb[1]*7)+(rgb[2]*13))%DICT_SIZE, j;
    for(j=0; j<2 && (
        d[ndx+j].rgb[0] != rgb[0] ||
        d[ndx+j].rgb[1] != rgb[1] ||
        d[ndx+j].rgb[2] != rgb[2]
    ); j++){}
    if(j<2) retval = d[ndx+j];
    return retval;
}









