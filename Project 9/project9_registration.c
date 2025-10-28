/* Daud Ahmad Nisar
A program to manage a queue of students with functionalities to add, remove, 
list, and search students based on GPA or grade, organized by attempts.*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//////////////////////
// data definitions //
//////////////////////

#define NAME_LEN 100
#define NETID_LEN 40

struct student {
    char name[NAME_LEN+1], netid[NETID_LEN+1], cop2510_grade; 
    double gpa; 
    int attempts; 
    struct student *next;
};

/////////////////////////
// function prototypes //
/////////////////////////

void help();
void read(char *name, char *netid, char *cop2510_grade, double *gpa, int *attempts);
struct student * add_student(struct student *registration, char *name, char *netid, char cop2510_grade, double gpa, int attempts);
struct student * pop_student(struct student *registration);
void list_students(struct student *registration);
void list_gpa_min(struct student *registration, double gpa);
void list_cop2510_min(struct student *registration, char cop2510_grade);
struct student * clear_queue(struct student *registration);

///////////////////
// main function //
///////////////////

int main() {
    char code; 
    char name[NAME_LEN+1], netid[NETID_LEN+1], cop2510_grade; 
    double gpa; 
    int attempts; 

    struct student *registration = NULL; 

    help(); 
    printf("\n");

    for (;;) {
        // read operation code
        printf("Enter operation code: ");
        scanf(" %c", &code); 
        while(getchar() != '\n') 
            ;

        // run operation
        switch (code) {
            case 'h':
                help(); 
                break;
            case 'a':
                read(name, netid, &cop2510_grade, &gpa, &attempts); 
                registration = add_student(registration, name, netid, cop2510_grade, gpa, attempts); 
                break;
            case 'p':
                registration = pop_student(registration); 
                break;
            case 'l':
                list_students(registration); 
                break;
            case 'g':
                read(NULL, NULL, NULL, &gpa, NULL); 
                list_gpa_min(registration, gpa); 
                break;
            case 'c':
                read(NULL, NULL, &cop2510_grade, NULL, NULL); 
                list_cop2510_min(registration, cop2510_grade); 
                break;
            case 'q':
                registration = clear_queue(registration);
                return 0;
            default:
                printf("Illegal operation code!\n"); 
        }
        printf("\n");
    }
}

//////////////////////////
// function definitions //
//////////////////////////

void help() {
    printf("List of operation codes:\n");
    printf("\t'h' for help;\n");
    printf("\t'a' for adding a student to the queue;\n");
    printf("\t'p' for removing a student from the queue;\n");
    printf("\t'l' for listing all students in the queue;\n");
    printf("\t'g' for searching students with a minimum GPA;\n");
    printf("\t'c' for searching students with a minimum grade in COP2510;\n");
    printf("\t'q' to quit.\n");
}

void read(char *name, char *netid, char *cop2510_grade, double *gpa, int *attempts) {
    if(name != NULL) {
        printf("Enter the name of the student: ");
        scanf("%[^\n]", name); 
        getchar();
    }
    if(netid != NULL) {
        printf("Enter the NetID of the student: ");
        scanf("%s", netid); 
    }
    if(cop2510_grade != NULL) {
        printf("Enter the COP2510 letter grade: ");
        scanf(" %c", cop2510_grade); 
    }
    if(gpa != NULL) {
        printf("Enter the GPA: ");
        scanf("%lf", gpa); 
    }
    if(attempts != NULL) {
        printf("Enter the number of previous attempts: ");
        scanf("%d", attempts);
    }
}

// adds a new student to queue in descending order of attempts
struct student * add_student(struct student *registration, char *name, char *netid, char cop2510_grade, double gpa, int attempts) {
    struct student *new_student = malloc(sizeof(struct student)); // allocate memory for new student
    if (!new_student) {
        perror("Failed to allocate memory"); // handle memory allocation failure
        return registration;
    }

    // copy the student details in the new student's fields
    strcpy(new_student->name, name);
    strcpy(new_student->netid, netid);
    new_student->cop2510_grade = cop2510_grade;
    new_student->gpa = gpa;
    new_student->attempts = attempts;
    new_student->next = NULL;

    // if the list is empty or new student has more attempts than the first student
    if (!registration || registration->attempts < attempts) {
        new_student->next = registration; // insert at the beginning
        return new_student;
    }

    struct student *current = registration;
    // traverse the list to find correct insertion point
    while (current->next && current->next->attempts >= attempts) {
        current = current->next;
    }

    // insert new student at the found position
    new_student->next = current->next;
    current->next = new_student;

    return registration; // return updated list
}

// removes first student from the queue
struct student * pop_student(struct student *registration) {
    if (!registration) {
        printf("The queue is empty.\n");
        return registration; // do nothing if list is empty
    }

    struct student *to_remove = registration;
    registration = registration->next; // move head of the list to the next student

    // print the details of student being removed
    printf("|----------------------|----------------------|---------|-----|----------|\n");
    printf("| Name                 | NetID                | COP2510 | GPA | Attempts |\n");
    printf("|----------------------|----------------------|---------|-----|----------|\n");
    printf("| %-20s | %-20s |       %c | %1.1f | %8d |\n", 
           to_remove->name, to_remove->netid, to_remove->cop2510_grade, to_remove->gpa, to_remove->attempts);
    printf("|----------------------|----------------------|---------|-----|----------|\n");

    free(to_remove); // free the memory of the removed student
    return registration; // return the updated list
}

// lists all students in queue
void list_students(struct student *registration) {
    if (!registration) {
        printf("The queue is empty.\n");
        return; // do nothing if list is empty
    }

    printf("|----------------------|----------------------|---------|-----|----------|\n");
    printf("| Name                 | NetID                | COP2510 | GPA | Attempts |\n");
    printf("|----------------------|----------------------|---------|-----|----------|\n");

    struct student *current = registration;
    while (current) {
        // print each student's details
        printf("| %-20s | %-20s |       %c | %1.1f | %8d |\n", 
               current->name, current->netid, current->cop2510_grade, current->gpa, current->attempts);
        printf("|----------------------|----------------------|---------|-----|----------|\n");
        current = current->next; // move to the next student in the list
    }
}

// list students with a GPA greater or equal to the specified value
void list_gpa_min(struct student *registration, double gpa) {
    if (!registration) {
        printf("The queue is empty.\n");
        return; // do nothing if the list is empty
    }

    struct student *current = registration;
    int found = 0;

    printf("|----------------------|----------------------|---------|-----|----------|\n");
    printf("| Name                 | NetID                | COP2510 | GPA | Attempts |\n");
    printf("|----------------------|----------------------|---------|-----|----------|\n");

    while (current) {
        if (current->gpa >= gpa) { // check if the student's GPA is greater or equal to the specified value
            printf("| %-20s | %-20s |       %c | %1.1f | %8d |\n",
                   current->name, current->netid, current->cop2510_grade, current->gpa, current->attempts);
            printf("|----------------------|----------------------|---------|-----|----------|\n");
            found = 1;
        }
        current = current->next; // move to the next student
    }

    if (!found) {
        printf("No students found with GPA >= %.2f\n", gpa);
    }
}

// list students with a COP2510 grade greater or equal to the specified grade
void list_cop2510_min(struct student *registration, char cop2510_grade) {
    if (!registration) {
        printf("The queue is empty.\n");
        return; // do nothing if the list is empty
    }

    struct student *current = registration;
    int found = 0;

    printf("|----------------------|----------------------|---------|-----|----------|\n");
    printf("| Name                 | NetID                | COP2510 | GPA | Attempts |\n");
    printf("|----------------------|----------------------|---------|-----|----------|\n");

    while (current) {
        if (current->cop2510_grade <= cop2510_grade) { // check if grade is less than or equal
            printf("| %-20s | %-20s |       %c | %1.1f | %8d |\n",
                   current->name, current->netid, current->cop2510_grade, current->gpa, current->attempts);
            printf("|----------------------|----------------------|---------|-----|----------|\n");
            found = 1;
        }
        current = current->next; // move to the next student
    }

    if (!found) {
        printf("No students found with COP2510 grade >= %c\n", cop2510_grade);
    }
}

// clears the entire student queue
struct student * clear_queue(struct student *registration) {
    struct student *current = registration;
    while (current) {
        struct student *next = current->next; // save the next student
        free(current); // free the current student
        current = next;
    }
    return NULL; // return NULL as the list is now empty
}