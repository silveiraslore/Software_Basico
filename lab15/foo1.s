.text
.globl foo1

/*xmm0, xmm1*/

foo1:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp

    movss %xmm15, -16(%rbp)

    movsd %xmm1, %xmm15 /* b */
    cvtss2sd %xmm0, %xmm0
    call sin

    addsd %xmm15, %xmm0
    cvtsd2ss %xmm0, %xmm0
    leave 
    ret
