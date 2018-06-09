#include "comida.h"

void Comida::setDescricao (const string &descricao)
{
	this->descricao = descricao;
}
void Comida::setQtdCalorica (const int &qtd_calorica)
{
	this->qtd_calorica = qtd_calorica;
}

string Comida::getDescricao ()
{
	return descricao;
}
int Comida::getQtdCalorica ()
{
	return qtd_calorica;
}
