/* Daud Ahmad Nisar
This code calculates the number of oscillating grades after the user 
inputs the total number of grades and the grades itself.*/

#include <stdio.h>

int main() {
    int total_grades; // store the total number of grades

    // ask user for number of grades and read the number of grades
    printf("Enter the number of grades: ");
    scanf("%d", &total_grades);

    int grades[total_grades];  // array to store the grades

    // ask user and read the grades
    printf("Enter the grades: ");
    for (int i = 0; i < total_grades; i++) {
        scanf("%d", &grades[i]);
    }

    int osc_count = 0;  // count of oscillating performances

    // loop through the grades starting from the second one
    for (int i = 1; i < total_grades; i++) {
        int greatest = 1;  // suppose the current grade is strictly greatest
        int smallest = 1;  // suppose the current grade is strictly smallest

        // check the current grade against all previous grades
        for (int j = 0; j < i; j++) {
            if (grades[i] <= grades[j]) {
                greatest = 0;  // if the current grade is less than or equal to any previous grade
            }
            if (grades[i] >= grades[j]) {
                smallest = 0;  // if the current grade is greater than or equal to any previous grade
            }
        }

        // if the grade is strictly greater or strictly smaller than all previous grades
        if (greatest || smallest) {
            osc_count++;
        }
    }

    // Print the result as the number of oscillating performances
    printf("%d\n", osc_count);

    return 0;
}
