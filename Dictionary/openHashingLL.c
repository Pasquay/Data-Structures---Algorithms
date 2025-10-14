#include<stdio.h>
#include"openHashingLL.h"

int main(){
    Dictionary pallete;
    initDict(pallete);
    displayDict(pallete);

    Color colors[11] = {
        {"red", {255, 0, 0}},       // 0
        {"green", {0, 255, 0}},     // 1
        {"blue", {0, 0, 255}},      // 2
        {"white", {255, 255, 255}}, // 3
        {"black", {0, 0, 0}},       // 4
        {"yellow", {255, 255, 0}},  // 5
        {"purple", {128, 0, 128}},  // 6
        {"orange", {255, 165, 0}},  // 7
        {"pink", {255, 192, 203}},  // 8
        {"gray", {128, 128, 128}},  // 9
        {"oten", {67, 67, 67}},     // 10
    }; 


    // for(int i=0; i<10; i++) insertFirst(pallete, colors[i]);
    for(int i=0; i<10; i++) insertLast(pallete, colors[i]);
    displayDict(pallete);


    // for(int i=0; i<4; i++) deleteFirst(pallete, colors[i]);
    // for(int i=4; i<7; i++) deleteLast(pallete, colors[i]);
    displayDict(pallete);

    
    printf("\n\n");
    printf("==================SEARCH COLOR==================\n");
    for(int i=0; i<11; i++) displayColor(searchColor(pallete, colors[i]));
    printf("================================================\n");
    printf("\n\n");
    printf("================SEARCH BY STRING================\n");
    for(int i=0; i<11; i++) displayColor(searchViaString(pallete, colors[i].name));
    printf("================================================\n");
    printf("\n\n");
    printf("=================SEARCH BY RGB==================\n");
    for(int i=0; i<11; i++) displayColor(searchViaRGB(pallete, colors[i].rgb));
    printf("================================================\n");
}