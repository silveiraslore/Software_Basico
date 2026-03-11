/*
float foo (double a, float b) {
  return (a+b)*(a-b);
}

xmm0, xmm1, xmm2 ..7

xmm0 retorna
*/

.text
.globl foo

foo:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp

    cvtss2sd %xmm1, %xmm15 /* xmm15 = (double) b */
    
    movsd %xmm0, %xmm14 /* xmm14 = a */

    addsd %xmm15, %xmm14 /*xmm14 = (xmm15+xmm14)*/

    subsd %xmm15, %xmm0

    mulsd %xmm14, %xmm0

    cvtsd2ss %xmm0, %xmm0

    leave 
    ret
