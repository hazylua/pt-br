#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Funcionario
{
    private:
        string nome;
        string telefone;
        string cpf;
        float salario;
        float vendas;
    public:
        Funcionario (const string &, const string &, const string &, const float &, const float &);

        string getNome ();
        string getTelefone ();
        string getCpf ();
        float getSalario ();
        float getVendas ();
        float getComissao ();
};

#endif