.text
.globl main

main:
    li x5, 0x3
    li x6, 0x4
    bge x5, x6, set_one       
    
    li x10, 0                 # If x5 < x6 → x10 = 0
    j print_result

set_one:
    li x10, 1                 # If x5 >= x6 → x10 = 1

print_result:
    mv a1, x10                # Move result to a1 for printing
    li a0, 1                  # syscall: print int
    ecall

    li a0, 11                 # syscall: print char
    li a1, 10                 # newline
    ecall

    li a0, 10                 # syscall: exit
    ecall
