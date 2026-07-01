.text

.global backtrace
backtrace:
    push %ebp
    mov %esp, %ebp
    
    mov 8(%ebp), %ecx # move n into ecx, ecx will be our counter
    mov %ebp, %edx # set edx to ebp, edx will store the pointer to the current base pointer
    
.loop:
    cmp %edx, (%edx) # if (cur base ptr < prev base ptr) then break
    jb .error
    
    cmp %edx, 4(%edx) # if (cur ret addr > prev base ptr) then break
    ja .error
    
    test %ecx, %ecx # while i != 0
    jz .success
    
    mov (%edx), %edx # progress to the next stack frame
    dec %ecx
    
    jmp .loop

.error:
    xor %eax, %eax # return 0 (nullptr)
    jmp .return

.success:
    mov 4(%edx), %eax # return the return address of the current stack frame
    
.return:
    pop %ebp
    ret
