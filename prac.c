#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_MAX 32

typedef struct {
    char name[STR_MAX];
    int evolution; // tier of eveolution (1 -> ?)
    int stratum;
        // Lower you go, the stronger you are
        // 1 = stratum of beasts
        // 2 = nightmare stratum
        // 3 = demon stratum
        // 4 = mythical stratum
        // 5 = death stratum
    int might;   // physical strength
    int speed;   // physical speed
    int will;    // magical strength
    int cunning; // intelligence
} Monster;

typedef struct node {
    Monster data;
    struct node *leftChild;
    struct node *rightChild;
} Node, *Tree;

// HELPER FUNCTIONS
    int getTotalStats(Monster m){
        return (m.might+m.speed+m.will+m.cunning);
    }
    void printMonsterAltHeader(){
        printf("--------------------\n");
        printf("| NAME       | TTL |\n");
        printf("--------------------\n");
    }
    void printMonsterAlt(Monster m){
        printf("| %-10s | %3d |\n", m.name, getTotalStats(m));
    }
    void printMonsterHeader(){
        printf("----------------------------------------------------\n");
        printf("| NAME       | Evo | Stm | M  | S  | W  | C  | TTL |\n");
        printf("----------------------------------------------------\n");
    }
    void printMonster(Monster m){
    printf("| %-10s |  %1d  |  %1d  | %2d | %2d | %2d | %2d | %3d |\n", 
        m.name, 
        m.evolution,
        m.stratum,
        m.might,
        m.speed,
        m.will,
        m.cunning,
        getTotalStats(m)
    );
}

// TREE FUNCTIONS
Tree initTree(){
    printf("Initialized tree\n");
    return NULL;
}
Tree createNode(Monster m){
    Tree temp = malloc(sizeof(Node));
    if(temp){
        strcpy(temp->data.name, m.name);
        temp->data.evolution = m.evolution;
        temp->data.stratum = m.stratum;
        temp->data.might = m.might;
        temp->data.speed = m.speed;
        temp->data.will = m.will;
        temp->data.cunning = m.cunning;

        temp->leftChild = NULL;
        temp->rightChild = NULL;
    }
    return temp;
}
// ITERATIVE FUNCTIONS
    void insert(Tree *t, Monster m){
        int total = getTotalStats(m);
        Tree *trav = t;
        while(*trav!=NULL && total!=getTotalStats((*trav)->data)){
            if(total<getTotalStats((*trav)->data)) trav=&(*trav)->leftChild;
            else if(total>getTotalStats((*trav)->data)) trav=&(*trav)->rightChild;
        }
        if(*trav) printf("Error: Not unique\n");
        else {
            printf("Insert ");
            printMonsterAlt(m);
            *trav = createNode(m);
        }
    }
    void printInorder(Tree t){
        Tree stack[32];
        int top = -1;

        while(t||top!=-1){
            while(t){
                stack[top++] = t;
                t = t->leftChild;
            }

            t = stack[top--];
            // printmonsterAlt(t->data);
        }
    }
// RECURSIVE FUNCTIONS
    // void insert(Tree *t, Monster m){
    //     int total = getTotalStats(m);
    //     if(!*t){
    //         printf("Insert:  ");
    //         printMonsterAlt(m);
    //         *t = createNode(m);
    //     }
    //     else if(total==getTotalStats((*t)->data)) printf("Error: Not unique\n");
    //     else if(total<getTotalStats((*t)->data)) insert(&(*t)->leftChild, m);
    //     else if(total>getTotalStats((*t)->data)) insert(&(*t)->rightChild, m);
    // }
    // void printInorder(Tree t){
    //     if(t){
    //         printInorder(t->leftChild);
    //         printMonsterAlt(t->data);
    //         printInorder(t->rightChild);
    //     }
    // }
    void printPreorder(Tree t){
        if(t){
            printMonsterAlt(t->data);
            printPreorder(t->leftChild);
            printPreorder(t->rightChild);
        }
    }
    void printPostorder(Tree t){
        if(t){
            printPostorder(t->leftChild);
            printPostorder(t->rightChild);
            printMonsterAlt(t->data);
        }
    }
    Monster find(Tree t, Monster m){
        if(!t) return (Monster){'-',0,0,0,0,0,0};
        else if(getTotalStats(m)<getTotalStats(t->data)) return find(t->leftChild,m);
        else if(getTotalStats(m)>getTotalStats(t->data)) return find(t->rightChild,m);
        else return t->data;
    }
    Monster findMin(Tree t){
        if(!t) return (Monster){"-",0,0,0,0,0,0,};
        else if(t->leftChild) return findMin(t->leftChild);
        else return t->data;
    }
    Monster findMax(Tree t){
        if(!t) return (Monster){"-",0,0,0,0,0,0,};
        else if(t->rightChild) return findMax(t->rightChild);
        else return t->data;
    }
    void delete(Tree *t, Monster m){
        if(!*t) {
            printf("Error: Not found ");
            printMonsterAlt(m);
        }
        else if(getTotalStats(m)<getTotalStats((*t)->data)) delete(&(*t)->leftChild, m);
        else if(getTotalStats(m)>getTotalStats((*t)->data)) delete(&(*t)->rightChild, m);
        else {
            // 0 Child
            if(!(*t)->leftChild && !(*t)->rightChild){
                printf("Delete 0 Child:  ");
                printMonsterAlt((*t)->data);
                Tree temp = *t;
                *t = NULL;
                free(temp);
            }
            // 1 Child
            else if(!(*t)->rightChild){
                printf("Delete 1 Child:  ");
                printMonsterAlt((*t)->data);
                Tree temp = *t;
                *t = (*t)->leftChild;
                free(temp);
            }
            // 2 Child
            else {
                printf("Delete 2 Child:  ");
                printMonsterAlt((*t)->data);
                (*t)->data = findMin((*t)->rightChild);
                delete(&(*t)->rightChild, (*t)->data);
            }
        }
    }

