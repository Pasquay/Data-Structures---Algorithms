/*
Closed Hashing:
	-Fixed sized dictionary, cant put same elements in same 
	 index like if its a linked list.
     SLTS:
       A. Linear Hashing
	1.If collide, move to next available index
	2.Use buckets. Rather than hash having one index,
	  Hash uses a range of index, like if the buckets are 3 big,
	  Index 0-2 are for elem%1, 3-5 are elem%2, 6-8 are elem%3, 
	  and so on until 27-29 are elem%10. If a bucket fills the 
	  range and there's still 1 more element, the element will
	  disappear.
*/
 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STR_MAX 32
#define DICT_MAX 64*2 //Each bucket is 2 indices

typedef struct {
    char name[STR_MAX];
    int rgb[3];
} Color;

typedef Color Dictionary[DICT_MAX];

void initDict(Dictionary d){
	for(int i=0; i<DICT_MAX; i++) d[i] = (Color){"", {-1,-1,-1}};
}
int hash(Color elem){
	return ((elem.rgb[0]*5)+(elem.rgb[1]*7)+(elem.rgb[2]*13))%64;
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
	for(int i=0; i<64; i++){
		int displayed = 0;
		for(int j=0; j<2; j++){
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
	int ndx = hash(elem)*2;
	if(!strcmp(d[ndx].name, "")){
		d[ndx] = elem;
		printf("Success: Insert First\n");
	} else if(!strcmp(d[ndx+1].name, "")) {
		d[ndx+1] = d[ndx];
		d[ndx] = elem;
		printf("Success: Insert First\n");
	} else {
		printf("Error: Bucket Full\n");
	}
}
void insertLast(Dictionary d, Color elem){
	int ndx = hash(elem)*2;
	if(!strcmp(d[ndx+1].name, "")){
		d[ndx+1] = elem;
		printf("Success: Insert Last\n");
	} else if(!strcmp(d[ndx].name, "") && strcmp(d[ndx+1].name, "")){
		d[ndx] = d[ndx+1];
		d[ndx+1] = elem;
		printf("Success: Insert Last\n");
	} else {
		printf("Error: Bucket is Full\n");
	}
}
void deleteFirst(Dictionary d, Color elem){
	int ndx = hash(elem)*2;
	if(strcmp(d[ndx].name, "")){
		d[ndx] = d[ndx+1];
		d[ndx+1] = (Color){"", {-1,-1,-1}};
		printf("Success: Delete First\n");
	} else if(strcmp(d[ndx+1].name, "")){
		d[ndx+1] = (Color){"", {-1,-1,-1}};
		printf("Success: Delete First\n");
	} else {
		printf("Error: Bucket Already Empty\n");
	}
}
void deleteLast(Dictionary d, Color elem){
	int ndx = hash(elem)*2;
	if(strcmp(d[ndx+1].name, "")){
		d[ndx+1] = (Color){"", {-1,-1,-1}};
		printf("Success: Delete Last\n");
	} else {
		printf("Error: Bucket Already Empty\n");
	}
}
Color searchColor(Dictionary d, Color elem){
	Color retval = (Color){"", {-1,-1,-1}};
	int i = hash(elem)*2, j;
	for(j=0; j<2 && (
		strcmp(d[i+j].name, elem.name) ||
		elem.rgb[0]!=d[i+j].rgb[0] ||
		elem.rgb[1]!=d[i+j].rgb[1] ||
		elem.rgb[2]!=d[i+j].rgb[2]
	); j++){}
	if(j<2) retval = d[j+i];
	return retval;
}
Color searchViaString(Dictionary d, char name[]){
	Color retval = (Color){"", {-1,-1,-1}};
	int i;
	for(int i=0; i<DICT_MAX && (strcmp(d[i].name, name)); i++){
		displayColor(d[i]);
	}
	if(i<DICT_MAX) retval = d[i];
	return retval;
}
Color searchViaRGB(Dictionary d, Color elem){
	Color retval = (Color){"", {-1,-1,-1}};

	return retval;
}





















