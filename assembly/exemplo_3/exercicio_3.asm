section .data
    titulo_msg db '*** Exercício 3 ***', 0xA
    titulo_tam equ $ - titulo_msg

    newline_msg db 10, 0
    newline_tam equ $ - newline_msg

    msg1 db "Digite um número de 0 a 10: "
    msg1_tam equ $ - msg1

    msg2 db "Digite incr para incrementar, decr para decrementar, e sair para terminar o programa: "
    msg2_tam equ $ - msg2

    msg3 db "Opção inválida.", 0xA
    msg3_tam equ $ - msg3

    msg4 db "Número: "
    msg4_tam equ $ - msg4

section .bss
    num resb 10
    opcao resb 10

section .text
    global _start

    _start:
        mov eax, 4
        mov ebx, 1
        mov ecx, titulo_msg
        mov edx, titulo_tam
        int 80h

        mov eax, 4
        mov ebx, 1
        mov ecx, msg1
        mov edx, msg1_tam
        int 80h

        mov eax, 3
        mov ebx, 2
        mov ecx, num
        int 80h

        call _begin

    _begin:
        mov eax, 4
        mov ebx, 1
        mov ecx, msg4
        mov edx, msg4_tam
        int 80h

        mov ecx, num
        mov eax, 4
        mov ebx, 1
        int 80h

        mov eax, 4
        mov ebx, 1
        mov ecx, msg2
        mov edx, msg2_tam
        int 80h

        mov eax, 3
        mov ebx, 2
        mov ecx, opcao
        int 80h

        mov eax, [opcao]

        cmp eax, 'incr'
        je _increase

        cmp eax, 'decr'
        je _decrease

        cmp eax, 'sair'
        je _exit

        jmp _invalido

    _increase:
        mov eax, [num]
        inc eax
        mov [num], eax

        jmp _begin

    _decrease:
        mov eax, [num]
        dec eax
        mov [num], eax

        jmp _begin


    _exit:    
        mov eax, 1
        mov ebx, 0
        int 80h

    _invalido:
        mov eax, 4
        mov ebx, 1
        mov ecx, msg3
        mov edx, msg3_tam
        int 80h

        jmp _begin