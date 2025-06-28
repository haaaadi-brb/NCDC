#include <stdio.h>

int main() {
    int c;
    printf("Start typing. Press Ctrl+D (Linux/Mac) or Ctrl+Z then Enter (Windows) to stop.\n");

    while ((c = getchar()) != EOF) {
        printf("%c", c);
    }

    printf("\nEnd of input detected.\n");
    return 0;
}
