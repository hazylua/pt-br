section .data
    num1:       dw 4
    num2:       dw 2
    newline:    db 10,0
    lnewline:   equ $ - newline

section .bss
    result: resb 10

section .text
    global _start

        _start:
            mov edx, 0
            mov eax, [num1]
            mov ecx, [num2]
            div ecx
            add ecx, '0'
            mov [result], ecx

            mov ecx, result
            mov edx, 1
            mov eax, 4
            mov ebx, 1
            int 80h
            
            mov ecx, newline
            mov edx, lnewline
            mov edx, 1
            mov eax, 4
            mov ebx, 1
            int 80h

            mov eax, 1
            mov ebx, 0
            int 80h