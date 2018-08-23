# pt-br - README.md
Repositório dedicado ao armazenamento de códigos não específicos.

##### Links:
Formatação básica: [basic writing and formatting syntax.](https://help.github.com/articles/basic-writing-and-formatting-syntax/)

Git pelo terminal:
```
git clone "https://github.com/yb00/pt-br.git"
[...]
git add -A
git commit -m "Minha mensagem."
git push -u https://github.com/yb00/pt-br.git
```

Instruções de compilação de códigos em assembly pelo NASM (64 bits):
```
nasm -f elf64 exemplo.asm
ld exemplo.o -s -o executavel
```