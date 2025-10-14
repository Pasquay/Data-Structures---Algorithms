/*
Closed Hashing:
	-Fixed sized dictionary, cant put same elements in same 
	 index like if its a linked list.
     SLTS:
       B. Progressive Overflow
	-Pretty much cursor based, Can be done via array but CB better
	1.First indices start at 0 to MAX-1, then just use cursor
	  based for the rest with avail and shit.
	2.Access primary to get the "Head" or "Primary" then insert it 
          whether its insert head or insert tail or whatever
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STR_MAX 32
#define DICT_SIZE 64
#define MULTIPLIER 2
#define DICT_MAX DICT_SIZE*MULTIPLIER

typedef struct {
	char name[STR_MAX];
	int rgb[3];
	int link;
} Color;

typedef struct {
	Color data[DICT_MAX];
	int avail;
} Dictionary;

void initDict(Dictionary *d){
	int i;
	for(i=d->avail=DICT_MAX-1; i>DICT_SIZE; i--) d->data[i] = (Color){"",{-1,-1,-1},i-1};
	for(i=i; i>-1; i--) d->data[i] = (Color){"",{-1,-1,-1}, -1};
}
int hash(Color elem){
	return ((elem.rgb[0]*5)+(elem.rgb[1]*7)+(elem.rgb[2]*13))%64;
}
void displayColor(Color x){
    printf("%-10s: RGB(%3d, %3d, %3d)\n", 
           x.name, 
           x.rgb[0], 
           x.rgb[1], 
           x.rgb[2]);
}
void displayDict(Dictionary d){
    printf("================== DICTIONARY ==================\n");
	printf("[NDX][CB ][LNK][  COLOR  ] [       RGB       ]\n");
    int count=0;
    for(int i=DICT_SIZE-1; i>-1; i--){
        int displayed = 0;
		for(int j=i; j!=-1; j=d.data[j].link){
			if(!displayed) printf("[%-3d][%-3d][%-3d] ", i, j, d.data[j].link), displayed=1;
			else printf("     [%-3d][%-3d] ", j, d.data[j].link);
			displayColor(d.data[j]);
			count++;
		}
    }
    printf("Colors: [%d]\tAvail: [%d]\n", count, d.avail);
    printf("================================================\n");
}
void insertFirst(Dictionary *d, Color elem){
	
}







