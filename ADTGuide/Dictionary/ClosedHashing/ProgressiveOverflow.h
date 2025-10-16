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
			if(strcmp(d.data[j].name, "")){
				if(!displayed) printf("[%-3d][%-3d][%-3d] ", i, j, d.data[j].link), displayed=1;
				else printf("     [%-3d][%-3d] ", j, d.data[j].link);
				displayColor(d.data[j]);
				count++;
			}
		}
    }
	if(!count) printf("[---][---][---][---------] [-----------------]\n");
    printf("Colors: [%d]\tAvail: [%d]\n", count, d.avail);
    printf("================================================\n");
}
int alloc(Dictionary *d){
	int retval = d->avail;
	if(retval!=-1) d->avail = d->data[d->avail].link;
	return retval;
}
void insertFirst(Dictionary *d, Color elem){
	int ndx = hash(elem);
	if(!strcmp(d->data[ndx].name, "")){
		d->data[ndx] = elem;
		printf("Success: Insert First [H]\n");
	} else {
		int temp = alloc(d);
		if(temp == -1) printf("Error: List is Full\n");
		else {
			d->data[temp] = d->data[ndx];
			d->data[ndx] = elem;
			d->data[ndx].link = temp;
			printf("Success: Insert First [T]\n");
		}
	}
}
void insertLast(Dictionary *d, Color elem){
	int ndx = hash(elem);
	if(!strcmp(d->data[ndx].name, "")){
		d->data[ndx] = elem;
		printf("Success: Insert Last [H]\n");
	} else{
		// alloc
		int temp = alloc(d);
		if(temp == -1) printf("Error: List is Full\n");
		else {
			for(ndx; d->data[ndx].link!=-1; ndx=d->data[ndx].link){}
			d->data[ndx].link = temp;
			d->data[temp] = elem;
			printf("Success: Insert Last [T]\n");
		}
	}
}
void dealloc(Dictionary *d, int ndx){
	if(ndx>=DICT_SIZE && ndx<DICT_MAX){
		d->data[ndx].link = d->avail;
		d->data[ndx] = (Color){"",{-1,-1,-1},-1};
		d->avail = ndx;
	}
}
void deleteFirst(Dictionary *d, Color elem){
	int ndx = hash(elem);
	if(!strcmp(d->data[ndx].name, "")) printf("Error: Already Empty\n");
	else {
		if(d->data[ndx].link == -1){
			d->data[ndx] = (Color){"",{-1,-1,-1},-1};
			printf("Success: Delete First\n");
		} else {
			int temp = d->data[ndx].link;
			d->data[ndx] = d->data[temp];
			dealloc(d, temp);
			printf("Success: Delete First [H]\n");
		}
	}
}
void deleteLast(Dictionary *d, Color elem){
	int ndx = hash(elem);
	if(!strcmp(d->data[ndx].name, "")) printf("Error: Already Empty\n");
	else {
		if(d->data[ndx].link == -1){
			d->data[ndx] = (Color){"",{-1,-1,-1},-1};
			printf("Success: Delete Last\n");
		} else {
			if(d->data[d->data[ndx].link].link == -1){
				dealloc(d, d->data[ndx].link);
				d->data[ndx].link = -1;
				printf("Success: Delete Last [H]\n");
			}
			else {
				for(ndx; d->data[d->data[ndx].link].link!=-1; ndx=d->data[ndx].link){}
				dealloc(d, d->data[ndx].link);
				d->data[ndx].link = -1;
				printf("Success: Delete Last [T]\n");
			}
		}
	}
}
Color searchColor(Dictionary d, Color elem){
	Color retval = (Color){"",{-1,-1,-1},-1};
	int ndx = hash(elem);
	for(ndx; ndx!=-1 && strcmp(d.data[ndx].name, elem.name); ndx=d.data[ndx].link){}
	if(ndx!=-1) retval = d.data[ndx];
	return retval;
}





