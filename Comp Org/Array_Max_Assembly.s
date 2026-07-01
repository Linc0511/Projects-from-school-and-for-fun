.section .text
.global max
max:
# Prolougue
push %ebp          # save old base pointer
mov %esp,%ebp      # setup the new base pointer

# Body
mov 8(%ebp), %ecx # array pointer
mov 12(%ebp), %edx # value for n
mov (%ecx), %eax
Find_Max_Loop:
jz done
cmp %eax, (%ecx, 1)
cmovg (%ecx, 1), %eax
add $4, %ecx        # Move to the next element in the array
dec %edx 
jmp Find_Max_Loop  

done:
# Epilogue

pop %ebp           # restore original base pointer
ret
