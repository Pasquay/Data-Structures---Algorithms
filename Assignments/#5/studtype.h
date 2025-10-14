#ifndef STUDTYPE_H
#define STUDTYPE_H

#define MAX 10
// STUDTYPE
    typedef struct{
        char LName[16];
        char FName[24];
        char Mi;
    } Nametype;

    typedef struct{
        Nametype name;
        unsigned int ID;
        char Course[8];
        int YrLvl;
    } Studtype;

// LINK LIST
    typedef struct node {
        Studtype stud;
        struct node* link;
    } Node, *List;

// CURSOR BASED
    typedef struct {
        Studtype data;
        int next;
    } stype, HeapSpace[MAX];

    typedef struct {
        HeapSpace arr;
        int avail;
    } VHeap;



void displayStudent(Studtype s){
    char fullname[50];
    snprintf(fullname, sizeof(fullname), "%s %c %s", s.name.FName, s.name.Mi, s.name.LName);
    printf("%-20s | %-8s | %-4d | %-10u\n", 
        fullname, s.Course, s.YrLvl, s.ID);
}
void displayStudentHeader(){
    printf("==================DISPLAYING===================\n");
    printf("Name                 | Course   | Year | ID\n");
}

#endif