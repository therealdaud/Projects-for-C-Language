/* Daud Ahmad Nisar
This code is to make sure that all numbers in an array are distinct and nothing is repeated,
it also makes sure that the numbers in the array are sorted in ascending order*/


#include <stdio.h>

// function to make sure all elements are distinct
int find_distinct(int numbers[], int n, int result[]) {
    int result_size = 0;

    // iterate through the numbers array
    for (int i = 0; i < n; i++) {
        int duplicate = 0;

        // check if numbers[i] is already in result array
        for (int j = 0; j < result_size; j++) {
            if (numbers[i] == result[j]) {
                duplicate = 1;
                break;
            }
        }

        // if not a duplicate, add to result
        if (!duplicate) {
            result[result_size] = numbers[i];
            result_size++;
        }
    }

    return result_size;  // return the number of distinct elements
}

// selection sort function from the textbook
void selection_sort(int array[], int n) {
    int i, j, min_index, temp;

    // going through all the elements
    for (i = 0; i < n - 1; i++) {
        min_index = i;

        // find the minimum element in unsorted part of array
        for (j = i + 1; j < n; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }

        // swap the found minimum element with the first element
        temp = array[min_index];
        array[min_index] = array[i];
        array[i] = temp;
    }
}

int main() {
    int n;

    // input the size of the sequence
    printf("Enter the size of sequence: ");
    scanf("%d", &n);

    int numbers[n];
    int result[n];  // this will hold the distinct numbers

    // input the sequence of numbers
    printf("Enter numbers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    // find the distinct numbers
    int result_size = find_distinct(numbers, n, result);

    // sort the distinct numbers
    selection_sort(result, result_size);

    // output the sorted distinct numbers
    printf("Output: ");
    for (int i = 0; i < result_size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
