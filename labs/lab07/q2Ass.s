/*
char S2[] = {65, 108, 111, 32, 123, 103, 97, 108, 101, 114, 97, 125, 33, 0};
int main (void) {
  char *pc = S2;
  while (*pc)
    printf ("%c", *pc++);
  printf("\n");
  return 0;
}
*/

.data
S2:    .byte 65, 108, 111, 32, 123, 103, 97, 108, 101, 114, 97, 125, 33, 0
Sf:  .string "%c"    /* primeira string de formato para printf */
Sf2: .string "\n"    /* segunda string de formato para printf */

.text
.globl  main
main:

/********************************************************/
/* mantenha este trecho aqui e nao mexa - prologo !!!   */
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)  /* guarda rbx */
  movq    %r12, -16(%rbp)  /* guarda r12 */
/********************************************************/

  movq  $S2, %r12  /* r12 = &S2 */

L1:
  movsbl  (%r12), %eax    /* eax = *r12 (extensão de byte para 32 bits) */
  cmpb  $0, %al           /* if (*pc == 0) ? */
  je  L2                  /* goto L2 (fim) se for null */

  cmpb  $123, %al         /* se o caractere for '{' */
  je   SkipPrint          /* pular impressão */
  
  cmpb  $125, %al         /* se o caractere for '}' */
  je   SkipPrint          /* pular impressão */ 
  
  movsbl  (%r12), %eax    /* eax = *r12 (estendendo o byte para 32 bits */

  movq    $Sf, %rdi    /* primeiro parametro (ponteiro)*/
  movl    %eax, %esi   /* segundo parametro  (inteiro) */
  movl  $0, %eax
  call  printf       /* chama a funcao da biblioteca */
  addq  $1, %r12  /* r12 += 1; */
  jmp  L1         /* goto L1; */


SkipPrint:
  addq $1, %r12
  jmp L1

L2:  
/*************************************************************/
/* este trecho imprime o \n (estraga %eax)                  */
  movq    $Sf2, %rdi    /* primeiro parametro (ponteiro)*/
  movl  $0, %eax
  call  printf       /* chama a funcao da biblioteca */
/*************************************************************/

/***************************************************************/
/* mantenha este trecho aqui e nao mexa - finalizacao!!!!      */
  movq  $0, %rax  /* rax = 0  (valor de retorno) */
  movq    -16(%rbp), %r12 /* recupera r12 */
  movq    -8(%rbp), %rbx  /* recupera rbx */
  leave
  ret      
/***************************************************************/
