.globl f

# f takes two arguments:
# a0: the input value to evaluate f at (must be in -3..3)
# a1: pointer to the output array [f(-3), f(-2), ..., f(3)]
# returns value f(a0) in a0

f:
addi t0, a0, 3       # convert domain [-3..3] to index [0..6]
slli t0, t0, 2       # multiply index by 4 (word size)
add t1, a1, t0       # compute effective address of f(a0)
lw a0, 0(t1)         # load the value at that address into a0
jr ra                # return
