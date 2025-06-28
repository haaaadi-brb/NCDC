.text
.globl main

main:
    # Load an example value into a1
   addi a1,x0,0xFFFFFFFF     # Example value to complement

    # Compute 1's complement: ~a1 = -1 - a1
    addi a2,x0,-1                # a2 = -1 = 0xFFFFFFFF
    sub a1, a2, a1           # a1 = -1 - a1 = ~a1

    # Print result (optional: print as signed int)
    li a0, 1                 # syscall code: print integer
    ecall

    # Exit
    li a0, 10
    ecall
check


