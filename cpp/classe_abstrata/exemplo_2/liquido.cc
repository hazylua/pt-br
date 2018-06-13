#include "liquido.h"

int Liquido::calorias_pp (const int &porcoes)
{
	int total = porcoes * getQtdCalorica ();
	return total;
}

void Liquido::setViscosidade (const int &viscosidade)
{
	this->viscosidade = viscosidade;
}

int Liquido::getViscosidade ()
{
	return viscosidade;
}