.data
Sf: .string "%d\n"

.text
.globl main

main:
    pushq %rbp
    movq %rsp, %rbp

    subq $16, %rsp /* aloca mais 16 de memoria de forma equilibrada*/
    
    movl $0, %eax /* max = 0*/
    movl $0, %r13d /* i = 0 */
    leaq dados(%rip), %rdi
    movq %rdi, -16(%rbp) /* %rdi == *p */
    movl %r13d, -8(%rbp) /*i*/
    movl %eax, -4(%rbp) /*max*/
    
    
    
L1:
    cmpl $3, %r13d
        jge L2
    
    movl %rdi, %bx
    
    cmpb $0, %bl
        je incrementa
    
    cmpb %eax, %bh
        jle incrementa

    movb %bh, %eax
    jmp incrementa

incrementa:
    addl $1, %r13d
    jmp L1

L2:
    movl $Sf, %edi
    movl %eax, %esi
    movl $0, %eax
    call printf

    movq %rbp, %rsp
    popq %rbp

    leave
    ret
    

