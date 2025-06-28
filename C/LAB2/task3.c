#include <stdio.h>

int main() {
    int n, i, checksum = 0, received_checksum, calculated_checksum = 0;

    // Asking for number of bytes
    printf("Enter the number of bytes in the data packet: ");
    scanf("%d", &n);

    int data[n]; // Array to store bytes

    // Taking input for the data bytes
    printf("Enter %d bytes (as integers):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &data[i]);
        checksum ^= data[i]; // Compute XOR checksum
    }

    // Append checksum to the packet
    printf("Generated Checksum: %d\n", checksum);

    // Simulate receiving process
    printf("\nReceiver Side:\n");
    printf("Enter the received %d bytes (including checksum):\n", n + 1);

    // Receiving data with checksum
    for (i = 0; i <= n; i++) {
        scanf("%d", &received_checksum);
        calculated_checksum ^= received_checksum; // Compute XOR again
    }

    // Check if checksum is valid
    if (calculated_checksum == 0) {
        printf("Data is CORRECT (Checksum Matched)\n");
    } else {
        printf("Data is CORRUPTED (Checksum Mismatch)\n");
    }

    return 0;
}
