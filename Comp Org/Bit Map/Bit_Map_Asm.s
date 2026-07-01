.text
.globl enlarge
enlarge:       
    push    %ebp          # save old base pointer
    mov     %esp, %ebp      # setup the new base pointer
    sub     $4, %esp 
    push    %esi
    push    %edi
    push    %ebx

    mov     8(%ebp), %esi
    mov     20(%ebp), %edi

    mov     12(%ebp), %eax
    shl     $1, %eax
    add     $7, %eax
    shr     $3, %eax

    mov     %eax, -4(%ebp)
    xor     %edx, %edx

height_loop:
    cmp     16(%ebp), %edx
    jge     end_height_loop
    push    %edx

    xor     %ebx, %ebx

width_loop:
    cmp     12(%ebp), %ebx
    jge     end_width_loop

    test    $0b111, %ebx
    jnz     end_fetch_if

    movb    (%esi), %dl
    inc     %esi
end_fetch_if:

    test    $0b11, %ebx
    jnz     end_advance_if

    mov     -4(%ebp), %ecx
    movb    $0, (%edi)
    movb    $0, (%edi, %ecx, 1)
    inc     %edi
end_advance_if:

    test    $0x80, %dl
    jz      end_set_if


    mov     %ebx, %ecx
    and     $0b11, %ecx
    shl     $1, %ecx

    mov     $0xC0, %al
    shr     %cl, %al

    mov     -4(%ebp), %ecx
    orb     %al, -1(%edi)
    orb     %al, -1(%edi, %ecx, 1)
end_set_if:

    shl     $1, %dl
    inc     %ebx
    jmp     width_loop

end_width_loop:

    add     -4(%ebp), %edi
    pop     %edx
    inc     %edx
    jmp     height_loop
end_height_loop:
pop %ebx
pop %edi
pop %esi
# "pop" our local variables off stack
mov     %ebp, %esp      # restore stack pointer
pop     %ebp           # restore original base pointer
ret
