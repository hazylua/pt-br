#include "pessoa.h"

Pessoa::Pessoa (const string &nome, const string &nascimento, const string &rg, const string &cpf, const float &altura, const float &peso, const vector <Profissao *> &profs)
{
    this->nome = nome;
    this->nascimento = nascimento;
    this->rg = rg;
    this->cpf = cpf;
    this->altura = altura;
    this->peso = peso;
    this->profs = profs;
}

void Pessoa::setProfs (const vector <Profissao *> &profs)
{
    this->profs = profs;
}

string Pessoa::getNome ()
{
    return nome;
}
string Pessoa::getNascimento ()
{
    return nascimento;
}
string Pessoa::getRg ()
{
    return rg;
}
string Pessoa::getCpf ()
{
    return cpf;
}
float Pessoa::getAltura ()
{
    return altura;
}
float Pessoa::getPeso ()
{
    return peso;
}
vector <Profissao *> Pessoa::getProfs ()
{
    return profs;
}

void Pessoa::getDados ()
{
    int i = 1;
    cout << "Nome: " << this->getNome () << endl;
    cout << "Data de Nascimento: " << this->getNascimento () << endl;
    cout << "RG: " << this->getRg () << endl;
    cout << "CPF: " << this->getCpf () << endl;
    cout << "Altura (em cm): " << this->getAltura () << endl;
    cout << "Peso (em kg): " << this->getPeso () << endl;
    cout << endl;
    vector <Profissao *> v = this->getProfs ();
    for (vector <Profissao *>::iterator it = v.begin (); it != v.end (); it++)
    {
        cout << "## Trabalho " << i << " ##" << endl;
        cout << "> Carga Horária (horas semanais): " << (*it)->getCargaHoraria () << endl;
        cout << "> Remuneração Mensal (em R$): " << (*it)->getRemuneracaoMensal () << endl;
        i++;
    }
    cout << endl;
}