/* Daud Ahmad Nisar
This C program tokenizes text by converting unique words from an input file 
into numbers in alphabetical order, outputting the words and their 
corresponding tokenized form.*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000         // maximum number of unique words
#define MAX_WORD_LENGTH 100     // maximum length of each word
#define MAX_LINE_LENGTH 1000    // maximum length of each line in the input

// structure to store each unique word with its assigned id
typedef struct {
    char word[MAX_WORD_LENGTH];
    int id;
} Word;

// function that will compare two words alphabetically for sorting
int compare(const void *a, const void *b) {
    return strcmp(((Word *)a)->word, ((Word *)b)->word);
}

// function to find a word in the array of words
// returns the index of the word if found, otherwise -1
int find_word(Word *words, int count, const char *word) {
    for (int i = 0; i < count; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

// function to tokenize the input file, assign word ids, and produce the output file
void tokenize_file(const char *input_file, const char *output_file) {
    FILE *infile = fopen(input_file, "r");
    FILE *outfile = fopen(output_file, "w");

    // check if file was opened successfully
    if (!infile || !outfile) {
        fprintf(stderr, "Error opening files.\n");
        exit(EXIT_FAILURE);
    }

    Word words[MAX_WORDS];       // array to store unique words
    int word_count = 0;          // count of unique words
    char line[MAX_LINE_LENGTH];  // buffer for each line read from the file
    char *token;                 // pointer for tokenizing lines

    // read the file and collect unique words
    while (fgets(line, sizeof(line), infile)) {
        // convert the line to lowercase
        for (char *p = line; *p; ++p) *p = tolower(*p);

        // tokenize the line by spaces, fullstops, and newlines
        token = strtok(line, " .\n");

        while (token != NULL) {
            // add the word to the unique words array if it is not already there
            if (find_word(words, word_count, token) == -1) {
                strcpy(words[word_count].word, token);
                word_count++;
            }
            token = strtok(NULL, " .\n");
        }
    }

    // sort unique words alphabetically and assign ids
    qsort(words, word_count, sizeof(Word), compare);
    for (int i = 0; i < word_count; i++) {
        words[i].id = i + 1;  // assign ids starting from 1
    }

    // output number of unique words and each word with its id
    fprintf(outfile, "%d\n", word_count);         // print total unique word count
    for (int i = 0; i < word_count; i++) {
        fprintf(outfile, "%s\n", words[i].word);  // print each unique word
    }

    // reset file pointer to start reading the input file again
    rewind(infile);

    // process every sentence for token ids based on fullstops
    while (fgets(line, sizeof(line), infile)) {
        // convert the line to lowercase for consistent comparison
        for (char *p = line; *p; ++p) *p = tolower(*p);

        // tokenize the line by spaces and newlines
        token = strtok(line, " \n");
        int first_word = 1;  // flag to manage spaces between ids in the output

        while (token != NULL) {
            // check if the token contains a fullstop at the end
            char *period_position = strchr(token, '.');
            if (period_position) {
                *period_position = '\0';  // temporarily remove the period for id lookup
            }

            // find the id of the current word in the unique words array
            int idx = find_word(words, word_count, token);

            // print a space between ids if it's not the first word in the sentence
            if (!first_word) {
                fprintf(outfile, " ");
            }
            first_word = 0;  // reset flag after the first word

            // print the word id
            fprintf(outfile, "%d", words[idx].id);

            // if a fullstop was detected, end the current line for the sentence
            if (period_position) {
                fprintf(outfile, "\n");  // newline to indicate the end of the sentence
                first_word = 1;          // reset flag for the next sentence
            }

            // move to the next word token
            token = strtok(NULL, " \n");
        }
    }

    // close both input and output files
    fclose(infile);
    fclose(outfile);
}

// main function to handle command-line arguments and initiate file processing
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    tokenize_file(argv[1], argv[2]);
    return EXIT_SUCCESS;
}

