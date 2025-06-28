.text
.globl main

main:
    li x5, 0x12F7C4D8       # Example word
    li x6, 2                # Byte index (0 = LSB, 3 = MSB)

    li x7, 8                # x7 = 8
    mul x7, x6, x7          # x7 = x6 * 8
    srl x10, x5, x7         # Shift right by (8 * index)
    andi x10, x10, 0xFF     # Mask to keep only 1 byte

    mv a1, x10              # Move result to a1 for printing
    li a0, 1                # Print integer syscall
    ecall

    li a0, 10               # Exit syscall
    ecall
