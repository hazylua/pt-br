#include "pessoa.h"

Pessoa::Pessoa (const string &nome)
{
    this->nome = nome;
}

void Pessoa::setContatos (const vector <Telefone *> &contatos)
{
    this->contatos = contatos;
}
vector <Telefone *> Pessoa::getContatos ()
{
    return this->contatos;
}