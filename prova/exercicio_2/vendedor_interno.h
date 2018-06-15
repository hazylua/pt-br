#ifndef VENDEDOR_INTERNO_H
#define VENDEDOR_INTERNO_H

#include "funcionario.h"

class VendedorInterno : public Funcionario
{
    private:
        float vale_transporte;
    public:
        VendedorInterno (const string &nome, const string &telefone, const string &cpf, const float &salario, const float &vendas, const float &);

        float getValeTransporte ();
        float getSalarioInterno ();
};

#endif