.text
.globl main

main:
    # Load the upper 20 bits
    lui x5, 0x12345        # x5 = 0x12345000

    # OR immediate with lower bits
    ori a1, x5, 0x678      # a1 = 0x12345678

    # Print a1 as an integer (decimal)
    li a0, 1               # syscall code for print_int
    mv a1, a1              # a1 already has the value
    ecall

    # Print newline (ASCII 10)
    li a0, 11              # syscall code for print_char
    li a1, 10              # newline character
    ecall

    # Exit
    li a0, 10
    ecall
