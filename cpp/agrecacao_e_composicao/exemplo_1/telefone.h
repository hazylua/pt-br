#ifndef TELEFONE_H
#define TELEFONE_H

#include <iostream>
#include <string>

using namespace std;

class Telefone
{
    private:
        string ddd;
        string num_tel;
    public:
        Telefone (const string &, const string &);
        
        string getDdd ();
        string getNumTel ();
};

#endif