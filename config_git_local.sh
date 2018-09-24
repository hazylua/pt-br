#!/bin/bash
read -p 'Github user name: ' username
read -p 'Github user email: ' usermail
echo
git config user.name $uservar
git config user.email $usermail
echo "Exibição das configurações do repositório: "
cat .git/config 