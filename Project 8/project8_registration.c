/* Daud Ahmad Nisar
This code implements a linked list-based queue for managing student registrations for COP3514, 
with functions to add, remove, list, filter by GPA or grade, and clear students from the queue.*/


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
void list_cop2510_min(struct student *registration, int cop2510_grade);
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

/////////////////////////////////////////////////////////
// WARNING - WARNING - WARNING - WARNING - WARNING     //
/////////////////////////////////////////////////////////
// Do not modify anything before this point, otherwise //
// your solution will be considered incorrect.         //
/////////////////////////////////////////////////////////

// adds a new student to the queue
struct student * add_student(struct student *registration, char *name, char *netid, char cop2510_grade, double gpa, int attempts) {
    struct student *new_student = malloc(sizeof(struct student)); // allocate memory for new student
    if (!new_student) {
        perror("Failed to allocate memory"); // handle memory allocation failure
        return registration;
    }
    // copy the student details into the new student's fields
    strcpy(new_student->name, name);
    strcpy(new_student->netid, netid);
    new_student->cop2510_grade = cop2510_grade;
    new_student->gpa = gpa;
    new_student->attempts = attempts;
    new_student->next = NULL; // set the next pointer to NULL

    if (!registration) {
        return new_student; // if the list is empty, the new student becomes first element
    }

    struct student *current = registration;
    // traverse the list until the last student
    while (current->next) {
        current = current->next;
    }
    current->next = new_student; // add new student at end of the list

    return registration; // return the updated list
}

// removes the first student from the queue (linked list)
struct student * pop_student(struct student *registration) {
    if (!registration) {
        return registration; // do nothing if the list is empty
    }

    struct student *to_remove = registration;
    registration = registration->next; // move head of the list to the next student

    // print the details of the student being removed
    printf("|----------------------|----------------------|---------|-----|----------|\n");
    printf("| Name                 | NetID                | COP2510 | GPA | Attempts |\n");
    printf("|----------------------|----------------------|---------|-----|----------|\n");
    printf("| %-20s | %-20s |       %c | %1.1f | %8d |\n", 
           to_remove->name, to_remove->netid, to_remove->cop2510_grade, to_remove->gpa, to_remove->attempts);
    printf("|----------------------|----------------------|---------|-----|----------|\n");

    free(to_remove); // free the memory of the removed student
    return registration; // return the updated list
}

// list all students in the queue
void list_students(struct student *registration) {
    if (!registration) {
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
        return; // do nothing if list is empty
    }

    struct student *current = registration;
    int found = 0;

    while (current) {
        if (current->gpa >= gpa) { // check if the student's GPA is greater or equal to the specified value
            if (!found) {
                // print table headers only when the first matching student is found
                printf("|----------------------|----------------------|---------|-----|----------|\n");
                printf("| Name                 | NetID                | COP2510 | GPA | Attempts |\n");
                printf("|----------------------|----------------------|---------|-----|----------|\n");
            }
            // print the details of the student
            printf("| %-20s | %-20s |       %c | %1.1f | %8d |\n", 
                   current->name, current->netid, current->cop2510_grade, current->gpa, current->attempts);
            printf("|----------------------|----------------------|---------|-----|----------|\n");
            found = 1;
        }
        current = current->next; // move to the next student in the list
    }

    if (!found) {
        return; // do nothing if no students match the criteria
    }
}

// list students with a COP2510 grade greater than or equal to the specified grade
void list_cop2510_min(struct student *registration, int cop2510_grade) {
    if (!registration) {
        return; // do nothing if the list is empty
    }

    struct student *current = registration;
    int found = 0;

    while (current) {
        if (current->cop2510_grade <= cop2510_grade) { // check if the student's grade is less than or equal to the specified grade
            if (!found) {
                // print table headers only when the first matching student is found
                printf("|----------------------|----------------------|---------|-----|----------|\n");
                printf("| Name                 | NetID                | COP2510 | GPA | Attempts |\n");
                printf("|----------------------|----------------------|---------|-----|----------|\n");
            }
            // print the details of the student
            printf("| %-20s | %-20s |       %c | %1.1f | %8d |\n", 
                   current->name, current->netid, current->cop2510_grade, current->gpa, current->attempts);
            printf("|----------------------|----------------------|---------|-----|----------|\n");
            found = 1;
        }
        current = current->next; // move to the next student in the list
    }

    if (!found) {
        return; // do nothing if no students match the criteria
    }
}

// clears the entire student queue (linked list)
struct student * clear_queue(struct student *registration) {
    struct student *current = registration;
    while (current) {
        struct student *next = current->next; // save the next student
        free(current); // free the current student
        current = next;
    }
    return NULL; // return NULL as the list is now empty
}
