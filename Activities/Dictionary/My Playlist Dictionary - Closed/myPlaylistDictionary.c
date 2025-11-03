#define MAX 32
#include<stdio.h>
#include<string.h>

typedef char String[30];

typedef struct{
	String songName;
	String singer;
	String genre;
}Song;

typedef struct{
	Song elem;
	int next;
}Heapspace;

typedef struct{
	Heapspace H[MAX];
	int avail;
}VirtualHeap;

void initDict(VirtualHeap *VH);

void insert(VirtualHeap *VH,Song song);
void deleteMember(VirtualHeap *VH,Song song);
int search(VirtualHeap VH,Song song);

int hash(String genre);
void displayDict(VirtualHeap VH);

String genreTable[16] = {
    "Ballad", "Pop Rock", "Pop", "R&B", "Rock", "Country Pop", "J-Pop", "K-Pop",
    "Classical", "Theater", "EDM", "OPM", "Reggae","Dance", "Jazz",  "Indie"
};

int main(){
	Song songBook[20]={	{"Someone Like You","Adele","Ballad"},
						{"Yellow Submarine","Beatles","Pop Rock"},
						{"Training Season","Dua Lipa","Pop"},
						{"Let's go back","Jungle","Dance"},
						{"Sway","Michael Buble","Jazz"},
						{"Love Story","Taylor Swift","Country Pop"},
						{"Where is my Husband?","Raye","Jazz"},
						{"Fly me to the moon","Frank Sinatra","Jazz"},
						{"Thinking Out Loud","Ed Sheeran","Ballad"},
						{"Back on 74","Jungle","Dance"},
						{"Mr. Brightside","The Killers","Pop Rock"},
						{"Kirari","Fuji Kaze","J-Pop"},
						{"This is What You Came For","Calvin Harris","Pop"},
						{"Rock with you","SEVENTEEN","K-Pop"},
						{"Symphony no. 8","Beethoven","Classical"},
						{"Defying Gravity","Wicked","Theater"},
						{"Alone","Marshmello","EDM"},
						{"Buwan","Juan Karlos","OPM"},
						{"NO PROBLEMZ","Jungle","Dance"},
						{"Doo Wop'","Lauryn Hill","R&B"}};

	int trav;
	Song temp={"Fly me to the moon","Frank Sinatra","Jazz"};
	Song check={"Everynight","Jungle","Dance"};
	Song delFirst={"Training Season","Dua Lipa","Pop"};
	VirtualHeap VH;

	
	initDict(&VH);
	
	for(trav=0;trav<20;trav++){
			insert(&VH,songBook[trav]);
	}
		
	displayDict(VH);
	printf("\n");

	printf("\nThe song \"%s\" %s in my playlist",check.songName,(search(VH,check))?"exists":"does not exist");
	printf("\nThe song \"%s\" %s in my playlist",temp.songName,(search(VH,temp))?"exists":"does not exist");

	// Delete Tail
	printf("\n\nDeleting song %s",temp.songName);
	deleteMember(&VH,temp);
	// Delete Head
	printf("\nDeleting song %s",delFirst.songName);
	deleteMember(&VH,delFirst);
	printf("\n\nInserting song %s",check.songName);
	insert(&VH,check);

	printf("\n");
	displayDict(VH);

	return 0;

}

//  your functions here...
int hash(String genre){
	int i;
	for(i=0; i<16 && strcmp(genre, genreTable[i]); i++){}
	return (i==16) ? -1 : i;
}

int alloc(VirtualHeap *VH){
	int retval = VH->avail;
	if(retval!=-1) VH->avail = VH->H[VH->avail].next;
	return retval;
}

void insert(VirtualHeap *VH,Song song){
	int ndx = hash(song.genre);
	if(ndx!=-1){
		if(!strcmp(VH->H[ndx].elem.songName, "")) VH->H[ndx].elem = song;
		else {
			int avail = alloc(VH);
			if(avail==-1) printf("Error: List is Full\n");
			else {
				VH->H[avail] = (Heapspace){song, -1};
				for(; VH->H[ndx].next!=-1; ndx=VH->H[ndx].next){}
				VH->H[ndx].next = avail;
			}
		}
	}
}

void dealloc(VirtualHeap *VH, int ndx){
	VH->H[ndx].next = VH->avail;
	VH->avail = ndx;
}

void deleteMember(VirtualHeap *VH,Song song){
	int ndx = hash(song.genre);
	if(ndx!=-1){
		int curr=ndx, prev=-1;
		for(; curr!=-1 && (
			strcmp(VH->H[curr].elem.genre, song.genre) ||
			strcmp(VH->H[curr].elem.singer, song.singer) ||
			strcmp(VH->H[curr].elem.songName, song.songName)
		); prev=curr, curr=VH->H[curr].next){}
		if(curr!=-1){
			if(prev==-1){
				int temp = VH->H[curr].next;
				if(temp==-1){
					strcpy(VH->H[curr].elem.genre, "Empty");
					VH->H[curr].elem.singer[0] = '\0';
					VH->H[curr].elem.songName[0] = '\0';
				} else {
					VH->H[curr] = VH->H[temp];
					dealloc(VH, temp);
				}
			} else {
				VH->H[prev].next = VH->H[curr].next;
				dealloc(VH, curr);
			}
		}
	}
}

int search(VirtualHeap VH,Song song){
	int retval = 0, ndx = hash(song.genre);
	if(ndx!=-1){
		for(; ndx!=-1 && 
			(strcmp(song.genre, VH.H[ndx].elem.genre) || 
			strcmp(song.singer, VH.H[ndx].elem.singer) || 
			strcmp(song.songName, VH.H[ndx].elem.songName)); 
		ndx=VH.H[ndx].next){}
		if(ndx!=-1) retval = 1;
	}
	return retval;
}




// HELPER FUNCTIONS
void initDict(VirtualHeap *VH)
{
	int i,Lim,Half;
	Lim=MAX-1; //31
	Half=MAX/2; //16
	for(i=0 ; i<Half ; i++){
		strcpy(VH->H[i].elem.genre,"Empty");
        VH->H[i].elem.songName[0] = '\0';
        VH->H[i].elem.singer[0] = '\0';
		VH->H[i].next=-1;
	}


	for(; i<Lim ; i++){
		VH->H[i].next=i+1;
	}

	VH->H[i].next=-1;
	VH->avail=16;
}

void displayDict(VirtualHeap VH){

	int trav,cntr,set,LIM;
	set=1;
	LIM=MAX/2;

	printf("Playlist of Janie Sabado");
	printf("\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ");
	printf("\n  %3s   %30s   %-15s   %-13s","Ndx","Song Name","Singer","Genre");
	printf("\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ");
	for(trav=0;trav<LIM;trav++){
		if(strcmp(VH.H[trav].elem.genre,"Empty")==0){
			printf("\n  %3d.  %30s - %-15s | %-13s",trav+1,"---","---","---");
			//printf("%5d",VH.H[trav].next);
		}else{
			printf("\n  %3d.  %30s - %-15s | %-13s",trav+1,VH.H[trav].elem.songName,VH.H[trav].elem.singer,VH.H[trav].elem.genre);
			//printf("%5d",VH.H[trav].next);
            cntr = VH.H[trav].next;
            while(cntr != -1){
                printf("\n        %30s - %-15s | %-13s",VH.H[cntr].elem.songName, VH.H[cntr].elem.singer, VH.H[cntr].elem.genre);
                //printf("%5d",VH.H[cntr].next);
				cntr = VH.H[cntr].next;
            }
		}

		printf("\n\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ");
	}

}