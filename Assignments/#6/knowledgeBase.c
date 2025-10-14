#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX_CELLS 20

typedef struct {
    int id;
    char title[64];
    char content[255];
} Article;

typedef struct {
    Article data;
    int next;
} Stype, HeapSpace[MAX_CELLS];

typedef struct {
    HeapSpace list;
    int avail;
} VHeap;

int idNumber = 1;

VHeap* initialize(){
    VHeap *vh = (VHeap*)malloc(sizeof(VHeap));
    if(vh){
        for(int ndx=vh->avail=MAX_CELLS-1; ndx>-1; ndx--){
            vh->list[ndx].next = ndx-1;
            vh->list[ndx].data.id = 0;
            strcpy(vh->list[ndx].data.title, "");
            strcpy(vh->list[ndx].data.content, "");
        }
    }
    return vh;
}
void initializeList(int* list){
    *list = -1;
}
void displayArticle(Article a){
    printf("-------------------------\n");
    printf("ID: %d\n", a.id);
    printf("Title: %s\n", a.title);
    printf("-------------------------\n");
}
void display(VHeap vh, int list){
    printf("\nLIST: ");
    for(int i=list; i!=-1; i=vh.list[i].next) displayArticle(vh.list[i].data);
    printf("\n\n");
}
int alloc(VHeap *vh){
    int retval = vh->avail;
    if(retval!=-1) vh->avail = vh->list[retval].next;
    return retval;
}
void dealloc(VHeap *vh, int index){
    if(vh->avail!=MAX_CELLS-1)
    vh->list[index].next = vh->avail;
    vh->avail = index;
}
void insertArticle(VHeap *vh, int *list){
    int temp = alloc(vh);
    if(temp!=-1){
        int position; char title[64], content[255];
        printf("Enter Title: "); scanf(" %[^\n]", title);
        printf("Enter Content:\n"); scanf(" %[^\n]", content);
        printf("Enter Position: "); scanf("%d", &position);

        vh->list[temp].data.id = idNumber++;
        strcpy(vh->list[temp].data.title, title);
        strcpy(vh->list[temp].data.content, content);

        if(position==0 || *list==-1){ //insert head
            vh->list[temp].next = *list;
            *list = temp;
        } else if(position==-1){ //insert tail
            int ndx;
            for(ndx=*list; vh->list[ndx].next!=-1; ndx=vh->list[ndx].next){}
            vh->list[temp].next = -1;
            vh->list[ndx].next = temp;
        } else { //inbetween
            int ndx=*list, count=0, temp2;
            for(; vh->list[ndx].next!=-1 && count<position; ndx=vh->list[ndx].next, count++){}
            temp2 = vh->list[ndx].next;
            vh->list[ndx].next = temp;
            vh->list[temp].next = temp2;
        }
    }
}
Article findArticle(VHeap *vh, int list, int id){
    Article retval = {
        0,
        "",
        ""
    };

    if(list!=-1){
        int ndx;
        for(ndx=list; ndx!=-1 && id!=vh->list[ndx].data.id; ndx=vh->list[ndx].next){}
        if(ndx!=-1) retval = vh->list[ndx].data;
    }
    
    return retval;
}
void deleteArticle(VHeap *vh, int *list){
    if(*list!=-1){
        printf("Enter ID: ");
        int id; scanf("%d", &id);
        int *trav;
        for(trav=list; *trav!=-1 && id!=vh->list[*trav].data.id; trav=&(vh->list[*trav].next)){}
        if(*trav!=-1){
            int temp = *trav;
            *trav = vh->list[*trav].next;
            dealloc(vh, temp);
        }

        // if(id==vh->list[*list].data.id){
        //     int temp = *list;
        //     *list = vh->list[*list].next;
        //     dealloc(vh, temp);
        // } else {
        //     int prev=*list, ndx=vh->list[prev].next;
        //     for(; ndx!=-1 && id!=vh->list[ndx].data.id; prev=ndx, ndx=vh->list[ndx].next){}
        //     if(ndx!=-1){
        //         vh->list[prev].next = vh->list[ndx].next;
        //         dealloc(vh, ndx);
        //     }
        // }
    }
}

int main(){
    VHeap *vh = initialize();
    int l; initializeList(&l);
    display(*vh, l);

    // Task 1: Write the function for inserting a new article.
    printf("=====TASK 1=====\n");
    insertArticle(vh, &l);
    insertArticle(vh, &l);
    insertArticle(vh, &l);
    display(*vh, l);

    // Task 2: Write the function for searching an article.
    printf("=====TASK 2=====\n");
    displayArticle(findArticle(vh, l, 2));
    display(*vh, l);
    
    // Task 3: Write the function for deleting an article.
    printf("=====TASK 3=====\n");
    deleteArticle(vh, &l);
    display(*vh, l);
}
