.data
nums:  .byte  10, -21, -30, 45         # Array de bytes
Sf:    .string "%d\n"                  # String de formato para printf

.text
.globl main
main:
    pushq   %rbp                       # Salva o ponteiro da pilha anterior
    movq    %rsp, %rbp                 # Define o novo ponteiro da pilha
    subq    $16, %rsp                  # Reserva espaço na pilha
    movq    %rbx, -8(%rbp)             # Salva o registrador rbx na pilha
    movq    %r12, -16(%rbp)            # Salva o registrador r12 na pilha

    movl    $0, %ebx                   # i = 0
    lea     nums, %r12                  # p = &nums (carrega o endereço de nums)
    movl    $0, %esi                   # sum = 0

L1:
    cmpl    $4, %ebx                   # if (i == 4)
    je      L2                          # vai para L2 se i == 4

    movzbl  (%r12, %rbx), %eax          # eax = *p (extensão zero do byte)
    addl    %eax, %esi                  # sum += eax

    addl    $1, %ebx                    # i++
    jmp     L1                          # volta para o início do loop

L2:
    movl    %esi, %edi                  # move o valor da soma para o primeiro parâmetro de printf
    movq    $Sf, %rsi                   # ponteiro para o formato da string
    call    printf                      # chama a função printf para imprimir a soma

    movq    $0, %rax                    # rax = 0 (valor de retorno)
    movq    -8(%rbp), %rbx              # restaura o registrador rbx
    movq    -16(%rbp), %r12             # restaura o registrador r12
    leave                               # restaura o ponteiro da pilha
    ret                                  # retorna
