#include <stdio.h>
#include "string.h"

int main() {
    char sentence[MAX_LEN];

    printf("Enter a sentence (max 100 characters): ");
    fgets(sentence, MAX_LEN, stdin);

    // Removing the newline character if present
    int len = findLength(sentence);
    if (sentence[len - 1] == '\n') {
        sentence[len - 1] = '\0';
    }

    printf("\nLength of sentence: %d\n", findLength(sentence));

    char lowercase[MAX_LEN], uppercase[MAX_LEN];
    strcpy(lowercase, sentence);
    strcpy(uppercase, sentence);

    toLowercase(lowercase);
    toUppercase(uppercase);

    printf("Sentence in lowercase: %s\n", lowercase);
    printf("Sentence in uppercase: %s\n", uppercase);
    printf("Number of words: %d\n", countWords(sentence));
    printf("Number of vowels: %d\n", countVowels(sentence));

    int freq[5] = {0};
    vowelFrequency(sentence, freq);

    printf("Vowel frequencies: A: %d, E: %d, I: %d, O: %d, U: %d\n",
           freq[0], freq[1], freq[2], freq[3], freq[4]);

    return 0;
}
        