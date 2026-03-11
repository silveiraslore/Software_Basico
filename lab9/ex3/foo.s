.text
.globl foo

foo:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp

    movl %r12d, -4(%rbp)
    movl %r13d, -8(%rbp)
    movq %rbx, -16(%rbp)
    
    movl $0, %r12d /*s =0*/
    movl $0, %ebx /* i=0*/

.loop:
    cmpl %esi, %ebx
        jge .end_loop
    
    movl (%rdi, %rbx, 4), %r13d /*r13 = a[i]*/
    addl %r13d, %r12d /*s+= a[i]*/
    
    cmpl $0, %r13d
        je .preenche
    
    incl %ebx
    jmp .loop

.preenche:
    movl %r12d, (%rdi, %rbx, 4)
    movl $0, %r12d
    incl %ebx
    jmp .loop

.end_loop:
    leave
    ret