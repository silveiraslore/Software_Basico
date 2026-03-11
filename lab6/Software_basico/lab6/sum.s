.data
nums:  .int  10, -21, -30, 45
Sf:    .string "%d\n"    # string de formato para printf

.text
.globl main
main:

/********************************************************/
/* mantenha este trecho aqui e nao mexa - prologo !!!   */
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $16, %rsp
    movq    %rbx, -8(%rbp)
    movq    %r12, -16(%rbp)
/********************************************************/

    movl    $0, %ebx          /* i = 0 */
    movq    $nums, %r12       /* p = &nums */
    movl    $0, %eax          /* sum = 0 (em %eax) */

L1:
    cmpl    $4, %ebx          /* if (i == 4) ? */
    je      L2                /* goto L2 */

    movl    (%r12), %ecx      /* ecx = *p (elemento atual) */
    addl    %ecx, %eax        /* sum += *p (soma) */

    addl    $1, %ebx          /* i++ */
    addq    $4, %r12          /* p++ (próximo elemento) */
    jmp     L1                /* goto L1 */

L2:
/***************************************************************/
/* mantenha este trecho aqui e nao mexa - finalizacao!!!!      */
    movq    %rax, %rdi        /* primeiro parametro (ponteiro) para printf */
    movl    %eax, %esi        /* segundo parametro (soma) */
    call    printf            /* chama a função da biblioteca */

    movq    $0, %rax          /* rax = 0 (valor de retorno) */
    movq    -8(%rbp), %rbx
    movq    -16(%rbp), %r12
    leave
    ret      
/***************************************************************/
