#include <stdio.h>
#include "name.h"

typedef struct student {
    Name name;
    char id[9];
    char course[5];
    int year;
    bool gender; // 0 - Female, 1 - Male
    char birthdate[11]; // YYYY-MM-DD;
    float gpa;
    bool isActive;
} Student;

void displayStudentHeader() {
    printf("%-20s %-10s %-8s %-6s %-8s %-12s %-6s %-8s\n",
        "Name", "ID", "Course", "Year", "Gender", "Birthdate", "GPA", "Status");
    printf("-----------------------------------------------------------------------------------\n");
}

void displayStudent(Student stud) {
    char nameBuf[NAME_MAX*2 + 5];
    snprintf(nameBuf, sizeof(nameBuf), "%s %c. %s", stud.name.fname, stud.name.mi, stud.name.lname);

    printf("%-20s %-10s %-8s %-6d %-8s %-12s %-6.2f %-8s\n",
        nameBuf,
        stud.id,
        stud.course,
        stud.year,
        stud.gender ? "Male" : "Female",
        stud.birthdate,
        stud.gpa,
        stud.isActive ? "Active" : "Inactive"
    );
}