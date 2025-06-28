.text
.globl main

main:
    li x5, 0x12F7C4D8        # 32-bit value to extract byte from
    li x6, 2                 # Select byte number (0 for LSB to 3 for MSB)

    li x7, 8
    mul x7, x6, x7           # x7 = x6 * 8 → shift amount
    srl x10, x5, x7          # Shift x5 >> (x6*8)
    andi x10, x10, 0xFF      # Mask to keep only 1 byte (lowest 8 bits)

    # Sign extend the byte manually
    slli x11, x10, 24        # Shift left to position byte in MSB
    srai x11, x11, 24        # Arithmetic right shift to sign-extend
    mv x10, x11              # Result now in x10

    # Print result
    mv a1, x10               # Move to a1 for printing
    li a0, 1                 # Syscall: print integer
    ecall

    # Exit program
    li a0, 10                # Syscall: exit
    ecall
