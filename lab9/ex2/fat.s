.text
.globl fat

fat:
    pushq %rbp                # Salva o valor de %rbp
    movq %rsp, %rbp           # Configura o quadro da pilha
    pushq %rbx                # Salva o registrador %rbx (usado para armazenar n)

    movl %edi, %ebx           # Salva n em %ebx
    cmpl $0, %edi             # Compara n com 0
    jne .recurse              # Se n != 0, salta para a recursão

    movl $1, %eax             # Caso base: retorna 1
    popq %rbx                 # Restaura %rbx
    popq %rbp                 # Restaura %rbp
    ret                       # Retorna

.recurse:
    subl $1, %edi             # Calcula n - 1 em %edi
    call fat                  # Chama recursivamente fat(n - 1)

    imull %ebx, %eax          # Multiplica n * fat(n - 1) (n está em %ebx)
    popq %rbx                 # Restaura %rbx
    popq %rbp                 # Restaura %rbp
    ret                       # Retorna
