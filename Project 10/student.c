/* Daud Ahmad Nisar
This file contains all functions related to managing the student queue,
including adding, removing, listing, and searching for students.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

// displays a help menu with available operation codes
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

// reads student details from the user based on non-NULL parameters provided
void read(char *name, char *netid, char *cop2510_grade, double *gpa, int *attempts) {
    if (name) {
        printf("Enter the name of the student: ");
        scanf("%[^\n]", name);  // reads the full name including spaces
        getchar();              // clears the newline character from the buffer
    }
    if (netid) {
        printf("Enter the NetID of the student: ");
        scanf("%s", netid);
    }
    if (cop2510_grade) {
        printf("Enter the COP2510 letter grade: ");
        scanf(" %c", cop2510_grade);
    }
    if (gpa) {
        printf("Enter the GPA: ");
        scanf("%lf", gpa);
    }
    if (attempts) {
        printf("Enter the number of previous attempts: ");
        scanf("%d", attempts);
    }
}

// adds a student to the queue in descending order of the number of attempts
struct student *add_student(struct student *registration, char *name, char *netid, char cop2510_grade, double gpa, int attempts) {
    struct student *new_student = malloc(sizeof(struct student));
    if (!new_student) {
        perror("Failed to allocate memory");
        return registration;  // return unchanged queue if memory allocation fails
    }

    // initialize the new student's details
    strcpy(new_student->name, name);
    strcpy(new_student->netid, netid);
    new_student->cop2510_grade = cop2510_grade;
    new_student->gpa = gpa;
    new_student->attempts = attempts;
    new_student->next = NULL;

    // insert the student at the correct position in the queue
    if (!registration || registration->attempts < attempts) {
        new_student->next = registration;
        return new_student;  // new student becomes the head of the queue
    }

    struct student *current = registration;
    while (current->next && current->next->attempts >= attempts) {
        current = current->next;  // traverse to the correct position
    }
    new_student->next = current->next;
    current->next = new_student;

    return registration;
}

// removes the first student from the queue and frees allocated memory
struct student *pop_student(struct student *registration) {
    if (!registration) {
        printf("The queue is empty.\n");
        return registration;
    }

    struct student *to_remove = registration;  // get the first student
    registration = registration->next;        // update the head of the queue
    printf("Removed student: %s\n", to_remove->name);
    free(to_remove);                           // free memory of the removed student

    return registration;
}

// lists all students currently in the queue in a formatted table
void list_students(struct student *registration) {
    if (!registration) {
        printf("The queue is empty.\n");
        return;
    }

    // print table header
    printf("|----------------------|----------------------|---------|-----|----------|\n");
    printf("| Name                 | NetID                | COP2510 | GPA | Attempts |\n");
    printf("|----------------------|----------------------|---------|-----|----------|\n");

    struct student *current = registration;
    while (current) {
        // print each student's details
        printf("| %-20s | %-20s |       %c | %1.1f | %8d |\n",
               current->name, current->netid, current->cop2510_grade, current->gpa, current->attempts);
        printf("|----------------------|----------------------|---------|-----|----------|\n");
        current = current->next;  // move to the next student
    }
}

// lists students with a GPA greater than or equal to the specified value
void list_gpa_min(struct student *registration, double gpa) {
    if (!registration) {
        printf("The queue is empty.\n");
        return;
    }

    // print table header
    printf("|----------------------|----------------------|---------|-----|----------|\n");
    printf("| Name                 | NetID                | COP2510 | GPA | Attempts |\n");
    printf("|----------------------|----------------------|---------|-----|----------|\n");

    struct student *current = registration;
    int found = 0;

    while (current) {
        if (current->gpa >= gpa) {  // check GPA condition
            printf("| %-20s | %-20s |       %c | %1.1f | %8d |\n",
                   current->name, current->netid, current->cop2510_grade, current->gpa, current->attempts);
            printf("|----------------------|----------------------|---------|-----|----------|\n");
            found = 1;
        }
        current = current->next;  // move to the next student
    }

    if (!found) {
        printf("No students found with GPA >= %.1f\n", gpa);
    }
}

// lists students with a COP2510 grade less than or equal to the specified grade
void list_cop2510_min(struct student *registration, char cop2510_grade) {
    if (!registration) {
        printf("The queue is empty.\n");
        return;
    }

    // print table header
    printf("|----------------------|----------------------|---------|-----|----------|\n");
    printf("| Name                 | NetID                | COP2510 | GPA | Attempts |\n");
    printf("|----------------------|----------------------|---------|-----|----------|\n");

    struct student *current = registration;
    int found = 0;

    while (current) {
        if (current->cop2510_grade <= cop2510_grade) {  // check grade condition
            printf("| %-20s | %-20s |       %c | %1.1f | %8d |\n",
                   current->name, current->netid, current->cop2510_grade, current->gpa, current->attempts);
            printf("|----------------------|----------------------|---------|-----|----------|\n");
            found = 1;
        }
        current = current->next;  // move to the next student
    }

    if (!found) {
        printf("No students found with COP2510 grade >= %c\n", cop2510_grade);
    }
}

// clears the entire queue by freeing all allocated memory
struct student *clear_queue(struct student *registration) {
    struct student *current = registration;
    while (current) {
        struct student *next = current->next;  // save the next student
        free(current);                         // free the current student
        current = next;
    }
    return NULL;  // return NULL as the list is now empty
}
