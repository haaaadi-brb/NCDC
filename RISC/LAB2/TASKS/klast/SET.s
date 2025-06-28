.data
msg: .asciiz "After set: "

.text
.globl main

main:
    li t0, 0b00000000     # Your number
    li t1, 0              # Bit position to set

    li t2, 1
    sll t2, t2, t1        # mask = 1 << pos
    or t3, t0, t2         # set the bit

    # Print result message
    li a0, 4
    la a1, msg
    ecall

    # Print result
    li a0, 1
    mv a1, t3
    ecall

    # Exit
    li a0, 10
    ecall
