.text
.globl add

add:
    pushq %rbp
    movq %rsp, %rbp

    movl $0, %eax
    movq %rdi, %rdx
loop:
    cmpq $0, %rdx
        je null_case
    
    movl (%rdx),%r12d
    addl %r12d, %eax

    movq 8(%rdx), %rdx

    jmp loop

null_case:
    leave
    ret