#include "string.h"

int findLength(const char str) {
    return strlen(str);
}

void toLowercase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

void toUppercase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

int countWords(const char str[]) {
    int count = 0, inWord = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            count++;
        }
    }
    return count;
}

int countVowels(const char str[]) {
    int count = 0;
    char vowels[] = "aeiouAEIOU";
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (strchr(vowels, str[i])) {
            count++;
        }
    }
    return count;
}

void vowelFrequency(const char str[], int freq[5]) {
    for (int i = 0; i < 5; i++) freq[i] = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        switch (tolower(str[i])) {
            case 'a': freq[0]++; break;
            case 'e': freq[1]++; break;
            case 'i': freq[2]++; break;
            case 'o': freq[3]++; break;
            case 'u': freq[4]++; break;
        }
    }
}
