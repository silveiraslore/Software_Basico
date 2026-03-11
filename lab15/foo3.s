.text
.globl foo3

foo3:
    pushq %rbp                  # Salva o quadro de pilha
    movq %rsp, %rbp             # Configura o quadro de pilha
    subq $32, %rsp              # Reserva espaço para variáveis locais:
                                # - r (8 bytes)
                                # - i (4 bytes)

    movq $0, -8(%rbp)           # Inicializa r = 0.0 (em memória local)
    movl $0, -12(%rbp)          # Inicializa i = 0 (em memória local)

.L_for_loop:                    # Início do loop
    cmpl %esi, -12(%rbp)        # Verifica se i < n
    jge .L_exit_loop            # Sai do loop se i >= n

    movq (%rdi), %xmm0          # Carrega o valor apontado por *a (em %rdi)
    call sin                    # Chama sin(*a), resultado em %xmm0

    movsd -8(%rbp), %xmm1       # Carrega r (double) da pilha para %xmm1
    addsd %xmm0, %xmm1          # Soma r + sin(*a)
    movsd %xmm1, -8(%rbp)       # Atualiza r na pilha

    addq $8, %rdi               # Incrementa o ponteiro a (a++)
    incl -12(%rbp)              # Incrementa i (i++)

    jmp .L_for_loop             # Volta ao início do loop

.L_exit_loop:
    movsd -8(%rbp), %xmm0       # Move r (resultado final) para %xmm0
    leave                       # Restaura o quadro de pilha
    ret                         # Retorna o valor em %xmm0
