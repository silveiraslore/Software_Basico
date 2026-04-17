.text
.globl add2

add2:
    pushq %rbp
    movq %rsp, %rbp

    movl $0, %eax
    
rec:
    cmpq $0, %rdi
        je ret_nulo
    
    movl (%rdi), %r12d
    addl %r12d, %eax

    movq 8(%rdi), %rdi
    call rec

ret_nulo:
    leave
    ret


    