/* Daud Ahmad Nisar
This code reads two sequences of lowercase letters and calculates their score based
on specific instructions and determines which sequence has more points.*/


#include <stdio.h>

// caclulate score based on these sets of instructions
int score_sequence() {
    int score = 0;
    char c;

    // read characters one by one using getchar() until a newline character
    while ((c = getchar()) != '\n') {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            score += 1; // 1 point for vowels
        } else if (c == 't' || c == 'n' || c == 's' || c == 'r' || c == 'h') {
            score += 2; // 2 points for popular consonants
        } else if (c >= 'a' && c <= 'z') {
            score += 3; // 3 points for other letters
        }
        // ignore spaces
    }
    // return the score for the sequence
    return score;
}

int main() {
    int marjorie_score, john_score; //store score for each of marjorie and john
    // ask for score 
    printf("Enter the first sequence: ");
    marjorie_score = score_sequence();
    // ask for second score
    printf("Enter the second sequence: ");
    john_score = score_sequence();
    
    //check who is the winner based on scores
    if (marjorie_score > john_score) {
        printf("Marjorie wins!\n");  // marjorie wins
    } else if (john_score > marjorie_score) {
        printf("John wins!\n");  // john wins
    } else {
        printf("Play again!\n"); // if scores equal, then ask to play again
    }

    return 0;
}
