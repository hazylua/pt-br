#include "fruta.h"

int Fruta::calorias_pp (const int &porcoes)
{
	int total = porcoes * getQtdCalorica ();
	return total;
}

void Fruta::setValidade (const string &validade)
{
	this->validade = validade;
}

string Fruta::getValidade ()
{
	return validade;
}