.data
msg:      .asciiz "GCD is: "
newline:  .asciiz "\n"

a_val:    .word 24      # First number
b_val:    .word 18     # Second number

.text
.globl _start

_start:
# Load a into t1
la t0, a_val
lw t1, 0(t0)

# Load b into t2
la t0, b_val
lw t2, 0(t0)

gcd_loop:
beqz t2, done        # if b == 0, done
rem t3, t1, t2       # t3 = a % b
mv t1, t2            # a = b
mv t2, t3            # b = a % b
j gcd_loop

done:
# t1 now holds the GCD
la a0, msg
jal print_str

mv a0, t1
jal print_digit

la a0, newline
jal print_str

j stop
stop:
j stop

# ===== Utility: Print null-terminated string at address a0 =====
print_str:
mv t4, a0         # t4 = pointer to string
str_loop:
lb t5, 0(t4)      # Load byte
beqz t5, str_ret  # If byte is 0 (null), end
li a0, 11         # syscall: print char
mv a1, t5
ecall
addi t4, t4, 1    # move to next char
j str_loop

str_ret:
jr ra

# ===== Utility: Print single digit in a0 =====
print_digit:
li t6, '0'
add t5, a0, t6    # Convert number to ASCII
li a0, 11
mv a1, t5
ecall
jr ra
