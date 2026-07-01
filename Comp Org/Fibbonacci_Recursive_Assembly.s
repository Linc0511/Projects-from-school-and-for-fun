.text
.globl fib

fib:
    push    %ebp
    mov     %esp, %ebp

    mov     8(%ebp), %eax

    cmpl    $2, %eax
    jl      done
    movl    %eax, %edx
recursion: 
    dec     %edx              # n-1
    push    %edx
    push    %edx
    call    fib
    addl    $4, %esp
    pop     %edx
    movl    %eax, %ecx        # Store the result of fib(n-1) in ecx

    
    dec     %edx         # n-2
    push    %ecx
    push    %edx
    call    fib
    add     $4, %esp
    pop     %ecx

    add     %ecx, %eax        # Add the results of fib(n-1) and fib(n-2)
    pop     %ebp
    ret


done:
    pop     %ebp
    ret

