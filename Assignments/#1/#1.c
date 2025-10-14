#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* link;
} Node, *List;

void displayList(List A);
int listLength(List A);
int mostRepeatedElem(List A);
void insertLast(List *A, int x);
void insertFirst(List *A, int x);
void insertAt(List *A, int x, int pos);
int listSum(List A);
void removeFirst(List *A);
void removeLast(List *A);
void removeAt(List *A, int pos);
void concatList(List *A, List *B);
void reverseList(List *A);
bool isPalindrome(List A);
void swapNode(List *A, List *B);
void sortList(List *A);

int main(){
    int x, pos;
    int arr[5] = {8,8,9,9,9};
    List l = NULL;
    for(int i=0; i<5; i++){
        insertLast(&l, arr[i]);
    }
    displayList(l);
    printf("%d", mostRepeatedElem(l));
}

void displayList(List A){
    printf("List: ");
    for(; A!=NULL; A=A->link){
        printf("\t%d", A->data);
    }
    printf("\n");
}
int listLength(List A){
    int count = 0;
    for(; A!=NULL; A=A->link) count++;
    return count;
}
int mostRepeatedElem(List A){
    if(A!=NULL){
        List curr, trav;
        int cnt, max=0, elem = A->data;
        for(curr=A; curr!=NULL; curr=curr->link){
            cnt=0;
            for(trav=A; trav!=NULL; trav=trav->link){
                if(trav->data == curr->data) cnt++;
            }
            if(cnt > max){
                max = cnt;
                elem = curr->data;
            }
        }
        return elem;
    } else return 0;
}
void insertLast(List *A, int x){
    List temp = (List)malloc(sizeof(Node));
    if(temp!=NULL){
        List *trav;
        for(trav=A; *trav!=NULL; trav=&(*trav)->link){}
        temp->data = x;
        temp->link = NULL;
        *trav = temp;
    }
}
void insertFirst(List *A, int x){
    List temp = (List)malloc(sizeof(Node));
    if(temp!=NULL){
        temp->data = x;
        temp->link = *A;
        *A = temp;
    }
}
void insertAt(List *A, int x, int pos){
    List temp = (List)malloc(sizeof(Node));
    if(temp!=NULL){
        temp->data = x;
        if(pos==0){
            temp->link = *A;
            *A = temp;
        } else {
            List *trav;
            int ndx = 0;
            for(trav=A; *trav!=NULL && ndx<pos; trav=&(*trav)->link){
                ndx++;
            }
            temp->link = *trav;
            *trav = temp;
        }
    }
}
int listSum(List A){
    int sum = 0;
    for(;A!=NULL; A=A->link){
        sum+=A->data;
    }
    return sum;
}
void removeFirst(List *A){
    if(*A!=NULL){
        List temp = *A;
        *A = (*A)->link;
        free(temp);
    }
}
void removeLast(List *A){
    if(*A!=NULL){
        if((*A)->link!=NULL){
            List *trav;
            for(trav=A; (*trav)->link->link!=NULL; trav=&(*trav)->link){}
            List temp = (*trav)->link;
            (*trav)->link = NULL;
            free(temp);
        } else {
            List temp = *A;
            *A = (*A)->link;
            free(temp);
        }
    }
}
void removeAt(List *A, int pos){
    if(*A!=NULL){
        List temp;
        if(pos==0){
            temp = *A;
            *A = (*A)->link;
            free(temp);
        } else {
            List *trav;
            int ndx=1;
            for(trav=A; (*trav)->link!=NULL && ndx<pos; trav=&(*trav)->link){
                ndx++;
            }
            if((*trav)->link!=NULL){
                temp = (*trav)->link;
                (*trav)->link = temp->link;
                free(temp);
            }
        }
    }
}
void concatList(List *A, List *B){
    List *trav;
    for(trav=A; *trav!=NULL; trav=&(*trav)->link){}
    *trav = *B;
}
void reverseList(List *A){
    List *curr, next, prev=NULL;
    for(curr=A; *curr!=NULL; *curr=next){
        next = (*curr)->link;
        (*curr)->link = prev;
        prev = *curr;
    }
    *A = prev;
}
bool isPalindrome(List A){
    bool retval = true;
    List fast=A, slow=A;
    while(fast->link!=NULL && fast->link->link!=NULL){
        slow=slow->link;
        fast=fast->link->link;
    }
    
    List second = slow->link;
    slow->link = NULL;
    reverseList(&second);
    
    List secondRev = second;
    List first = A;
    
    while(secondRev!=NULL && first!=NULL){
        if(secondRev->data != first->data){
            retval = false;
            break;
        }
        first = first->link;
        secondRev = secondRev->link;
    }
    
    reverseList(&second);
    slow->link = second;
    
    return retval;
}
void swapNode(List *A, List *B){
    List temp = *A;
    *A = *B;
    *B = temp;
    
    temp = (*A)->link;
    (*A)->link = (*B)->link;
    (*B)->link = temp;
}
void sortList(List *A){
    List *outer, *inner, *min;
    for(outer=A; (*outer)->link!=NULL; outer=&(*outer)->link){
        displayList(*A); // Logging
        min = outer;
        for(inner=&(*outer)->link; *inner!=NULL; inner=&(*inner)->link){
            if((*min)->data > (*inner)->data) min = inner;
        }
        if(min!=outer) swapNode(min, outer);
    }
}








