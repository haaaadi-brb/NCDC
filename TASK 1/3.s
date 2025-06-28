.text
.globl main

main:
    li x5, 8          # Load example number

    andi a1, x5, 1    # a1 = x5 & 1 → 0 if even, 1 if odd

    li a0, 1          # syscall code: print integer
    ecall             # print a1

    li a0, 10         # syscall code: exit
    ecall
