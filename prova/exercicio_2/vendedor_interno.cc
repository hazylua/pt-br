#include "vendedor_interno.h"

VendedorInterno::VendedorInterno (const string &nome, const string &telefone, const string &cpf, const float &salario, const float &vendas, const float &vale_transporte) : Funcionario (nome, telefone, cpf, salario, vendas)
{
    this->vale_transporte = vale_transporte;
}

float VendedorInterno::getValeTransporte ()
{
    return vale_transporte;
}
float VendedorInterno::getSalarioInterno ()
{
    float total = (this->getComissao ()) + (this->getSalario ()) + (this->getValeTransporte ());
    return total;
}