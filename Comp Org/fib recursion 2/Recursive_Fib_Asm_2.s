.section .data
format_string1:
    .string "fibonacci(%d) = %d\n"

format_string2:
    .string "fibonacci(%d) = %d + %d\n"

.text
.globl fib

fib:
    push    %ebp
    mov     %esp, %ebp
    push    %ebx
    # test n < 2
    mov     8(%ebp), %eax
    mov     12(%ebp), %ebx
    cmp    $2, %eax
    jl      trace
    push    %ebx
    dec     %eax
    push    %eax
    call    fib
    pop     %eax
    pop     %ebx
    push    %ecx

    # fib (n-2)
    push    %ebx
    dec     %eax
    push    %eax
    call    fib
    pop     %eax
    pop     %ebx
    pop     %edx


    cmp    $0, %ebx
    je      skip
    # Load the format string address into ebx
    push    %ecx           # Push n2
    push    %edx           # Push n1
    add     $2, %eax
    push    %eax           # Push n
    push    $format_string2          # Push the format string
    call    printf
    add     $8, %esp
    pop     %edx
    pop     %ecx

skip:
    add     %edx, %ecx
    jmp     done

trace:
    cmp    $0, %ebx
    je      done 
    push   %eax
    push   %eax           # Push the result to print
    push   $format_string1           # Push the format string
    call    printf
    add    $8, %esp
    pop     %eax
    #xor     %ecx, %ecx
    mov     %eax, %ecx



done:
    cmp    $0, %ebx
    jne      dont_move 
    add     %edx, %eax
    mov     %eax, %ecx
dont_move:
    pop     %ebx
    mov     %ebp, %esp
    pop     %ebp
    ret
