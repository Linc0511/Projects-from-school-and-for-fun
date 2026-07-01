.global bits

bits:
    movl n, %eax      # move n into eax
    movl $0, %ecx     # clear the counting regester %ecx 

count_bits_loop:
    cmpl $0, %eax      # Check if n is zero
    jz done            # If zero, exit the loop

    movl %eax, %edx # store what the oraginal value was in %edx
    push %edx
    andl $1, %eax # check the last bit of %eax
    addl %eax, %ecx # store the result 
    movl %edx, %eax
    shrl $1, %eax      # Shift right by 1 bit in %edx
    pop %edx
    subl $1, %edx

    
    
    jmp count_bits_loop  # Repeat the loop

done:
    movl %ecx, %eax      # Move the count from ecx to eax
    ret                  # Return with the result in eax
