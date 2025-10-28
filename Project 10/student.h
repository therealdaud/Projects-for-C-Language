/* Daud Ahmad Nisar
This header file declares the student structure and 
function prototypes for managing the student queue.*/

#ifndef STUDENT_H
#define STUDENT_H

// constants for name and netID length
#define NAME_LEN 100
#define NETID_LEN 40

// structure to represent a student in queue
struct student {
    char name[NAME_LEN + 1];      // student name
    char netid[NETID_LEN + 1];    // student NetID
    char cop2510_grade;           // student grade in COP2510
    double gpa;                   // student GPA
    int attempts;                 // number of attempts in COP2510
    struct student *next;         // pointer to next student in queue
};

// function prototypes
void help();  // displays the help menu with operation codes
void read(char *name, char *netid, char *cop2510_grade, double *gpa, int *attempts);  // reads student details
struct student *add_student(struct student *registration, char *name, char *netid, char cop2510_grade, double gpa, int attempts);  // adds a student to queue
struct student *pop_student(struct student *registration);  // removes first student from the queue
void list_students(struct student *registration);  // lists all students in queue
void list_gpa_min(struct student *registration, double gpa);  // lists students with a GPA >= specified value
void list_cop2510_min(struct student *registration, char cop2510_grade);  // lists students with a grade <= specified value
struct student *clear_queue(struct student *registration);  // clears entire queue

#endif 