.text
.globl main

main:
    li x5, 0b00001111      # Example value in x5 (can be any number)
    li x10, 3              # Bit number to toggle (0-based indexing)

    li t1,1
    sll t2, t1, x10        # t0 = 1 << x10 → create bitmask
    xor x5, x5, t2         # Toggle the bit in x5

    # Print result using your custom print syscall method
    mv a1, x5              # move result to a1 for printing
    li a0, 1               # syscall: print integer
    ecall

    # Print newline (optional)
    

    # Exit
    li a0, 10
    ecall
