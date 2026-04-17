.text
.globl foo2

/*xmm0, xmm1*/

foo2:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp

    movss %xmm14, -8(%rbp)

    movsd %xmm0, %xmm14 /* a */

    cvtss2sd %xmm0, %xmm0
    cvtss2sd %xmm1, %xmm1

    call sin
    movsd %xmm0, %xmm14
    movsd %xmm1, %xmm0
    call cos


    addsd %xmm14, %xmm0
    leave 
    ret
