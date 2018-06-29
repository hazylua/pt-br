section .data
    msg db 'Olá!', 0xA
    msg_tam equ $ - msg

section .text
    global _start
    
    _start:
        call _exibir
        mov ecx, msg
        mov edx, msg_tam
        int 0x80

        mov eax, 1
        mov ebx, 0
        int 0x80

    _exibir:
        mov eax, 4
        mov ebx, 1
        ret
        