.data
msg: .asciiz "After toggle: "

.text
.globl main

main:
    li t0, 0b10101010     # Your number
    li t1, 0              # Bit position to toggle

    li t2, 1
    sll t2, t2, t1        # mask = 1 << pos
    xor t3, t0, t2        # toggle bit

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
s