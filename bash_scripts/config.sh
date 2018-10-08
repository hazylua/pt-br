#!/bin/bash
read -p "Usuário do Github: " username
read -p "Email do Github: " usermail
git config user.name $username
git config user.email $usermail
echo -n -e "\nConfigurações do repositório:\n"
git config user.name
git config user.email
echo -n -e "\nConfigurações globais:\n"
git config --global user.name
git config --global user.email