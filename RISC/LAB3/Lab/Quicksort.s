.data
array:      .word -1, 22, 8, 35, 5, 4, 11, 2, 1, 78
array_size: .word 10

.text
.globl main

main:
    la s0, array            # s0 = base address of array (never changed)
    li a0, 0                # a0 = low index
    li a1, 9                # a1 = high index (n - 1)
    jal quicksort           # sort array from 0 to 9

    jal print_array         # print sorted array

    li a0, 10               # syscall: exit
    li a1, 0
    ecall

# -----------------------------
# void quicksort(int low, int high)
# a0 = low, a1 = high
# -----------------------------
quicksort:
    addi sp, sp, -16     # allocate stack space (4 bytes * 4)
    sw ra, 12(sp)        # save ra at sp+12
    sw s1, 8(sp)         # save s1 at sp+8
    sw s2, 4(sp)         # save s2 at sp+4

    bge a0, a1, qs_return

    mv s1, a0
    mv s2, a1
    jal partition

    mv a0, s1
    mv a1, a2
    addi a1, a1, -1
    jal quicksort

    mv a0, a2
    addi a0, a0, 1
    mv a1, s2
    jal quicksort

qs_return:
    lw ra, 12(sp)        # restore ra
    lw s1, 8(sp)         # restore s1
    lw s2, 4(sp)         # restore s2
    addi sp, sp, 16      # restore stack pointer
    ret

# -----------------------------
# int partition(int low, int high)
# returns pivot index in a2
# -----------------------------
partition:
    slli t0, a1, 2
    add t0, s0, t0
    lw t1, 0(t0)            # t1 = pivot = array[high]

    addi t2, a0, -1         # t2 = i = low - 1
    mv t3, a0               # t3 = j = low

partition_loop:
    bge t3, a1, partition_done

    slli t4, t3, 2
    add t5, s0, t4
    lw t6, 0(t5)            # t6 = array[j]

    ble t6, t1, do_swap

skip_swap:
    addi t3, t3, 1
    j partition_loop

do_swap:
    addi t2, t2, 1
    slli t4, t2, 2
    add t4, s0, t4

    lw t6, 0(t5)            # t6 = array[j]
    lw t5, 0(t4)            # t5 = array[i]
    sw t6, 0(t4)
    
    slli t6, t3, 2
    add t6, s0, t6
    sw t5, 0(t6)

    j skip_swap

partition_done:
    addi t2, t2, 1
    slli t4, t2, 2
    add t4, s0, t4

    slli t5, a1, 2
    add t5, s0, t5
    lw t6, 0(t5)
    lw t5, 0(t4)
    sw t6, 0(t4)

    slli t6, a1, 2
    add t6, s0, t6
    sw t5, 0(t6)

    mv a2, t2              # return pivot index
    ret

# -----------------------------
# void print_array()
# -----------------------------
print_array:
    li t0, 0               # index = 0

print_loop:
    li t2, 10              # array size
    bge t0, t2, done_print

    slli t3, t0, 2
    add t4, s0, t3
    lw a1, 0(t4)           # a1 = array[i]
    li a0, 1               # syscall: print_int
    ecall

    li a0, 11              # syscall: print_char
    li a1, 32              # space
    ecall

    addi t0, t0, 1
    j print_loop

done_print:
    li a0, 11              # syscall: print_char
    li a1, 10              # newline
    ecall
    ret
