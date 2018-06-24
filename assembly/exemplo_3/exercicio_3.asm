section .data
    titulo_msg db '*** Exercício 3 ***', 0xA
    titulo_tam equ $ - titulo_msg

    newline_msg db 10, 0
    newline_tam equ $ - newline_msg

    msg1 db "Digite um número de zero a dez: "
    msg1_tam equ $ - msg1

section .bss
    num resb 2
    opcao resb 4

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
        mov ebx, 1
        mov ecx, num
        int 80h

        mov eax, 1
        mov ebx, 0
        int 80h