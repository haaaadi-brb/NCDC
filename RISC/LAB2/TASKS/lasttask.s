.data
menu:       .asciiz "\nSelect operation:\n1. Toggle Bit\n2. Check Bit\n3. Set Bit\n4. Clear Bit\n5. Exit\nChoice: "
prompt_int: .asciiz "Enter the integer: "
prompt_pos: .asciiz "Enter the bit position (0-based): "
result_msg: .asciiz "Result: "
check_set:  .asciiz "Bit is set.\n"
check_clear:.asciiz "Bit is clear.\n"
invalid_pos_msg: .asciiz "Invalid bit position! Must be between 0 and 31.\n"

.text
.globl main

main:
menu_loop:
    # Print menu string
    li a0, 4          # syscall 4: print string
    la a1, menu       # address of string in a1
    ecall

    # Read choice integer
    li a0, 5          # syscall 5: read int
    ecall
    mv t0, a0         # t0 = choice

    # Exit if choice == 5
    li t1, 5
    beq t0, t1, exit

    # Prompt for integer
    li a0, 4
    la a1, prompt_int
    ecall

    # Read integer
    li a0, 5
    ecall
    mv t1, a0         # t1 = input integer

    # Prompt for bit position
    li a0, 4
    la a1, prompt_pos
    ecall

    # Read bit position
    li a0, 5
    ecall
    mv t2, a0         # t2 = bit position

    # Validate bit position: must be less than 32
    li t4, 32
    bge t2, t4, invalid_pos

    # mask = 1 << bit position
    li t3, 1
    sll t3, t3, t2    # create mask in t3

    # Branch based on choice
    li t4, 1
    beq t0, t4, do_toggle
    li t4, 2
    beq t0, t4, do_check
    li t4, 3
    beq t0, t4, do_set
    li t4, 4
    beq t0, t4, do_clear

    # If invalid choice, loop again
    j menu_loop

invalid_pos:
    # Print invalid position message
    li a0, 4
    la a1, invalid_pos_msg
    ecall
    j menu_loop

do_toggle:
    xor t5, t1, t3    # toggled result in t5

    # Print result message
    li a0, 4
    la a1, result_msg
    ecall

    # Print integer result
    li a0, 1
    mv a1, t5
    ecall

    j menu_loop

do_check:
    and t5, t1, t3
    bnez t5, bit_set

    # Bit is clear
    li a0, 4
    la a1, check_clear
    ecall
    j menu_loop

bit_set:
    li a0, 4
    la a1, check_set
    ecall
    j menu_loop

do_set:
    or t5, t1, t3

    # Print result message
    li a0, 4
    la a1, result_msg
    ecall

    # Print integer result
    li a0, 1
    mv a1, t5
    ecall
    j menu_loop

do_clear:
    xori t6, t3, -1       # bitwise NOT of mask
    and t5, t1, t6        # clear the selected bit in t1

    # Print result message
    li a0, 4
    la a1, result_msg
    ecall

    # Print integer result
    li a0, 1
    mv a1, t5
    ecall

    j menu_loop

exit:
    li a0, 10         # syscall 10 = exit
    ecall
