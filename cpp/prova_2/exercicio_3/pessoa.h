#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>
#include <vector>

#include "profissao.h"

using namespace std;

class Pessoa
{
    private:
        string nome;
        string nascimento;
        string rg;
        string cpf;
        float altura;
        float peso;
        vector <Profissao *> profs;
    public:
        Pessoa (const string &, const string &, const string &, const string &, const float &, const float &, const vector <Profissao *> &);
        
        void setProfs (const vector <Profissao *> &profs);

        string getNome ();
        string getNascimento ();
        string getRg ();
        string getCpf ();
        float getAltura ();
        float getPeso ();
        vector <Profissao *> getProfs ();
        
        void getDados ();
        
};

#endif