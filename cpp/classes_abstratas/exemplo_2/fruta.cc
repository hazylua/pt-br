#include "fruta.h"

int Fruta::calorias_pp (const int &porcoes)
{
	cout << "Calorias totais: " << porcoes * getQtdCalorica () << endl;
}

//set().
void Fruta::setValidade (const int &validade)
{
	this->validade = validade;
}

//get().
void Fruta::getValidade ()
{
	return validade;
}