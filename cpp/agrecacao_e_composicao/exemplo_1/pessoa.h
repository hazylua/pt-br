#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>
#include <vector>

#include "telefone.h"

using namespace std;

class Pessoa
{
    private:
        string nome;
        vector <Telefone *> contatos;
    public:
        Pessoa (const string &);
        
        void setContatos (const vector <Telefone *> &);
        vector <Telefone *> getContatos ();
};

#endif