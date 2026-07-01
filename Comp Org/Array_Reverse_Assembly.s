.text
.globl reverse

reverse:
push %ebp  # Save the base pointer
mov %esp, %ebp # Set up a new base pointer
push %esi 
mov 8(%ebp), %ecx # Move the string address to ECX
mov %ecx, %edx

xor %esi, %esi
xor %eax, %eax

end_of_array_loop:
cmpb $0, (%edx)
jz reverse_loop
inc %edx
inc %eax
jmp end_of_array_loop

reverse_loop:
dec %eax
cmp %eax, %esi
jg reverse_done
mov (%ecx,%eax,1), %dh # Load a character into AL
mov (%ecx,%esi,1), %dl
mov %dh, (%ecx,%esi,1)
mov %dl, (%ecx,%eax,1)
inc %esi
jmp reverse_loop # Repeat the loop

reverse_done:
pop %esi
pop %ebp  # Restore the base pointer
ret
