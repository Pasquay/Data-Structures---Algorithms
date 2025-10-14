#define MAX 10

typedef struct {
int elem[MAX];
int count;
} List;

List initialize(List L);
void display(List L);
List insertPos(List L, int data, int position);
List insertSorted(List L, int data);
List deletePos(List L, int position);
int locate(List L, int data);
List sortAsc(List L);
List sortDesc(List L);

/**
 * INITIALIZE LIST
 */
List initialize(List L){
    L.count = 0;
    return L;
}


/**
 * DISPLAY LIST
 */
void display(List L){
    int ndx;
    printf("Elem: [ ");
    for(ndx=0; ndx<L.count; ndx++) printf("%d, ", L.elem[ndx]);
    printf("]\n");
    printf("Count: [%d]\n", L.count);
}


/**
 * INSERT ELEMENT
 */
List insertPos(List L, int data, int position){
    if(position > L.count) printf("Error: Index is out of bounds.\n");
    else if(L.count == MAX) printf("Error: List is full.\n");
    else {
        int ndx;
        for(ndx=L.count; ndx>position; ndx--){
            L.elem[ndx] = L.elem[ndx-1];
        }
        L.count++;
        L.elem[ndx] = data;
        printf("Success: %d inserted at [%d].\n", data, position);
    }
    return L;
}
List insertSorted(List L, int data){
    if(L.count == MAX) printf("Error: List is full.\n");
    else {
        int i;
        for(i=L.count-1; i>=0 && data<L.elem[i]; i--){
            L.elem[i+1] = L.elem[i];
        }
        L.count++;
        L.elem[i+1] = data;
        printf("Success: %d inserted at [%d].\n", data, i);
    }
    return L;
}



/**
 * DELETE ELEMENT
 */
List deletePos(List L, int position){
    if(position >= L.count) printf("Error: Index is out of bounds.\n");
    else {
        int i;
        for(i=0; i<position; i++){}
        L.count--;
        for(i=i; i<L.count; i++){
            L.elem[i] = L.elem[i+1];
        }
        printf("Success: Deleted from [%d].\n", position);
    }
    return L;
}


/**
 * LOCATE ELEMENT
 */
int locate(List L, int data){
    int i;
    for(i=0; i<L.count && L.elem[i]!=data; i++){}
    return (i==L.count) ? -1 : i;
}


/**
 * SORT LIST
 */
List sortAsc(List L){
    int out, in, temp, min;
    for(out=0; out<L.count-1; out++){
        min = out;
        for(in=out+1; in<L.count; in++){
            if(L.elem[min] > L.elem[in]) min = in;
        }
        if(min != out){
            temp = L.elem[out];
            L.elem[out] = L.elem[min];
            L.elem[min] = temp;
        }
    }
    printf("Success: List sorted.\n");
    return L;
}
List sortDesc(List L){
    int out, in, max, temp;
    for(out=0; out<L.count-1; out++){
        max = out;
        for(in=out+1; in<L.count; in++){
            if(L.elem[max] < L.elem[in]) max = in;
        }
        if(max != out){
            temp = L.elem[max];
            L.elem[max] = L.elem[out];
            L.elem[out] = temp;
        }
    }
    printf("Success: List sorted.\n");
    return L;
}



