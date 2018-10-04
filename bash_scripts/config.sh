#!/bin/bash
echo "+---+ CONFIG.SH +---+"
read -p '-> Github user name: ' username
read -p '-> Github user email: ' usermail
echo
git config user.name $username
git config user.email $usermail
echo "-> Exibição das configurações do repositório: "
git config user.name
git config user.email
echo "-> Exibição das configurações globais: "
git config --global user.name
git config --global user.email