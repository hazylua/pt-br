# Instruções de compilação
Para a compilação desses arquivos usando NASM em sistemas Linux, usar os seguintes comandos.

<b>Em arquitetura 64 bits:</b>

$ nasm -f elf64 hello.asm

$ ld hello.o -s -o hello

<b>Em arquitetura 32 bits:</b>

$ nasm -f elf32 hello.asm

$ ld hello.o -s -o hello
