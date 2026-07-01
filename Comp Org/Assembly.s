    .text

    .global f
f:  
    # Load the values of x, y, and z from global variables
    movl x, %ecx
    movl y, %edx

    # Subtract 1 from x
    subl $1, %ecx

    # Add 3 to y
    addl $3, %edx

    # Multiply (x - 1) with (y + 3)
    imull %edx, %ecx

    # Add z to the result
    addl %ecx, %eax
    ret
movl x, %ecx
    movl y, %edx
    movl z, %eax
.global g
g:
    # Load the values of x, y, and z from global variables
    movl x, %ecx
    

    # Extract the bits 0 to 2 of x
    andl $0b111, %ecx

    # Move the value for y in 
    movl y, %edx

    # Extract the bits 0 to 3 of y
    andl $0b1111, %edx

    # Add the values for x and y
    addl %ecx, %edx

    # Move in z
    movl z, %eax

    #Add z to the rest of the equation
    addl %edx, %eax

    # move in x again for second part
    movl x, %ecx

    # Extract the bits 9 to 31 of x
    shrl $9, %ecx

    # move in y
    movl y, %edx

    # Find if y is odd
    andl $0b1, %edx

    # If y is odd multiply it by 3 to get 3 or else keep the value 0
    imull $3, %edx

    # add the value of y
    addl %edx, %ecx

    # Calculate (x0..2 + y0..3 + z)(x9..31)
    imull %ecx, %eax

.global h
h:
    mov $4004,%eax
    mov $69,%ax
    ret
