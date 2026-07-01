.text
.global find

find:
    push %ebp             # Save the old base pointer
    mov %esp, %ebp        # Set up the new base pointer
    push %esi

    push %ebx
    movzwl 8(%ebp), %ebx      # Load needle into ebx
    mov 12(%ebp), %esi    # Load haystack pointer into edx
    mov 16(%ebp), %ecx    # Load size into ecx
    xor %eax, %eax        # set eax to 0

search_loop:
    cmp $0, %ecx          # Check if the size is 0
    jz not_found          # If so, element not found

    movzwl (%esi, %eax, 2), %edx       # Load the current element from the haystack
    cmp %ebx, %edx          # Compare with the needle
    je end_find              # If equal, found the element
    dec %ecx              # Decrement the size
    inc %eax
    jmp search_loop       # Repeat the loop

not_found:
    mov $-1, %eax         # Element not found, set return value to -1
    jmp end_find


end_find:
    pop %ebx
    pop %esi            # Restore register after using it
    mov %ebp, %esp        # Set up the new base pointer
    pop %ebp            # Restore the original base pointer
    ret
