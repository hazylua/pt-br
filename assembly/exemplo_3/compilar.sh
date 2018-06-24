#!/bin/bash
nasm -f elf64 exercicio_3.asm
ld exercicio_3.o -s -o exercicio_3
./exercicio_3
