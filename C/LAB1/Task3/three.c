#include <stdio.h>

int main() {
    char lastCharName = 'i';  // Last letter of "Hadi"
    char lastCharCMS = '0';   // Last digit of CMS ID "413970"

    printf("Name: %c%c%c%c\n", 72, 97, 100, lastCharName);  // ASCII for "Hadi"
    printf("CMS ID: %d%d%d%d%d%c\n", 4, 1, 3, 9, 7, lastCharCMS);  // CMS ID

    return 0;
}
