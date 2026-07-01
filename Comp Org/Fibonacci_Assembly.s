.section .text
.globl fib
fib:

    cmpl $2, %eax          # Compare n with 2
    jl .less_than_2       # If n < 2, return n

    # Initialize variables
    movl $1, %ecx          # fn1 = 1
    movl $1, %edx          # fn = 1

.loop:
    cmpl $2, %eax          # Compare n with 2
    jl .done               # If n < 2, exit the loop

    # Calculate the next Fibonacci number
    addl %edx, %ecx        # temp = fn1 + fn
    xchgl %ecx, %edx       # Swap fn and temp (fn <- temp, temp <- fn)
    subl $1, %eax          # Decrement n
    jmp .loop

.done:
    movl %edx, %eax
    ret                    # Return

.less_than_2:
    ret                    # Return

