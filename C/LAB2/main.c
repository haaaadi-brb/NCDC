/****************************************************
 * Author: AbdulHadi Afzal
 * Task: Number System Converter (Decimal to Binary, Octal, Hex)
 ****************************************************/

#include <stdio.h>

// Function to convert and print binary representation
void printBinary(int n) {
    if (n > 1)
        printBinary(n / 2);
    printf("%d", n % 2);
}

int main() {
    int number;

    printf("Enter a decimal number: ");
    scanf("%d", &number);

    printf("Hexadecimal: %X\n", number);
    printf("Octal: %o\n", number);

    printf("Binary: ");
    printBinary(number);
    printf("\n");

    return 0;
}