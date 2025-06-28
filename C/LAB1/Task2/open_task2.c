#include <stdio.h>

int main() {
    char chChar;

    // Take user input
    printf("Enter a character: ");
    scanf(" %c", &chChar);  // Space before %c to ignore newline

    // Display entered character
    printf("You entered: %c\n", chChar);

    // ASCII Value of the character
    printf("ASCII Value: %d\n", chChar);

    // Add 7 to character and print new value
    chChar = chChar + 7;
    printf("After adding 7: %c\n", chChar);

    // Set it to 'd' and print
    chChar = 'd';
    printf("Final character: %c\n", chChar);

    // 🔹 Display size of different data types
    printf("\n----- Data Type Sizes -----\n");
    printf("Size of char: %lu byte\n", sizeof(char));
    printf("Size of int: %lu bytes\n", sizeof(int));
    printf("Size of float: %lu bytes\n", sizeof(float));
    printf("Size of double: %lu bytes\n", sizeof(double));

    return 0;
}
