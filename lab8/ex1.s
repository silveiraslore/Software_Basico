.data
s1: .string "ls -ls"

.text
.globl main

main:
    /*prologo*/
    pushq %rbp
    movq %rsp, %rbp

    /*Coloque seu codigo aqui*/
    lea s1(%rip), %rdi
    call system



    /*finalização*/
    leave
    ret