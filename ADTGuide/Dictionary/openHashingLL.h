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

typedef struct node {
    Color data;
    struct node *link;
} Node, *List;

typedef List Dictionary[DICT_MAX];
 
void initDict(Dictionary d){
    for(int i=0; i<DICT_MAX; i++) d[i] = NULL;
}
int hash(Color x){
    return ((x.rgb[0]*5)+(x.rgb[1]*7)+(x.rgb[2]*13))%DICT_MAX; 
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
    for(int i=0; i<DICT_MAX; i++){
        int displayed = 0;
        List trav = d[i];
        for(; trav!=NULL; trav=trav->link){
            if(!displayed) printf("[%-2d] ", i), displayed=1;
            else printf("     ");
            displayColor(trav->data);
            count++;
        }
    }
    printf("Colors in Pallete: [%d]\n", count);
    printf("================================================\n");
}
void insertFirst(Dictionary d, Color elem){
    List temp = malloc(sizeof(Node));
    if(temp){
        temp->data = elem;
        temp->link = d[hash(elem)];
        d[hash(elem)] = temp;
        printf("Success: Insert first\n");
    } else {
        printf("Error: Insert first\n");
    }
}
void insertLast(Dictionary d, Color elem){
    if(d[hash(elem)]==NULL) insertFirst(d, elem);
    else {
        List temp = malloc(sizeof(Node));
        if(temp){
            temp->data = elem;
            temp->link = NULL;
            List *trav;
            for(trav=&d[hash(elem)]; *trav!=NULL; trav=&(*trav)->link){}
            *trav = temp;
            printf("Success: Insert Last\n");
        } else {
            printf("Error: Insert Last\n");
        }
    }
}
void deleteFirst(Dictionary d, Color elem){
    if(!d[hash(elem)]) printf("Error: Delete First\n");
    else {
        List temp = d[hash(elem)];
        d[hash(elem)] = d[hash(elem)]->link;
        free(temp);
        printf("Success: Delete First\n");
    }
}
void deleteLast(Dictionary d, Color elem){
    if(!d[hash(elem)]) printf("Error: Delete Last\n");
    else {
        if(!d[hash(elem)]->link) deleteFirst(d, elem);
        else {
            List *trav = &d[hash(elem)];
            for(; (*trav)->link!=NULL; trav=&(*trav)->link){}
            List temp = *trav;
            *trav = NULL;
            free(temp);
            printf("Success: Delete Last\n");
        }
    }
}
Color searchColor(Dictionary d, Color elem){
    Color retval = (Color){"", {-1,-1,-1}};
    List trav = d[hash(elem)];
    for(; trav!=NULL && strcmp(elem.name, trav->data.name) && (
        elem.rgb[0]!=trav->data.rgb[0] ||
        elem.rgb[1]!=trav->data.rgb[1] ||
        elem.rgb[2]!=trav->data.rgb[2]
    ); trav=trav->link){}
    if(trav) retval = trav->data;
    return retval;
}
Color searchViaString(Dictionary d, char str[]){
    Color retval = (Color){"", {-1,-1,-1}};
    int found = 0;
    for(int i=0; i<DICT_MAX && !found; i++){
        List trav = d[i];
        for(; trav!=NULL && strcmp(str, trav->data.name); trav=trav->link){}
        if(trav) retval = trav->data, found=1;
    }
    return retval;
}
Color searchViaRGB(Dictionary d, int rgb[]){
    Color retval = (Color){"", {-1,-1,-1}};
    List trav = d[((rgb[0]*5)+(rgb[1]*7)+(rgb[2]*13))%64];
    for(; trav!=NULL && (
        rgb[0]!=trav->data.rgb[0] ||
        rgb[1]!=trav->data.rgb[1] ||
        rgb[2]!=trav->data.rgb[2]
    ); trav=trav->link){}
    if(trav) retval = trav->data;
    return retval;
}









