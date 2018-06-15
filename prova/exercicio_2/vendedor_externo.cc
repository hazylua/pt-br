#include "vendedor_externo.h"

VendedorExterno::VendedorExterno (const string &nome, const string &telefone, const string &cpf, const float &salario, const float &vendas, const float &gasolina) : Funcionario (nome, telefone, cpf, salario, vendas)
{
    this->gasolina = gasolina;
}

float VendedorExterno::getGasolina ()
{
    return gasolina;
}
float VendedorExterno::getSalarioExterno ()
{
    float total = (this->getComissao ()) + (this->getSalario ()) + (this->getGasolina ());
    return total;
}