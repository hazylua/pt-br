#include "liquido.h"

int Liquido::calorias_pp (const int &porcoes)
{
	cout << "Calorias totais: " << porcoes * getQtdCalorica () << endl;
}

//set().
void Liquido::setViscosidade (const int &viscosidade)
{
	this->viscosidade = viscosidade;
}

//get().
void Liquido::getViscosidade ()
{
	return viscosidade;
}

