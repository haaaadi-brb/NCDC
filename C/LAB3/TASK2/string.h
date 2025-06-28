#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100  // Define MAX_LEN correctly

int findLength(const char *str);
void toLowercase(char *str);
void toUppercase(char *str);
int countWords(const char *str);
int countVowels(const char *str);
void vowelFrequency(const char *str, int freq[5]);

#endif // STRING_H
