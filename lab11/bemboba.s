.text
.globl bemboba

/*%rdi, %rsi, %rdx*/


bemboba:
    pushq %rbp
    movq %rsp, %rbp
    subq $32, %rsp

    movq %r10, -8(%rbp) /*local[4]*/
    movq %r11, -16(%rbp) /* *a */
    movl %ebx, -20(%rbp) /* int i */

    movq %r10, %r11
    movl $0, %ebx


loop:
    cmpl $4, %ebx
        jg end_loop
    movq %rdi, (%r11)

    incl %ebx
    addq $4, %r11
    jmp loop

end_loop:
    movq %r10, %rdi
    movl $4, %esi
    call addl

    leave
    ret

    
