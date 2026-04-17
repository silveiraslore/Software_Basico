.text
.globl map2


map2:
    pushq %rbp
    movq %rsp, %rbp

    movq %rdi, %r10
    movq %rsi, %r11
    movl %edx, %r12d

    movl $0, %ebx

loop:
    cmpl %r12d, %ebx
        je end_loop
    movq (%r10, %rbx,4), %rdi
    call f

    movl %eax, (%r11, %rbx, 4)

    incl %ebx
    jmp loop

end_loop:
    leave 
    ret
    