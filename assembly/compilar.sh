#!/bin/bash
nasm -f elf64 exercicio_1.asm
ld exercicio_1.o -s -o exercicio_1
while true; do
    read -p "Executar arquivo (Y/N)? " yn
    case $yn in
        [Yy]* ) echo "Executando resultado...";
                ./exercicio_1;
                break;;

        [Nn]* ) echo "Tchau.";
                exit;;

            * ) echo "Sim ou não?";;
    esac
done
