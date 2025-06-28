#include <stdio.h>
#include <math.h>

#define SIZE 5

// Function to calculate mean
double mean(int arr[]) {
    double sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += arr[i];
    }
    return sum / SIZE;
}

// Function to calculate median
double median(int arr[]) {
    // Sort array (Simple Bubble Sort)
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr[SIZE / 2]; // Middle value
}

// Function to calculate mode
int mode(int arr[]) {
    int maxCount = 0, modeVal = arr[0];

    for (int i = 0; i < SIZE; i++) {
        int count = 0;
        for (int j = 0; j < SIZE; j++) {
            if (arr[j] == arr[i])
                count++;
        }
        if (count > maxCount) {
            maxCount = count;
            modeVal = arr[i];
        }
    }
    if (maxCount == 1) return -1; // No mode
    return modeVal;
}

// Function to calculate standard deviation
double standardDeviation(int arr[]) {
    double m = mean(arr);
    double sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += pow(arr[i] - m, 2);
    }
    return sqrt(sum / SIZE);
}

int main() {
    int numbers[SIZE];

    // Taking input
    printf("Enter 5 numbers: ");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &numbers[i]);
    }

    // Printing results
    printf("Mean: %.2f\n", mean(numbers));
    printf("Median: %.2f\n", median(numbers));

    int modeVal = mode(numbers);
    if (modeVal == -1)
        printf("Mode: No mode (all numbers appear once)\n");
    else
        printf("Mode: %d\n", modeVal);

    printf("Standard Deviation: %.2f\n", standardDeviation(numbers));

    return 0;
}
