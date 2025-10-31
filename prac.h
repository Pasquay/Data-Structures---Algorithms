#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#define DICT_S 10
#define DICT_M 3
#define DICT_MAX DICT_S*DICT_M

typedef int ID;

typedef ID Dictionary[DICT_MAX];

void initDict(Dictionary d){
    for(int i=0; i<DICT_MAX; i++) d[i] = 0;
}
int hash(ID id){
    return (id%DICT_S)*DICT_M;
}
void display(Dictionary d){
    printf("\n\n=====DICTIONARY=====\n");
    printf("NDX | Students...\n");
    int count = 0;
    for(int i=0; i<DICT_S; i++){   
        int first = 0;
        for(int j=i*DICT_M; j<(i*DICT_M)+DICT_M && d[j]; j++, count++){
            if(!first) printf("%d | ", i), first=1;
            printf("[%3d] ", d[j]);
        }
        if(first) printf("\n");
    }
    printf(" Count: [%2d]\n", count);
    printf("=====DICTIONARY=====\n\n\n");
}
void insertFirst(Dictionary d, ID id){
    int ndx = hash(id), i=ndx;
    for(; i<ndx+DICT_M && d[i] && d[i]!=id; i++){}
    if(i==ndx+DICT_M) printf("E: Full [%2d]\n", (i/3)-1);
    else if(d[i]==id) printf("E: [%3d] Already Exists\n", id);
    else {
        for(i=ndx+DICT_M-1; i>ndx; i--) d[i] = d[i-1];
        d[i] = id;
        printf("S: [%3d] Insert First\n", id);
    }
}
void insertLast(Dictionary d, ID id){
    int ndx = hash(id), i;
    for(i=ndx; i<ndx+DICT_M && d[i] && d[i]!=id; i++){}
    if(i==ndx+DICT_M) printf("E: Full [%2d]\n", (i/3)-1);
    else if(d[i]==id) printf("E: [%3d] Already Exists\n", id);
    else {
        d[i] = id;
        printf("S: [%3d] Insert Last\n", id);
    }
}
void deleteFirst(Dictionary d, ID id){
    int ndx = hash(id), i;
    if(!d[ndx]) printf("E: Empty [%2d]\n", (ndx/3));
    else {
        for(i=ndx; i<ndx+DICT_M-1 && d[i+1]; i++) d[i] = d[i+1];
        d[i] = 0;
        printf("S: [%3d] Delete First\n", id);
    }
}
void deleteLast(Dictionary d, ID id){
    int ndx = hash(id), i;
    for(i=ndx+DICT_M-1; i>=ndx && !d[i]; i--){}
    if(i<ndx) printf("E: Empty [%2d]\n", (ndx/3));
    else {
        d[i] = 0;
        printf("S: [%3d] Delete Last\n", id);
    }
}
void deleteID(Dictionary d, ID id){
    int ndx = hash(id), i;
    for(i=ndx; i<ndx+DICT_M && d[i]!=id; i++){}
    if(i==ndx+DICT_M) printf("E: [%3d] Not Found\n", id);
    else {
        for(; i<ndx+DICT_M-1 && d[i+1]; i++) d[i] = d[i+1];
        d[i] = 0;
        printf("S: [%3d] Deleted ID\n", id);
    }
}
bool find(Dictionary d, ID id){
    int ndx = hash(id), i;
    for(i=ndx; i<ndx+DICT_M && d[i]!=id; i++){}
    return (i==ndx+DICT_M) ? false : true;
}









