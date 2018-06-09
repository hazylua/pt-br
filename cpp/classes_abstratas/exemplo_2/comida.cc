#include "comida.h"

//set().
void Comida::setDescricao (const string &descricao)
{
	this->descricao = descricao;
}
void Comida::setQtdCalorica (const int &qtd_calorica)
{
	this->qtd_calorica = qtd_calorica;
}

//get().
string Comida::getDescricao ()
{
	return descricao;
}
int Comida::getQtdCalorica ()
{
	return qtd_calorica;
}
