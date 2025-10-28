/* Daud Ahmad Nisar
This file contains the main function, which provides a
menu-driven interface to manage the student queue.*/

#include <stdio.h>
#include "student.h"

int main() {
    char code;  // stores the operation code entered by user
    char name[NAME_LEN + 1], netid[NETID_LEN + 1], cop2510_grade;
    double gpa;
    int attempts;
    struct student *registration = NULL;  // head of the student queue

    // display help menu at the start
    help();
    printf("\n");

    for (;;) {  // infinite loop for continuous menu-driven operation
        // prompt user for an operation code
        printf("Enter operation code: ");
        scanf(" %c", &code);  // read operation code
        while (getchar() != '\n');  // clear input buffer

        switch (code) {
            case 'h':  // help: display the operation codes
                help();
                break;
            case 'a':  // add: add a new student to the queue
                read(name, netid, &cop2510_grade, &gpa, &attempts);
                registration = add_student(registration, name, netid, cop2510_grade, gpa, attempts);
                break;
            case 'p':  // pop: remove the first student from the queue
                registration = pop_student(registration);
                break;
            case 'l':  // list: display all students in the queue
                list_students(registration);
                break;
            case 'g':  // GPA search: list students with a GPA >= specified value
                printf("Enter GPA: ");
                scanf("%lf", &gpa);
                list_gpa_min(registration, gpa);
                break;
            case 'c':  // grade search: list students with a grade >= specified value
                printf("Enter COP2510 grade: ");
                scanf(" %c", &cop2510_grade);
                list_cop2510_min(registration, cop2510_grade);
                break;
            case 'q':  // quit: clear the queue and exit the program
                registration = clear_queue(registration);
                return 0;
            default:  // handle invalid operation codes
                printf("Invalid operation code!\n");
        }
        printf("\n");  // add a blank line after each operation
    }
}
