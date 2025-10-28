/* Daud Ahmad Nisar
This code determines if a sequence is a good one or not based on specific
instructions, which are that each number should either be a perfet square 
or it should be less than the total numbers in the sequence. */



#include <stdio.h>

// function to check if number is a perfect square of an integer less than n
int perf_sq(int num, int n) {
    for (int j = 0; j < n; j++) {
        if (j * j == num) {
            return 1;  // num is a perfect square of j
        }
    }
    return 0;  // num is not a perfect square of integer less than n
}

// function to check if the sequence is good
int good_sequence(int n, int sequence[]) {
    for (int i = 0; i < n; i++) {
        int num = sequence[i];
        
        // condition 1: check if 0 <= num < n
        if (num >= 0 && num < n) {
            continue;  // valid number, move to next number
        }
        
        // Condition 2: check if num is a perfect square of some integer less than n
        if (!perf_sq(num, n)) {
            return 0;  // if neither condition is satisfied, it is not a good sequence
        }
    }
    
    return 1;  // all elements satisfy the conditions
}

int main() {
    int n;
    
    // input the size of sequence
    printf("Enter the size of sequence: ");
    scanf("%d", &n);
    
    int sequence[n];
    
    // input the sequence of numbers
    printf("Enter numbers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence[i]);
    }
    
    // check if the sequence is good and print the result
    if (good_sequence(n, sequence)) {
        printf("Output: yes\n");
    } else {
        printf("Output: no\n");
    }
    
    return 0;
}
