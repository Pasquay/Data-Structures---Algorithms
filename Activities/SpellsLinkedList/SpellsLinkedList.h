#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char String[30];
typedef struct Node {
    String spell;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
}Set;

/**  
Expected Output

Common Spells:
  1. Inferno

All Spells:
  1. Aqua Jet
  2. Flame Burst
  3. Inferno

All Spells:
  1. Flame Burst
  2. Inferno
*/

// write your functions here...

// Create a new empty set
Set* createSet(){
    Set *temp = malloc(sizeof(Set));
    if(temp){
        temp->head = NULL;
        temp->size = 0;
    }
    return temp;
}

// Add a spell to the set (no duplicates)
bool addSpell(Set* set, String spell){
    bool retval = false;
    Node **trav = &set->head;
    for(; *trav!=NULL && strcmp((*trav)->spell, spell); trav=&(*trav)->next){}
    if(*trav==NULL){
        Node *temp = malloc(sizeof(Node));
        if(temp){
            strcpy(temp->spell, spell);
            temp->next = NULL;
            *trav = temp;
            set->size++;
            retval = true;
        }
    }
    return retval;
}

// Remove a spell from the set
bool removeSpell(Set** set, String spell){
    bool retval = false;
    if(!strcmp(spell, (*set)->head->spell)){
        Node *temp = (*set)->head;
        (*set)->head = temp->next;
        free(temp);
        (*set)->size--;
        retval = true;
    } else {
        Node *trav = (*set)->head;
        for(; trav->next!=NULL && strcmp(trav->next->spell, spell); trav=trav->next){}
        if(trav->next!=NULL){
            Node *temp = trav->next;
            trav->next = temp->next;
            free(temp);
            (*set)->size--;
            retval = true;
        }
    }
    return retval;
}

// Check if a spell exists in the set
bool containsSpell(Set* set, String spell){
    Node *trav = set->head;
    for(; trav!=NULL && strcmp(trav->spell, spell); trav=trav->next){}
    return trav==NULL ? false : true;
}

// Print all spells in the set
void printSet(Set* set){
    Node *trav = set->head;
    for(int i=1; trav!=NULL; trav=trav->next, i++) 
        printf("  %d. %s\n", i, trav->spell);
}

// Free all memory associated with the set
void destroySet(Set* set){
    for(; set->head!=NULL; removeSpell(&set, set->head->spell)){}
    free(set);
}

Set* unionSets(Set* set1, Set* set2){
    Set *retval = createSet();
    Node *trav1=set1->head, *trav2=set2->head;
    for(; trav1!=NULL && trav2!=NULL; trav1=trav1->next, trav2=trav2->next){
        if(!containsSpell(retval, trav2->spell)) addSpell(retval, trav2->spell);
        if(!containsSpell(retval, trav1->spell)) addSpell(retval, trav1->spell);
    }
    return retval;
}

Set* intersectSets(Set* set1, Set* set2){
    Set *retval = createSet();
    Node *trav=set1->head;
    for(; trav!=NULL; trav=trav->next)
        if(containsSpell(set2, trav->spell)) addSpell(retval, trav->spell);
    return retval;
}

// // Create a new empty set
// Set* createSet(){
//     Set *temp = malloc(sizeof(Set));
//     if(temp) {
//         temp->head = NULL;
//         temp->size = 0;
//     }
//     return temp;
// }

// // Add a spell to the set (no duplicates)
// bool addSpell(Set* set, String spell){
//     bool retval = false;
//     Node **trav = &set->head;
//     for(; *trav!=NULL && strcmp((*trav)->spell, spell); trav=&(*trav)->next){}
//     if(*trav==NULL){
//         Node *temp = malloc(sizeof(Node));
//         if(temp){
//             strcpy(temp->spell, spell);
//             temp->next = NULL;
//             *trav = temp;
//             set->size++;
//             retval = true;
//         }
//     }
//     return retval;
// }

// // Remove a spell from the set
// bool removeSpell(Set** set, String spell){
//     bool retval = false;
//     if(*set!=NULL && (*set)->head!=NULL){
//         if(!strcmp((*set)->head->spell, spell)){
//             Node *temp = (*set)->head;
//             (*set)->head = (*set)->head->next;
//             free(temp);
//             (*set)->size--;
//             retval = true;
//         } else {
//             Node *trav = (*set)->head;
//             for(; trav->next!=NULL && strcmp(trav->next->spell, spell); trav=trav->next){}
//             if(trav->next!=NULL){
//                 Node *temp = trav->next;
//                 trav->next = temp->next;
//                 free(temp);
//                 (*set)->size--;
//                 retval = true;
//             }
//         }
//     }
//     return retval;
// }

// // Check if a spell exists in the set
// bool containsSpell(Set* set, String spell){
//     Node *trav = set->head;
//     for(; trav!=NULL && strcmp(trav->spell, spell); trav=trav->next){}
//     return (trav==NULL) ? 0:1;
// }

// // Print all spells in the set
// void printSet(Set* set){
//     Node *trav = set->head;
//     for(int count=1; trav!=NULL; trav=trav->next, count++){
//         printf("  %d. %s\n", count, trav->spell);
//     }
// }

// // Free all memory associated with the set
// void destroySet(Set* set){
//     Node *trav = set->head;
//     for(; trav!=NULL; ){
//         Node *temp = trav; 
//         trav=trav->next;
//         free(temp);
//     }
//     free(set);
// }

// Set* unionSets(Set* set1, Set* set2){
//     Set *retval = createSet();
//     Node *trav2 = set2->head, *trav = set1->head;
//     for(; trav2!=NULL && trav!=NULL; trav2=trav2->next, trav=trav->next){
//         if(!containsSpell(retval, trav2->spell)) addSpell(retval, trav2->spell);
//         if(!containsSpell(retval, trav->spell)) addSpell(retval, trav->spell);
//     }
//     return retval;
// }

// Set* intersectSets(Set* set1, Set* set2){
//     Set *retval=createSet();
//     Node *trav=set1->head;
//     for(trav; trav!=NULL; trav=trav->next)
//         if(containsSpell(set2, trav->spell)) addSpell(retval, trav->spell);
//     return retval;
// }
