#include <stdio.h>

int main() {
    float V1, R1, R2, R3, i1, i2, i3;

    // Take user input
    printf("Enter Voltage (V1): ");
    scanf("%f", &V1);

    printf("Enter Resistance R1: ");
    scanf("%f", &R1);

    printf("Enter Resistance R2: ");
    scanf("%f", &R2);

    printf("Enter Resistance R3: ");
    scanf("%f", &R3);

    // Calculate currents using Ohm's Law
    i1 = V1 / R1;
    i2 = V1 / R2;
    i3 = i1 - i2;  // Using Kirchhoff’s Current Law

    // Print results
    printf("\nCalculated Currents:\n");
    printf("i1 = %.2f A\n", i1);
    printf("i2 = %.2f A\n", i2);
    printf("i3 = %.2f A\n", i3);

    return 0;
}
