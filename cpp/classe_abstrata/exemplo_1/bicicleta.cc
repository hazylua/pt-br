#include "bicicleta.h"

void Bicicleta::valor_de_venda ()
{
	cout << "Valor de venda: " << getValorAquisicao () - ((getIdadeVeiculo () * 0.15) * getValorAquisicao ()) << endl;
}