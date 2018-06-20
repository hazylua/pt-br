section .data
    titulo_msg db '*** Exercício 1 ***', 0xA
    titulo_tam equ $ - titulo_msg

    newline_msg db 10, 0
    newline_tam equ $ - newline_msg
    
    resposta_msg db '> Resultado: ', 0
    resposta_tam equ $ - resposta_msg


    num1 db '8', 0xA
    num2 db '4', 0xA

section .bss
    result resb 10

section .text
    global _start
        
        _start:
            mov ecx, titulo_msg
            mov edx, titulo_tam
            call mst_saida

            mov al, [num1]
            mov bl, [num2]
            
            mov ah, 0
            mov dx, 0
            sub al, '0'
            sub bl, '0'                            
            
            div bl
            add ax, '0'
            
            mov [result], ax            
            call mst_saida

            mov ecx, resposta_msg
            mov edx, resposta_tam
            call mst_saida            

            mov ecx, result
            mov edx, 1
            call mst_saida

            jmp exit

        exit:
            mov ecx, newline_msg
            mov edx, newline_tam
            call mst_saida
            mov eax, 1
            mov ebx, 0
            int 80h

        mst_saida:
            mov eax, 4
            mov ebx, 1
            int 80h
            ret