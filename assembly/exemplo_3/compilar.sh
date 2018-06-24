#!/bin/bash
if nasm -f elf64 exercicio_2.asm; 
    then
        ld exercicio_2.o -s -o exercicio_2
        printf "Compilação com sucesso.\n"
    else
        printf "Compilação falhou.\n"
fi
