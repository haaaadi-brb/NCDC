#include <stdio.h>
#include <unistd.h> // For sleep function on Linux/Mac
#include <windows.h> // For Sleep function on Windows

int main() {
    int minutes;
    
    // Asking the user to enter the number of minutes
    printf("Enter the number of minutes: ");
    
    // Validate input: Check if the user enters a valid integer
    if (scanf("%d", &minutes) != 1) {
        printf("Invalid input! Please enter an integer value.\n");
        return 1; // Exit with error code
    }

    // Simulating the stopwatch
    for (int m = 0; m < minutes; m++) {
        for (int s = 0; s < 60; s++) {
            printf("\r%02d:%02d", m, s); // Print time in MM:SS format
            fflush(stdout);
            Sleep(1000); // Wait for one second
        }
    }
    
    printf("\nStopwatch finished!\n");
    return 0;
}
