#include "telefone.h"

Telefone::Telefone (const string &ddd, const string &num_tel)
{
    this->ddd = ddd;
    this->num_tel = num_tel;
}

string Telefone::getDdd ()
{
    return ddd;
}
string Telefone::getNumTel ()
{
    return num_tel;
}