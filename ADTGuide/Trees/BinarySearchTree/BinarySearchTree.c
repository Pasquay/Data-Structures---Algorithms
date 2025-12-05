#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define STR_MAX 32

// DEFINITION
    typedef struct node {
        int data;
        struct node *leftChild;
        struct node *rightChild;
    } Node, *Tree;

Tree initTree(){
    printf("Initialized\n");
    return NULL;
}
Tree createNode(int x){
    Tree temp = malloc(sizeof(Node));
    if(!temp) printf("Error: Malloc\n");
    else {
        temp->data = x;
        temp->leftChild = NULL;
        temp->rightChild = NULL;
    }
    return temp;
}
// ITERATIVE FUNCTIONS
    void insertIterative(Tree *t, int x){
        if(*t==NULL){
            *t = createNode(x);
            printf("Insert Iterative: %2d - ROOT\n", x);
        } else {
            Tree *trav = t;
            while(*trav!=NULL && (x<(*trav)->data || x>(*trav)->data)){
                if(x<(*trav)->data) trav=&(*trav)->leftChild;
                else if(x>(*trav)->data) trav=&(*trav)->rightChild;
            }
            if(*trav==NULL) *trav = createNode(x);
            printf("Insert Iterative: %2d - LEAF\n", x);
        }
    }
    void printInorderIterative(Tree t){
        Tree stack[32];
        int top = -1;
        while(t||top!=-1){
            while(t){
                stack[++top] = t;
                t = t->leftChild;
            }
            t = stack[top--];
            printf("[%2d] ", t->data);
            t = t->rightChild;
        }
    }
    void printPreorderIterative(Tree t){
        Tree stack[32];
        int top = -1;
        if(t) stack[++top] = t;
        while(top!=-1){
            t = stack[top--];
            printf("[%2d] ", t->data);
            if(t->rightChild) stack[++top] = t->rightChild;
            if(t->leftChild) stack[++top] = t->leftChild;
        }
    }
    void printPostorderIterative(Tree t){
        Tree stack1[32], stack2[32];
        int top1 = -1, top2 = -1;

        stack1[++top1] = t;
        while (top1 != -1) {
            Tree curr = stack1[top1--];
            stack2[++top2] = curr;
            if (curr->leftChild) stack1[++top1] = curr->leftChild;
            if (curr->rightChild) stack1[++top1] = curr->rightChild;
        }
        while (top2 != -1) {
            printf("[%2d] ", stack2[top2--]->data);
        }
    }
    Tree findIterative(Tree t, int x){
        while(t!=NULL && t->data!=x){
            if(x<t->data) t = t->leftChild;
            else if(x>t->data) t = t->rightChild;
        }
        return t ? t : NULL ;
    }
    Tree minIterative(Tree t){
        for(t; t!=NULL && t->leftChild!=NULL; t=t->leftChild){}
        return t;
    }
    Tree maxIterative(Tree t){
        for(t; t!=NULL && t->rightChild!=NULL; t=t->rightChild){}
        return t;
    }
    void deleteMinIterative(Tree *t){
        if(!*t) printf("Error: Tree is empty\n");
        else {
            Tree *trav = t;
            for(; (*trav)->leftChild!=NULL; trav=&(*trav)->leftChild){}
            if(*trav!=NULL){
                printf("Delete Min: [%2d]\n", (*trav)->data);
                Tree temp = *trav;
                *trav = (*trav)->rightChild;
                free(temp);
            }
        }
    }
    void deleteMaxIterative(Tree *t){
        if(!*t) printf("Error: Tree is empty\n");
        else {
            Tree *trav = t;
            for(t; (*trav)->rightChild!=NULL; trav=&(*trav)->rightChild){}
            if(*trav){
                printf("Delete Max: [%2d]\n", (*trav)->data);
                Tree temp = *trav;
                *trav = (*trav)->leftChild;
                free(temp);
            }
        }
    }
    void deleteRootIterative(Tree *t){
        if(!*t) printf("Error: Tree is empty\n");
        else {
            // 0 Child
            if(!(*t)->leftChild && !(*t)->rightChild){
                printf("Delete Root 0 Child: [%2d]\n", (*t)->data);
                Tree temp = *t;
                *t = NULL;
                free(temp);
            }
            // 1 Child
            else if(!(*t)->rightChild){
                printf("Delete Root 1 Child: [%2d]\n", (*t)->data);
                Tree temp = *t;
                *t = (*t)->leftChild;
                free(temp);
            }
            // 2 Children
            else {
                printf("Delete Root 2 Children: [%2d]\n", (*t)->data);
                (*t)->data = minIterative((*t)->rightChild)->data;
                deleteMinIterative(&(*t));
            }
        }
    }
    void deleteElemIterative(Tree *t, int x){
        Tree *trav = t;
        while(*trav!=NULL && x!=(*trav)->data){
            if(x<(*trav)->data) trav=&(*trav)->leftChild;
            else if(x>(*trav)->data) trav=&(*trav)->rightChild;
        }
        if(!*trav) printf("Error: [%2d] not found\n", x);
        else {
            // 0 Child
            if(!(*trav)->leftChild && !(*trav)->rightChild){
                printf("Delete Leaf: [%2d]\n", (*trav)->data);
                Tree temp = *trav;
                *trav = NULL;
                free(temp);
            }
            // 1 Child
            else if(!(*trav)->rightChild){
                printf("Delete 1 Child Node: [%2d]\n", (*trav)->data);
                Tree temp = *trav;
                *trav = (*trav)->leftChild;
                free(temp);
            }
            // 2 Children
            else {
                printf("Delete 2 Child Node: [%2d]\n", (*trav)->data);
                (*trav)->data = minIterative((*trav)->rightChild)->data;
                deleteElemIterative(&(*trav)->rightChild, (*trav)->data);
            }
        }
    }
