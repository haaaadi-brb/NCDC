.data
n: .word 5          # Change this value to test different factorials

.text
.globl main

main:
    la t0, n
    lw a0, 0(t0)         # Load n into a0
    jal ra, factorial    # Call factorial function

    addi a1, a0, 0      # Prepare argument for print int syscall
    li a0, 1            # Syscall code for print integer
    ecall

    addi a1, x0, '\n'   # Prepare newline char
    li a0, 11           # Syscall code for print char
    ecall

    li a0, 10           # Syscall code for exit
    ecall

# factorial: iterative factorial function
# Input: a0 = n
# Output: a0 = n!
factorial:
    li t0, 1            # i = 1
    li t1, 1            # result = 1

loop:
    bgt t0, a0, end_loop    # if i > n, end loop

    mul t1, t1, t0          # result *= i
    addi t0, t0, 1          # i++

    j loop

end_loop:
    mv a0, t1               # Move result to a0 to return
    jr ra                   # Return to caller
