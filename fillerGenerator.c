/*  Name: Filler Generator
    Creator: Adam Douglas
    Date: 01-06-2016
    Purpose: To output randomly generated words to a sequential file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include "fillerGenerator.h"

#define FALSE 0
#define TRUE 1

int main (int argc, char *argv[]) {
    int programLoop = TRUE;
    int numWords;
    int count = 0;

    while (programLoop) {
        // Initialise a seed for random generation
        srand (time (NULL));
    
        // Print the program title
        printTitle ("Filler Generator");
        
        // Get number of words from user input
        numWords = getWords ();
    
        // Iteratively call function to send a randomly generated word
        while (count < numWords) {
            addWord ();
    
            count++;
        }

        // Get user input on looping the program
        printf ("Repeat the program? Enter 1 or 0: ");
        scanf ("%d", &programLoop);
    }
}

void printTitle (char *title) {
    int len = strlen (title);
    int count = 0;
    
    // Print the title followed by dashes and newlines
    printf ("%s\n", title);
    
    while (count < len) {
        printf ("=");
        count++;
    }
    
    printf ("\n\n");
}

int getWords (void) {
    int num;
    
    // Get user input on the number of words to generate
    printf ("How many words to generate?\n");
    scanf ("%d", &num);
    
    return num;
}

void addWord (void) {
    FILE *file;
    file = fopen ("filler.txt", "a");

    // Randomly generate the word length from 2-10 characters
    int wordLength = rand() % 8 + 2;
    int count = 0;
    char word[wordLength+1];
    
    // Generate the word one character at a time
    while (count < wordLength) {
        word[count] = rand() % 26 + 97;
        
        count++;
    }
    word[count] = '\0';
    
    // Append the word to the sequential file
    fprintf (file, "%s ", word);
}
