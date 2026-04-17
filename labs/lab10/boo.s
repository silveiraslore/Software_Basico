.text
.globl boo


boo:
    pushq %rbp
    movq %rsp, %rbp

    movq %rdi, %rbx
    movl %esi, %r12d
    movl %edx, %r13d

loop:
    cmpl $0, %r12d
        je end_loop
    
    movl (%rbx), %edi
    movl %r13d, %esi
    call f
    movl %eax, 4(%rbx)

    addq $8, %rbx
    subl $1, %r12d
    jmp loop

end_loop:
    leave
    ret