int main(){
    Monster given[14] = {
        {"Leviathan",   4, 4, 88, 82, 82, 58},   // Total: 310
        {"Fenrir",      1, 1, 60, 45, 40, 35},   // Total: 180
        {"Reaper",      5, 5, 99, 99, 99, 99},   // Total: 396
        {"Dragon",      4, 4, 94, 86, 78, 57},   // Total: 315
        {"Chimera",     2, 2, 68, 62, 54, 46},   // Total: 230
        {"Cerberus",    1, 1, 57, 53, 38, 37},   // Total: 185
        {"Dullahan",    3, 3, 80, 60, 60, 55},   // Total: 255
        {"Behemoth",    1, 1, 65, 40, 36, 34},   // Total: 175
        {"Basilisk",    2, 2, 70, 60, 50, 45},   // Total: 225
        {"Archdemon",   3, 3, 82, 68, 61, 54},   // Total: 265
        {"Manticore",   1, 1, 58, 57, 39, 36},   // Total: 190
        {"Phoenix",     4, 4, 90, 80, 70, 65},   // Total: 305
        {"Oni",         3, 3, 78, 67, 62, 53},   // Total: 260
        {"Nightmare",   2, 2, 72, 58, 56, 49},   // Total: 235
    };
    int size = sizeof(given)/sizeof(Monster);
    
    // printMonsterAltHeader();
    // for(int i=0; i<14; i++) printMonsterAlt(given[i]);
    // printf("--------------------\n");
    printMonsterHeader();
    for(int i=0; i<14; i++) printMonster(given[i]);
    printf("----------------------------------------------------\n");



    printf("\n\n==========%s==========\n", "INITIALIZE");
        Tree monsters = initTree();


    printf("\n\n==========%s==========\n", "INSERT");
        for(int i=0; i<size; i++)
            insert(&monsters, given[i]);


    printf("\n\n==========%s==========\n", "INORDER");
        printMonsterAltHeader();
        printInorder(monsters);
        printf("--------------------\n");


    // printf("==========%s==========\n", "PREORDER");
    //     printMonsterAltHeader();
    //     printPreorder(monsters);
    //     printf("--------------------\n");


    // printf("==========%s==========\n", "POSTORDER");
    //     printMonsterAltHeader();
    //     printPostorder(monsters);
    //     printf("--------------------\n");


    // printf("\n\n==========%s==========\n", "FIND");
    //     Monster toFind[6] = {
    //         {"Behemoth",    1, 1, 65, 40, 36, 34},   // MIN
    //         {"Reaper",      5, 5, 99, 99, 99, 99},   // MAX
    //         {"Leviathan",   4, 4, 88, 82, 82, 58},   // ROOT
    //         {"Basilisk",    2, 2, 70, 60, 50, 45},   // 1 CHILD
    //         {"Chimera",     2, 2, 68, 62, 54, 46},   // 2 CHILD
    //         {"Ant",         1, 1, 16,  8, 12,  9},   // MISSING
    //     };

    //     printMonsterHeader();
    //     for(int i=0; i<6; i++){
    //         printMonster(find(monsters, toFind[i]));
    //     }
    //     printf("----------------------------------------------------\n");


    // printf("\n\n==========%s==========\n", "MIN-MAX");
    //     printMonsterHeader();
    //     printMonster(findMin(monsters));
    //     printMonster(findMax(monsters));
    //     printf("----------------------------------------------------\n");


    // printf("\n\n==========%s==========\n", "DELETE");
    //     Monster toDelete[6] = {
    //         {"Behemoth",    1, 1, 65, 40, 36, 34},   // MIN
    //         {"Reaper",      5, 5, 99, 99, 99, 99},   // MAX
    //         {"Leviathan",   4, 4, 88, 82, 82, 58},   // ROOT
    //         {"Basilisk",    2, 2, 70, 60, 50, 45},   // 1 CHILD
    //         {"Chimera",     2, 2, 68, 62, 54, 46},   // 2 CHILD
    //         {"Ant",         1, 1, 16,  8, 12,  9},   // MISSING
    //     };

    //     for(int i=0; i<6; i++) delete(&monsters, toDelete[i]);
    //     // for(int i=0; i<size; i++) delete(&monsters, given[i]);

    //     printMonsterAltHeader();
    //     printInorder(monsters);
    //     printf("--------------------\n");
}