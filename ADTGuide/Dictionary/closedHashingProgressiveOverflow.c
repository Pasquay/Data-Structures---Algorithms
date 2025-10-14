#include<stdio.h>
#include<stdlib.h>
#include"closedHashingProgressiveOverflow.h"

int main(){
    Dictionary pallete;
    initDict(&pallete);
    displayDict(pallete);

    Color colors[20] = {
        {"red", {21, 0, 0}, -1},    //0
        {"green", {21, 0, 0}, -1},  //1
        {"blue", {54, 0, 0}, -1},   //2
        {"white", {38, 0, 0}, -1},  //3
        {"black", {21, 0, 0}, -1},  //4
        {"yellow", {46, 0, 0}, -1}, //5
        {"purple", {16, 0, 0}, -1}, //6
        {"orange", {17, 0, 0}, -1}, //7
        {"pink", {54, 0, 0}, -1},   //8
        {"gray", {54, 0, 0}, -1},   //9
        {"crimson", {21, 0, 0}, -1},//10
        {"cyan", {46, 0, 0}, -1},   //11
        {"magenta", {16, 0, 0}, -1},//12
        {"brown", {16, 0, 0}, -1},  //13
        {"lime", {46, 0, 0}, -1},   //14
        {"indigo", {32, 0, 0}, -1}, //15
        {"maroon", {32, 0, 0}, -1}, //16
        {"olive", {21, 0, 0}, -1},  //17
        {"teal", {19, 0, 0}, -1},   //18
        {"silver", {61, 0, 0}, -1},  //19
        {"silver", {61, 0, 0}, -1},  //20
    };


    for(int i=0; i<20; i++) insertFirst(&pallete, colors[i]);
    // for(int i=0; i<20; i++) insertLast(&pallete, colors[i]);
    displayDict(pallete);


    for(int i=0; i<1; i++) deleteFirst(&pallete, colors[2]); //0-5
    // for(int i=0; i<21; i++) deleteLast(&pallete, colors[i]); //5-7
    displayDict(pallete);

    
    printf("\n\n"); 
    printf("==================SEARCH COLOR==================\n");
    for(int i=0; i<20; i++) displayColor(searchColor(pallete, colors[i]));
    printf("================================================\n");
    // printf("\n\n");
    // printf("================SEARCH BY STRING================\n");
    // for(int i=0; i<11; i++) displayColor(searchViaString(pallete, colors[i].name));
    // printf("================================================\n");
    // printf("\n\n");
    // printf("=================SEARCH BY RGB==================\n");
    // for(int i=0; i<11; i++) displayColor(searchViaRGB(pallete, colors[i].rgb));
    // printf("================================================\n");
}