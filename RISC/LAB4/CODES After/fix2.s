.data
# please don't change these!
n: .word 2
exp: .word 10

.text
main:
    # load the value of n into a0
    la a0 n
    lw a0 0(a0)

    # load the value of exp into a1
    la a1 exp
    lw a1 0(a1)

    # call ex2
    jal ra ex2

    # prints the output of ex2
    mv a1 a0
    li a0 1
    ecall # Print Result

    # exits the program
    li a0 17
    li a1 0
    ecall

ex2:
    addi sp, sp, -4     # Allocate 4 bytes of space on stack
    sw s0, 0(sp)        # Save s0 on the stack

    beq a1, x0, ex2_zero_case

    mv s0, a0
    addi a1, a1, -1
    jal ra, ex2
    mul a0, a0, s0
    j ex2_end

ex2_zero_case:
    li a0, 1

ex2_end:
    lw s0, 0(sp)        # Restore s0
    addi sp, sp, 4      # Free up the space on stack
    jr ra
