/*Daud Ahmad Nisar
This C program splits a two word string into two strings each containing 
one word and it ignores the white space between the two words.*/


#include <stdio.h>

// read_line function (pointer version) from lecture
int read_line(char *str, int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n') {
        if (i < n) {
            *str++ = ch;
            i++;
        }
    }
    *str = '\0';  // null terminate the string
    return i;     // return number of characters stored
}

// split the input string into two words
void split(char *input, char *word1, char *word2) {
    // skip white spaces
    while (*input == ' ') {
        input++;
    }

    // extract the first word
    while (*input != ' ' && *input != '\0') {
        *word1 = *input;
        word1++;
        input++;
    }
    *word1 = '\0';  // null terminate the first word

    // skip spaces between words
    while (*input == ' ') {
        input++;
    }

    // extract the second word
    while (*input != ' ' && *input != '\0') {
        *word2 = *input;
        word2++;
        input++;
    }
    *word2 = '\0';  // null terminate the second word
}

int main() {
    char input[1001];  // input string with max length 1000 characters
    char word1[501], word2[501];  // arrays for storing the two words resulting from the breakdown of input string

    printf("Enter input: ");
    read_line(input, 1000);  // read the input using the read_line function

    // split the input string into two words
    split(input, word1, word2);

    // display results
    printf("Word #1: %s\n", word1);
    printf("Word #2: %s\n", word2);

    return 0;
}

