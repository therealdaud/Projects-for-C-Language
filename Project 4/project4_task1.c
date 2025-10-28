/*Daud Ahmad Nisar
This code is for a board game between Marjorie and John, where they alternate turns picking 
numbers from either end of a sequence. The winner is the one with the highest sum.*/

#include <stdio.h>

void round_result(int *board, int n) {
    int marjorie_score = 0, john_score = 0;
    int *left = board;        // pointer to the first element
    int *right = board + n - 1; // pointer to the last element
    int turn = 1; // 1 for marjorie, 0 for john (default starting with Marjorie)

    while (left <= right) {
        // select the largest available number
        if (*left > *right) {
            if (turn == 1) { // marjorie's turn
                marjorie_score += *left;
            } else { // john's turn
                john_score += *left;
            }
            left++;
        } else {
            if (turn == 1) { // marjorie's turn
                marjorie_score += *right;
            } else { // john's turn
                john_score += *right;
            }
            right--;
        }
        // alternate turns
        turn = 1 - turn;
    }

    if (marjorie_score > john_score) {
        printf("Marjorie\n");
    } else if (john_score > marjorie_score) {
        printf("John\n");
    } else {
        printf("Draw\n");
    }
}

int main() {
    int T;
    scanf("%d", &T); // number of rounds

    for (int a = 0; a < T; a++) {
        int N;
        scanf("%d", &N); // amount of numbers in the board
        int board[N];
        
        for (int b = 0; b < N; b++) {
            scanf("%d", board + b); // read the numbers into the board using pointer arithmetic
        }

        if (a % 2 == 0) {
            // odd rounds start with marjorie
            round_result(board, N);
        } else {
            // even rounds start with john
            // Swap the initial turn to start with John
            int marjorie_score = 0, john_score = 0;
            int *left = board;
            int *right = board + N - 1;
            int turn = 0; // Starting with John

            while (left <= right) {
                // select the largest available number
                if (*left > *right) {
                    if (turn == 1) { // marjorie's turn
                        marjorie_score += *left;
                    } else { // john's turn
                        john_score += *left;
                    }
                    left++;
                } else {
                    if (turn == 1) { // marjorie's turn
                        marjorie_score += *right;
                    } else { // john's turn
                        john_score += *right;
                    }
                    right--;
                }
                // alternate turns
                turn = 1 - turn;
            }

            if (marjorie_score > john_score) {
                printf("Marjorie\n");
            } else if (john_score > marjorie_score) {
                printf("John\n");
            } else {
                printf("Draw\n");
            }
        }
    }

    return 0;
}
