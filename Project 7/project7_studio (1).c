/* Daud Ahmad Nisar
This C program reads customer data from a file, filters customers based on the number of 
lessons they’ve taken, and writes the filtered data to an output file in CSV format.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 200 // maximum number of customers allowed
#define MAX_CHAR 100      // maximum length for email and name strings

// structure to store customer data
struct customer {
    char email[MAX_CHAR]; // customers email address
    int lessons;          // number of lessons customer has taken
    char name[MAX_CHAR];  // customers name
};

// function prototype for searching customers based on lessons
int search(struct customer list[], int n, int num_lessons, struct customer result[]);

int main() {
    struct customer customers[MAX_CUSTOMERS];        
    struct customer filtered_customers[MAX_CUSTOMERS]; 
    int customer_count = 0;                          
    int filtered_count = 0;                          
    int num_lessons;                                 
    char output_file_name[MAX_CHAR] = "result.csv";  
    FILE *input_file, *output_file;

    // open the input file for reading customer data
    input_file = fopen("customers.csv", "r");
    if (!input_file) { // check if the file is successfully opened
        printf("Error: Unable to open file customers.csv\n");
        return 1;
    }

    // read data from the input file line by line
    while (fscanf(input_file, "%[^,],%d,%[^\n]\n", customers[customer_count].email,
                  &customers[customer_count].lessons, customers[customer_count].name) != EOF) {
        customer_count++; 
    }
    fclose(input_file);

    // prompt user to enter the minimum number of lessons for filtering
    printf("Enter number of lessons: ");
    scanf("%d", &num_lessons); // read user input
    printf("Output file name: %s\n", output_file_name); // display output file name

    // search for customers who have taken more than the specified number of lessons
    filtered_count = search(customers, customer_count, num_lessons, filtered_customers);

    // open the output file for writing filtered results
    output_file = fopen(output_file_name, "w");
    if (!output_file) { // check if the file is successfully opened
        printf("Error: Unable to create output file %s\n", output_file_name);
        return 1;
    }

    // write filtered customer data to the output file
    for (int i = 0; i < filtered_count; i++) {
        fprintf(output_file, "%s,%d,%s\n", filtered_customers[i].email,
                filtered_customers[i].lessons, filtered_customers[i].name);
    }
    fclose(output_file); // close the output file after writing

    printf("Filtered data written to %s\n", output_file_name);
    return 0;
}


// the number of customers who meet the filtering criteria
int search(struct customer list[], int n, int num_lessons, struct customer result[]) {
    int count = 0; // counter for the number of filtered customers

    // iterate through customers
    for (int i = 0; i < n; i++) {
        if (list[i].lessons > num_lessons) { 
            result[count] = list[i];
            count++; 
        }
    }
    return count;
}
