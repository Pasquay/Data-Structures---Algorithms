#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"
// #include "array.h"
// #include "struct.h"

int main(){
    Student data[10] = {
        {{"Joseph", "Pascua", 'S'}, "22101372", "BSCS", 2, 1, "2005-05-19", 1.52, 1},
        {{"Maria", "Lopez", 'A'}, "22101373", "BSCS", 2, 0, "2005-07-21", 1.75, 1},
        {{"John", "Smith", 'B'}, "22101374", "BSIT", 1, 1, "2006-01-10", 2.10, 1},
        {{"Anna", "Garcia", 'C'}, "22101375", "BSCS", 3, 0, "2004-12-05", 1.90, 1},
        {{"Mark", "Lee", 'D'}, "22101376", "BSIT", 2, 1, "2005-03-15", 2.25, 1},
        {{"Sofia", "Kim", 'E'}, "22101377", "BSCS", 1, 0, "2006-08-30", 1.60, 1},
        {{"Paul", "Tan", 'F'}, "22101378", "BSIT", 4, 1, "2003-11-22", 2.00, 1},
        {{"Grace", "Lim", 'G'}, "22101379", "BSCS", 3, 0, "2004-04-18", 1.80, 1},
        {{"Luke", "Evans", 'H'}, "22101380", "BSIT", 2, 1, "2005-09-09", 2.30, 1},
        {{"Ella", "Cruz", 'I'}, "22101381", "BSCS", 1, 0, "2006-02-27", 1.70, 1}
    };

    Student data1[5] = {
        {{"Kevin", "Reyes", 'J'}, "22101382", "BSIT", 3, 1, "2004-06-12", 2.15, 1},
        {{"Lara", "Santos", 'K'}, "22101383", "BSCS", 2, 0, "2005-11-03", 1.85, 1},
        {{"Miguel", "Torres", 'L'}, "22101384", "BSIT", 1, 1, "2006-03-27", 2.05, 1},
        {{"Nina", "Flores", 'M'}, "22101385", "BSCS", 4, 0, "2003-08-14", 1.95, 1},
        {{"Oscar", "Dela Cruz", 'N'}, "22101386", "BSIT", 2, 1, "2005-12-30", 2.20, 1}
    };

    /**
     * Task 1: Initialize the list then display
     */

    printf("\nTask #1: Initializing List.\n\n");
    List l = initialize();

    /**
     * Task 2: Populate the list with data then display
     */

    printf("\nTask#2: Populating List.\n");
    for(int i=0; i<10; i++) insertLast(&l, data[i]);
    displayList(l);

    /**
     * Task 3: Insert first, last, then at positions 8, 16, 0
     *      Display after each insertion
     */

    printf("\nTask #3: Inserting in List.\n\n");
    insertFirst(&l, data[0]);
    // displayList(l);
    insertLast(&l, data[1]);
    // displayList(l);
    insertAt(&l, data[4], 0);
    // displayList(l);
    insertAt(&l, data[2], 8);
    // displayList(l);
    insertAt(&l, data[3], 16);
    displayList(l);

    /**
     * Task 4: Delete first, last, at positions 0, 8 and 18, delete ids
     *      Display after each deletion
     */

    char id[4][9] = {
        "22101372",
        "22101381",
        "22101376",
        "99999999"
    };

    printf("\nTask #4: Deleting from List.\n\n");
    deleteFirst(&l);
    // displayList(l);
    deleteLast(&l);
    // displayList(l);
    deleteAt(&l, 0);
    // displayList(l);
    deleteAt(&l, 8);
    // displayList(l);
    deleteAt(&l, 18);
    for(int i=0; i<4; i++) deleteId(&l, id[i]);
    displayList(l);


    /**
     * Task 5: Find a student by id and display their info
     */

    char id2[4][9] = {
        "22101373",
        "22101380",
        "22101375",
        "99999999"
    };

    printf("\nTask #5: Finding Element in List.\n\n");
    for(int i=0; i<4; i++) displayStudent(findStudent(l, id2[i]));

    /**
     * Task 6: Update the students fname, id, gpa and status then display
     */

    char id3[2][9] = {
        "99999999", // NOT FOUND
        "22101373"  // MARIA A. LOPEZ
    };

    printf("\nTask #6: Updating Element in List.\n\n");
    // updateFname(&l, id3[0]);
    // updateFname(&l, id3[1]);
    // updateId(&l, id3[0]);
    // updateId(&l, id3[1]);
    // updateGPA(&l, id3[0]);
    // updateGPA(&l, id3[1]);
    // updateStatus(&l, id3[0]);
    // updateStatus(&l, id3[1]);
    displayList(l);

    
     /**
     * Task 7: Sort list by ID, then GPA, then Name
     *      Display after each sort
     */


    /**
     * Task 8: Reverse the list and display
     */


    /**
     * Task 9: Count the number of students and display
     */

    /**
     * Task 10: Insert sorted elem
     */
    
    /**
     * Task 11: Delete list
     */
}