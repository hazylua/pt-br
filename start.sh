#!/bin/bash
echo "Testando..."

_isRunning() {
    pgrep -x "$1" > /dev/null
}

if [ ! -f ./arquivo_1.txt ]; then
    touch arquivo_1.txt
    ls
fi

while _isRunning gedit; do
    ls
    sleep 1
done

rm -r arquivo_1.txt
ls