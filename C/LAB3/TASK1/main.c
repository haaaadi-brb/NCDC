#include <stdio.h>
#include <math.h>

#define N 50 
#define PI 3.14159265

double v[N];  

void initialize_signal() {
    for (int i = 0; i < N; i++) {
        double t = (double)i / N;  
        v[i] = sin(2 * PI * t);

    }
}

double compute_dc_value() {
    double sum = 0;
    for (int i = 0; i < N; i++) {
        sum += v[i];
    }
    return sum / N;
}

void detect_crossings() {
    for (int i = 0; i < N - 1; i++) {
        if ((v[i] > 0 && v[i + 1] < 0) || (v[i] < 0 && v[i + 1] > 0)) {
            printf("Zero crossing at index %d\n", i);
        }
    }
}

void detect_glitches() {
    for (int i = 1; i < N - 1; i++) {
        if (fabs(v[i] - v[i - 1]) > 0.5 && fabs(v[i] - v[i + 1]) > 0.5) {
            printf("Possible glitch detected at index %d\n", i);
        }
    }
}

int main() {
    initialize_signal();
    printf("DC Value: %lf\n", compute_dc_value());
    printf("\nDetecting Zero Crossings:\n");
    detect_crossings();
    printf("\nDetecting Glitches:\n");
    detect_glitches();
    return 0;
}