// RECURSIVE FUNCTIONS
    void insertRecursive(Tree *t, int x){
        if(*t == NULL){
            *t = createNode(x);
            printf("Insert Recursive: %2d\n", x);
        } 
        else if(x<(*t)->data) insertRecursive(&(*t)->leftChild, x);
        else if(x>(*t)->data) insertRecursive(&(*t)->rightChild, x);
    }
    void printInorderRecursive(Tree t){
        if(t!=NULL){
            printInorderRecursive(t->leftChild); // LEFTCHILD
            printf("[%2d] ", t->data); // PARENT
            printInorderRecursive(t->rightChild); // RIGHTCHILD
        }
    }
    void printPreorderRecursive(Tree t){
        if(t!=NULL){
            printf("[%2d] ", t->data);
            printPreorderRecursive(t->leftChild);
            printPreorderRecursive(t->rightChild);
        }
    }
    void printPostorderRecursive(Tree t){
        if(t!=NULL){
            printPostorderRecursive(t->leftChild); // LEFTCHILD
            printPostorderRecursive(t->rightChild); // RIGHTCHILD
            printf("[%2d] ", t->data); // PARENT
        }
    }
    Tree findRecursive(Tree t, int x){
        if(t==NULL) return NULL;
        if(x==t->data) return t;
        if(x<t->data) return findRecursive(t->leftChild,x);
        else return findRecursive(t->rightChild,x);
    }
    Tree minRecursive(Tree t){
        if(t==NULL) return NULL;
        if(t->leftChild==NULL) return t;
        else return minRecursive(t->leftChild);
    }
    Tree maxRecursive(Tree t){
        if(t==NULL) return NULL;
        if(t->rightChild==NULL) return t;
        else return maxRecursive(t->rightChild);
    }
    void deleteMinRecursive(Tree *t){
        if(!*t) printf("Error: Tree is empty\n");
        else if((*t)->leftChild) deleteMinRecursive(&(*t)->leftChild);
        else {
            printf("Delete Min: [%2d]\n", (*t)->data);
            Tree temp = *t;
            *t = (*t)->rightChild;
            free(temp);
        }
    }
    void deleteMaxRecursive(Tree *t){
        if(!*t) printf("Error: Tree is empty\n");
        else if((*t)->rightChild) deleteMaxRecursive(&(*t)->rightChild);
        else {
            printf("Delete Max: [%2d]\n", (*t)->data);
            Tree temp = *t;
            *t = (*t)->leftChild;
            free(temp);
        }
    }
    void deleteRootRecursive(Tree *t){
        if(!*t) printf("Error: Tree is empty\n");
        else if(!(*t)->leftChild && !(*t)->rightChild){
            printf("Delete Root 0 Children: [%2d]\n", (*t)->data);
            Tree temp = *t;
            *t = NULL;
            free(temp);
        }
        else if(!(*t)->rightChild){
            printf("Delete Root 1 Children: [%2d]\n", (*t)->data);
            Tree temp = *t;
            *t = (*t)->leftChild;
            free(temp);
        } else {
            printf("Delete Root 2 Children: [%2d]\n", (*t)->data);
            (*t)->data = minRecursive((*t)->rightChild)->data;
            deleteMinRecursive(&(*t)->rightChild);
        }
    }
    void deleteElemRecursive(Tree *t, int x){
        if(!*t) printf("Error: [%2d] not found\n", x);
        else if(x<(*t)->data) deleteElemRecursive(&(*t)->leftChild,x);
        else if(x>(*t)->data) deleteElemRecursive(&(*t)->rightChild,x);
        else {
            // 0 Child
            if(!(*t)->leftChild && !(*t)->rightChild){
                printf("Delete Leaf: [%2d]\n", (*t)->data);
                Tree temp = *t;
                *t = NULL;
                free(temp);
            }
            // 1 Child
            else if(!(*t)->rightChild){
                printf("Delete 1 Child Node: [%2d]\n", (*t)->data);
                Tree temp = *t;
                *t = temp->leftChild;
                free(temp);
            }
            // 2 Child
            else {
                printf("Delete 2 Child Node: [%2d]\n", (*t)->data);
                (*t)->data = minRecursive((*t)->rightChild)->data;
                deleteElemRecursive(&(*t)->rightChild,(*t)->data);
            }
        }
    }

