#include "motorizado.h"

void Motorizado::valor_de_venda ()
{
	cout << "Valor de venda: " << getValorAquisicao () - ((getIdadeVeiculo () * 0.08) * getValorAquisicao ())<< endl;
}

void Motorizado::setCilindradas (const int &cilindradas)
{
	this->cilindradas = cilindradas;
}

int Motorizado::getCilindradas ()
{
	return cilindradas;
}

void Motorizado::getMediaCavaloVapor ()
{
	cout << "Média de cavalo-vapor: " << getCilindradas () * getNumRodas () << endl;
}