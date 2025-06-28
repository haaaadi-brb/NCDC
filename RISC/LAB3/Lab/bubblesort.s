.data
array:  .word 12, 5, 8, 1, 19, 7, 3, 15, 2, 10, 6, 4
n:      .word 12

.text
.globl main

main:
    la t0, n
    lw t1, 0(t0)        # t1 = n

    la t2, array        # t2 = base address of array

    li t3, 0            # t3 = i

outer_loop:
    blt t3, t1, outer_continue
    j print_array       # done sorting

outer_continue:
    li t4, 0            # t4 = j

    sub t5, t1, t3      # t5 = n - i
    addi t5, t5, -1     # t5 = n - i - 1

inner_loop:
    blt t4, t5, inner_continue
    addi t3, t3, 1      # i++
    j outer_loop

inner_continue:
    slli t6, t4, 2      # t6 = j * 4
    add a0, t2, t6      # a0 = &array[j]
    lw a1, 0(a0)        # a1 = array[j]

    addi t6, t6, 4
    add a2, t2, t6      # a2 = &array[j+1]
    lw a3, 0(a2)        # a3 = array[j+1]

    ble a1, a3, no_swap

    # Swap array[j] and array[j+1]
    sw a3, 0(a0)
    sw a1, 0(a2)

no_swap:
    addi t4, t4, 1
    j inner_loop

print_array:
    li t3, 0            # i = 0

print_loop:
    blt t3, t1, print_continue
    j done

print_continue:
    slli t4, t3, 2
    add t5, t2, t4
    lw a1, 0(t5)

    li a0, 1        # syscall print int
    ecall

    li a0, 11       # syscall print char
    li a1, 32       # space
    ecall

    addi t3, t3, 1
    j print_loop

done:
    li a0, 10       # syscall exit
    ecall
