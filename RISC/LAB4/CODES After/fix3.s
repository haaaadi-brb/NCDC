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

    # call ex3
    jal ra ex3

    # prints the output of ex3
    mv a1 a0
    li a0 1
    ecall # Print Result

    # exits the program
    li a0 17
    li a1 0
    ecall
ex3:
    addi sp, sp, -4
    sw ra, 0(sp)

    # return 1 if a1 == 0
    beq a1, x0, ex3_zero_case

    # otherwise, return ex3(a0, a1-1) * a0
    mv t0, a0      # save a0 in t0
    addi a1, a1, -1 # decrement a1

    jal ra, ex3    # call ex3(a0, a1-1)

    mul a0, a0, t0  # multiply ex3(a0, a1-1) by t0

    j ex3_end

ex3_zero_case:
    li a0, 1

ex3_end:
    lw ra, 0(sp)
    addi sp, sp, 4
    jr ra
