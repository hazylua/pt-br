#ifndef VENDEDOR_EXTERNO_H
#define VENDEDOR_EXTERNO_H

#include "funcionario.h"

class VendedorExterno : public Funcionario
{
    private:
        float gasolina;
    public:
        VendedorExterno (const string &nome, const string &telefone, const string &cpf, const float &salario, const float &vendas, const float &);

        float getGasolina ();
        float getSalarioExterno ();
};

#endif