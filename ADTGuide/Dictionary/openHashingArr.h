#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define STR_MAX 32
#define DICT_MAX 64

typedef struct {
    char name[STR_MAX];
    int rgb[3];
} Color;

typedef struct {
    Color *data;
    int size;
    int capacity;
} Node, *List;

typedef List Dictionary[DICT_MAX];

void initDict(Dictionary d){
    for(int i=0; i<DICT_MAX; i++){
        d[i] = malloc(sizeof(Node));
        if(d[i]){
            d[i]->data = malloc(sizeof(Color)*1);
            if(d[i]->data) d[i]->data[0] = (Color){"", {-1,-1,-1}};
            d[i]->size = 0;
            d[i]->capacity = 1;
        }
    }
}
int hash(Color elem){
    return ((elem.rgb[0]*5)+(elem.rgb[1]*7)+(elem.rgb[2]*13))%DICT_MAX;
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
    int count = 0;
    for(int i=0; i<DICT_MAX; i++){
        int displayed = 0;
        for(int j=0; j<d[i]->size; j++){
            if(!displayed) printf("[%-2d] ", i), displayed=1;
            else printf("     ");
            displayColor(d[i]->data[j]);
            count++;
        }
    }
    printf("Colors in Pallete: [%d]\n", count);
    printf("================================================\n");
}
void resize(List l){
    l->capacity *= 2;
    l->data = realloc(l->data, sizeof(Color)*l->capacity);
    if(l->data){
        for(int i=l->capacity/2; i<l->capacity; i++) l->data[i] = (Color){"", {-1,-1,-1}};
        printf("         [RESIZED]\n");
    } else {
        l->capacity /= 2;
        printf("Error: Memory Allocation Error\n");
    }
}
void insertFirst(Dictionary d, Color elem){
    int ndx = hash(elem);
    if(d[ndx]->size == d[ndx]->capacity) resize(d[ndx]);
    for(int i=d[ndx]->size; i>0; i--) d[ndx]->data[i] = d[ndx]->data[i-1];
    d[ndx]->data[0] = elem;
    d[ndx]->size++;
    printf("Success: Insert First\n");
}
void insertLast(Dictionary d, Color elem){
    int ndx = hash(elem);
    if(d[ndx]->size == d[ndx]->capacity) resize(d[ndx]);
    d[ndx]->data[d[ndx]->size++] = elem;
    printf("Success: Insert Last\n");
}
void desize(List l){
    l->capacity /= 2;
    l->data = realloc(l->data, l->capacity);
    if(l->data) printf("         [DESIZED]\n");
    else {
        l->capacity *= 2;
        printf("Error: Memory Allocation Error\n");
    }
}
void deleteFirst(Dictionary d, Color elem){
    int ndx = hash(elem);
    if(d[ndx]->size>0){
        for(int i=0; i<d[ndx]->size-1; i++) d[ndx]->data[i] = d[ndx]->data[i+1];
        d[ndx]->data[--d[ndx]->size] = (Color){"", {-1,-1,-1}};
        if(d[ndx]->size < (d[ndx]->capacity*0.25) && d[ndx]->capacity>1) desize(d[ndx]);
        printf("Success: Delete First\n");
    } else {
        printf("Error: Node is Empty\n");
    }
}
void deleteLast(Dictionary d, Color elem){
    int ndx = hash(elem);
    if(d[ndx]->size>0){
        d[ndx]->data[--d[ndx]->size] = (Color){"", {-1,-1,-1}};
        if(d[ndx]->size < (d[ndx]->capacity*0.25) && d[ndx]->capacity>1) desize(d[ndx]);
        printf("Success: Delete Last\n");
    } else {
        printf("Error: Node is Empty\n");
    }
}
Color searchColor(Dictionary d, Color elem){
    Color retval = (Color){"", {-1,-1,-1}};
    int ndx = hash(elem), i;
    for(i=0; i<d[ndx]->size && (
        strcmp(elem.name, d[ndx]->data[i].name) ||
        d[ndx]->data[i].rgb[0] != elem.rgb[0] ||
        d[ndx]->data[i].rgb[1] != elem.rgb[1] ||
        d[ndx]->data[i].rgb[2] != elem.rgb[2]
    ); i++){}
    if(i<d[ndx]->size) retval = d[ndx]->data[i];
    return retval;
}
Color searchViaString(Dictionary d, char name[]){
    Color retval = (Color){"", {-1,-1,-1}};
    for(int i=0, found=0, j; i<DICT_MAX && !found; i++){
        for(j=0; j<d[i]->size && strcmp(name, d[i]->data[j].name); j++){}
        if(j<d[i]->size) retval = d[i]->data[j], found=1;
    }
    return retval;
}
Color searchViaRGB(Dictionary d, int rgb[]){
    Color retval = (Color){"", {-1,-1,-1}};
    int ndx = ((rgb[0]*5)+(rgb[1]*7)+(rgb[2]*13))%DICT_MAX, i;
    for(i=0; i<d[ndx]->size && (
        rgb[0] != d[ndx]->data[i].rgb[0] ||
        rgb[1] != d[ndx]->data[i].rgb[1] ||
        rgb[2] != d[ndx]->data[i].rgb[2]
    ); i++){}
    if(i < d[ndx]->size) retval = d[ndx]->data[i];
    return retval;
}