int main(){
    int data[] = {
        42, 87, 13, 56, 99,
        24, 68, 75, 31, 90,
         7, 53, 61, 28,
    };
    int size = sizeof(data)/sizeof(int);

    printf("==========%s==========\n", "INITIALIZE");
        printf("ITERATIVE:\n");
        Tree iterate = initTree();
        printf("RECURSIVE:\n");
        Tree recurse = initTree();
        

    printf("\n\n==========%s==========\n", "INSERT");
        printf("ITERATIVE:\n");
        for(int i=0; i<size; i++) insertIterative(&iterate, data[i]);
        printf("RECURSIVE:\n");
        for(int i=0; i<size; i++) insertRecursive(&recurse, data[i]);


    printf("\n\n==========%s==========\n", "PRINT");
        printf("=====PRINT: %s======\n", "INORDER");
            printf("ITERATIVE:\n");
            printInorderIterative(iterate);
            printf("\n");
            printf("RECURSIVE:\n");
            printInorderRecursive(recurse);
        printf("\n=====PRINT: %s=====\n", "PREORDER");
            printf("ITERATIVE:\n");
            printPreorderIterative(iterate);
            printf("\n");
            printf("RECURSIVE:\n");
            printPreorderRecursive(recurse);
        printf("\n=====PRINT: %s====\n", "POSTORDER");
            printf("ITERATIVE:\n");
            printPostorderRecursive(iterate);
            printf("\n");
            printf("RECURSIVE:\n");
            printPostorderRecursive(recurse);
        
        
    printf("\n\n\n==========%s==========\n", "FIND");
        int data2[6] = {
            42,   // root
            7,    // min (leftmost leaf)
            99,   // max (rightmost leaf)
            24,   // internal node
            68,   // internal node
            15    // not found (missing)
        };

        char *string2[6] = {
            "root",
            "min",
            "max",
            "node",
            "node",
            "n/a",
        };

        printf("ITERATIVE:\n");
            for(int i=0; i<6; i++){
                printf("Find %4s [%2d]: %s\n",
                    string2[i],
                    data2[i],
                    findIterative(iterate, data2[i])!=NULL
                        ? "FOUND"
                        : "MISSING"
                );
            }
        printf("\n");
        printf("RECURSIVE:\n");
            for(int i=0; i<6; i++)
                printf("Find %4s [%2d]: %s\n",  
                    string2[i], 
                    data2[i],
                    findRecursive(recurse, data2[i])!=NULL
                        ? "FOUND" 
                        : "MISSING"
                );


    printf("\n\n==========%s==========\n", "MIN-MAX");
        printf("ITERATIVE:\n");
            printf("Min: [%2d]\n", minIterative(iterate)->data);
            printf("Max: [%2d]\n", maxIterative(iterate)->data);
            printf("  Root: %2d\n  Predecessor: %2d\n  Successor: %2d", 
                iterate->data,
                maxIterative(iterate->leftChild)->data,
                minIterative(iterate->rightChild)->data
            );
        printf("\n");
        printf("RECURSIVE:\n");
            printf("Min: [%2d]\n", minRecursive(recurse)->data);
            printf("Max: [%2d]\n", maxRecursive(recurse)->data);
            printf("  Root: %2d\n  Predecessor: %2d\n  Successor: %2d", 
                recurse->data,
                maxRecursive(recurse->leftChild)->data,
                minRecursive(recurse->rightChild)->data
            );


    printf("\n\n\n==========%s==========\n", "DELETE");
        int data3[6] = {
            42,   // root
            7,    // min (leftmost leaf)
            99,   // max (rightmost leaf)
            24,   // internal node
            68,   // internal node
            15    // not found (missing)
        };

        printf("ITERATIVE:\n");
            for(int i=0; i<6; i++) deleteElemIterative(&iterate, data3[i]);
            printf("\n");
            for(int i=0; i<1; i++) 
                deleteMinIterative(&iterate);  // 13 
            for(int i=0; i<1; i++) 
                deleteMaxIterative(&iterate);  // 90
            for(int i=0; i<1; i++) 
                deleteRootIterative(&iterate); // 53
            printInorderRecursive(iterate);
        printf("\n\n\n");
        printf("RECURSIVE:\n");
        for(int i=0; i<6; i++) deleteElemRecursive(&recurse, data3[i]);
        printf("\n");
            for(int i=0; i<1; i++) 
                deleteMinRecursive(&recurse);  // 13
            for(int i=0; i<1; i++) 
                deleteMaxRecursive(&recurse);  // 90
            for(int i=0; i<1; i++) 
                deleteRootRecursive(&recurse); // 53
            printInorderRecursive(recurse);
}
