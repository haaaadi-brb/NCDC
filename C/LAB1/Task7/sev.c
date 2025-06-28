#include <stdio.h>

// Function to calculate extrema
void find_extrema(double a, double b, double c) {
    if (a == 0) {
        printf("Not a quadratic equation.\n");
        return;
    }

    double x = -b / (2 * a);  // x-coordinate of vertex
    double y = a * x * x + b * x + c;  // y-coordinate of vertex

    printf("Extrema at x = %.2f, y = %.2f\n", x, y);

    if (a > 0)
        printf("This is a Minimum point.\n");
    else
        printf("This is a Maximum point.\n");
}

int main() {
    double a, b, c;

    // Input quadratic equation coefficients
    printf("Enter coefficients a, b, and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // Find and display extrema
    find_extrema(a, b, c);

    return 0;
}
