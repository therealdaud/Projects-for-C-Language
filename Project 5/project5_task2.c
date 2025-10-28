/*Daud Ahmad Nisar
This code reads two words entered as command-line arguments and calculates their respective scores based
on specific instructions and determines which word has more points, and thus the winner between Marjorie and John.*/


#include <stdio.h>
#include <ctype.h>

// function that calculates the score of a word
int calculate_score(char *word) {
    int score = 0;
    while (*word != '\0') {
        char c = tolower(*word);  // convert character to lowercase
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            score += 1;  // 1 point for vowels
        } else if (c == 't' || c == 'n' || c == 's' || c == 'r' || c == 'h') {
            score += 2;  // 2 points for common consonants
        } else if (c >= 'a' && c <= 'z') {
            score += 3;  // 3 points for all other letters
        }
        word++;  // move to next character
    }
    return score;
}

int main(int argc, char *argv[]) {
    // check if the number of arguments is 3
    if (argc != 3) {
        printf("invalid number of arguments\n");
        return 1;
    }

    // calculate scores for the two words
    int score1 = calculate_score(argv[1]);
    int score2 = calculate_score(argv[2]);

    // determine the winner based on scores
    if (score1 > score2) {
        printf("Marjorie wins!\n");
    } else if (score2 > score1) {
        printf("John wins!\n");
    } else {
        printf("Play again!\n");
    }

    return 0;
}



