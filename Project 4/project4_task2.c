/*Daud Ahmad Nisar
This code counts how many times each number appears before and after its 
position in a dynamically allocated list using pointer arithmetic.*/


#include <stdio.h>
#include <stdlib.h>

void before_after(int *array, int n) {
    for (int *ptr = array; ptr < array + n; ptr++) {
        int B = 0, A = 0;
        //count occurrences before the current position
        for (int *prev = array; prev < ptr; prev++) {
            if (*prev == *ptr) {
                B++;
            }
        }
        //count occurrences after the current position
        for (int *next = ptr + 1; next < array + n; next++) {
            if (*next == *ptr) {
                A++;
            }
        }
        //print the results for the current position
        printf("%d %d\n", B, A);
    }
}

int main() {
    int n;
    //reading the number of elements
    scanf("%d", &n);
    
    //dynamically allocate memory for the elements
    int *array = (int *)malloc(n * sizeof(int));
    
    //read the elements with pointer arithmetic
    for (int *ptr = array; ptr < array + n; ptr++) {
        scanf("%d", ptr);
    }
    
    //call the function to calculate and print the before and after counts
    before_after(array, n);
    
    //free the dynamically allocated memory
    free(array);
    
    return 0;
}




