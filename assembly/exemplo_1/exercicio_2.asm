section .data
    titulo_msg db '*** Exercício 2 ***', 0xA
    titulo_tam equ $ - titulo_msg

    newline_msg db 10, 0xA
    newline_tam equ $ - newline_msg

    nome_msg db "Nome: ", 0
    nome_tam equ $ - nome_msg

    sobrenome_msg db "Sobrenome: ", 0
    sobrenome_tam equ $ - sobrenome_msg

    nascimento_msg db "Data de nascimento: ", 0
    nascimento_tam equ $ - nascimento_msg

    espaco_msg db ' ', 0
    espaco_tam equ $ - espaco_msg

section .bss
    nome resb 20
    sobrenome resb 20
    nascimento resb 20
    
section .text
    global _start

        _start:
            ; Mostrar título.
            mov eax, 4
            mov ebx, 1
            mov ecx, titulo_msg
            mov edx, titulo_tam
            int 80h

            ; Mostrar mensagem ---> Ler nome
            mov eax, 4
            mov ebx, 1
            mov ecx, nome_msg
            mov edx, nome_tam
            int 80h

           ;; mov edx, 5 ; Nome pode ter apenas este tamanho.
            mov eax, 3
            mov ebx, 1
            mov ecx, nome
            int 80h
            
            ; Mostrar mensagem ---> Ler sobrenome.
            mov eax, 4
            mov ebx, 1
            mov ecx, sobrenome_msg
            mov edx, sobrenome_tam
            int 80h

            mov edx, 20
            mov eax, 3
            mov ebx, 1
            mov ecx, sobrenome
            int 80h

            ; Mostrar mensagem ---> Ler data de nascimento.
            mov eax, 4
            mov ebx, 1
            mov ecx, nascimento_msg
            mov edx, nascimento_tam
            int 80h

            mov edx, 11
            mov ecx, nascimento
            mov eax, 3
            mov ebx, 1
            int 80h

            ; Mostar nome completo.
            ; Mostrar nome.
            mov eax, 4
            mov ebx, 1
            mov ecx, nome
            mov edx, 4
            int 80h
            ; Espaço em branco.
            mov eax, 4
            mov ebx, 1
            mov ecx, espaco_msg
            mov edx, 1
            int 80h
            ; Mostrar sobrenome.
            mov eax, 4
            mov ebx, 1
            mov ecx, sobrenome
            mov edx, 17
            int 80h

            call _newline

            ; Mostar data de nascimento.
            mov eax, 4
            mov ebx, 1
            mov ecx, nascimento
            mov edx, 10
            int 80h

            call _newline

            ; Terminar programa.
            mov eax, 1
            mov ebx, 0
            int 80h

        _newline:
            mov eax, 4
            mov ebx, 1
            mov ecx, newline_msg
            mov edx, newline_tam
            int 80h
            ret