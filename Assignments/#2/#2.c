//switch between these two by incommenting and commenting the other
#include "linkList.h"
// #include "arrayList.h"

int main(){
    //initialize variables
    ListPtr l;
    Studtype students[] = {
        { {"Garcia", "Isabella", 'M'}, 20231001, "BSCS", 1 },
        { {"Tan", "Miguel", 'R'}, 20231002, "BSIT", 2 },
        { {"Reyes", "Jasmine", 'L'}, 20231003, "BSBA", 3 },
        { {"Santos", "John", 'D'}, 20231004, "BSCE", 4 },
        { {"Lim", "Angela", 'T'}, 20231005, "BSN", 2 },
        { {"Cruz", "Nathaniel", 'S'}, 20231006, "BSME", 1 },
        { {"Torres", "Camille", 'A'}, 20231007, "BSED", 3 },
        { {"Fernandez", "Liam", 'J'}, 20231008, "BSCS", 4 },
        { {"Dela Cruz", "Sofia", 'E'}, 20231009, "BSIT", 1 },
        { {"Ramos", "Enzo", 'K'}, 20231010, "BSBA", 2 }
    };
    initList(&l);

    //populating list
    for(int ndx = 0; ndx < 10; ndx++){
        addToList(l, students[ndx]);
    }
    
    //printing initial list
    printList(l);
    
    //delete by id, 20231005 is sample
    delNode(l, 20231005); // Lim Angela   
    delNode(l, 99999999); // Error   
    
    //print new list
    printList(l);
    return 0;
}
