#include "funcionario.h"

Funcionario::Funcionario (const string &nome, const string &telefone, const string &cpf, const float &salario, const float &vendas)
{
    this->nome = nome;
    this->telefone = telefone;
    this->cpf = cpf;
    this->salario = salario;
    this->vendas = vendas;
}

string Funcionario::getNome ()
{
    return nome;
}
string Funcionario::getTelefone ()
{
    return telefone;
}
string Funcionario::getCpf ()
{
    return cpf;
}
float Funcionario::getSalario ()
{
    return salario;
}
float Funcionario::getVendas ()
{
    return vendas;
}
float Funcionario::getComissao ()
{
    if (this->getVendas () >= 1000.0)
    {
        float comissao = (getVendas () * 0.10);
        return comissao;
    }
    else
    {
        float comissao = (getVendas () * 0.07);
        return comissao;
    }
}