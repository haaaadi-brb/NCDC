#include <stdio.h>

int main() {
    int n, i;
    float totalPoints = 0, totalCredits = 0, gpa, grade, credit;

    printf("Enter number of courses: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Enter credit hours for course %d: ", i);
        scanf("%f", &credit);

        printf("Enter grade points (e.g., 4.0, 3.5) for course %d: ", i);
        scanf("%f", &grade);

        totalPoints += credit * grade;
        totalCredits += credit;
    }

    gpa = totalPoints / totalCredits;
    printf("\nYour Semester GPA is: %.2f\n", gpa);

    return 0;
}
