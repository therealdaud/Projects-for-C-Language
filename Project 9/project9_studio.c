/* Daud Ahmad Nisar
A program to process customer data from a CSV file, sort it by lessons
in descending order, and save the sorted results to another CSV file.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 200 // maximum number of customers allowed
#define MAX_CHAR 100      // maximum length for email and name strings

// structure to store customer data
struct customer {
    char email[MAX_CHAR]; // customer's email address
    int lessons;          // number of lessons the customer has taken
    char name[MAX_CHAR];  // customer's name
};

// comparison function for qsort (descending order)
int compare_customers(const void *a, const void *b) {
    struct customer *custA = (struct customer *)a;
    struct customer *custB = (struct customer *)b;
    return (custB->lessons - custA->lessons);
}

int main() {
    struct customer customers[MAX_CUSTOMERS];
    int customer_count = 0;
    char input_file_name[] = "customers.csv"; // input file name
    char output_file_name[] = "result.csv";  // output file name
    FILE *input_file, *output_file;

    // open the input file
    input_file = fopen(input_file_name, "r");
    if (!input_file) {
        printf("Error: Unable to open file %s\n", input_file_name);
        return 1;
    }

    // read data from the input file
    while (fscanf(input_file, "%[^,],%d,%[^\n]\n", customers[customer_count].email,
                  &customers[customer_count].lessons, customers[customer_count].name) != EOF) {
        customer_count++;
        if (customer_count >= MAX_CUSTOMERS) {
            printf("Warning: Maximum number of customers reached. Some data may not be read.\n");
            break;
        }
    }
    fclose(input_file);

    // sort customers using qsort in descending order
    qsort(customers, customer_count, sizeof(struct customer), compare_customers);

    // open output file
    output_file = fopen(output_file_name, "w");
    if (!output_file) {
        printf("Error: Unable to create file %s\n", output_file_name);
        return 1;
    }

    // write sorted data to output file
    for (int i = 0; i < customer_count; i++) {
        fprintf(output_file, "%s, %d,   %s\n", customers[i].email, customers[i].lessons, customers[i].name);
    }
    fclose(output_file);

    printf("Sorted data written to %s\n", output_file_name);
    return 0;
}

