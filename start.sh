#!/bin/bash
echo "+---+ START.SH +---+"

_isRunning() {
    pgrep -x "$1" > /dev/null
}

if [ ! -f ../arquivo_1.txt ]; then
    touch ../arquivo_1.txt
    ls ../
fi

while _isRunning gedit; do
    echo "sleeping"
    sleep 5
done

rm -r ../arquivo_1.txt
ls ../