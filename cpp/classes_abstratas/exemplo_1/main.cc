//Exemplo 1:
//Superclasse que encapsula um veículo.

#include "veiculo.h"
#include "bicicleta.h"
#include "motorizado.h"

void definir_bicicleta (Bicicleta *);
void definir_motorizado (Motorizado *);

int main ()
{
	Bicicleta *b = new Bicicleta ();
	Motorizado *m = new Motorizado ();

	definir_bicicleta (b);
	definir_motorizado (m);

	cout << "*** Bicicleta ***" << endl;
	b->valor_de_venda ();
	
	cout << "*** Motorizado ***" << endl;
	m->valor_de_venda ();
	m->getMediaCavaloVapor ();

	delete (b);
	delete (m);
	
	return 0;
}

void definir_bicicleta (Bicicleta *b)
{
	b->setNomeDono ("Dono 1");
	b->setNumRodas (2);
	b->setAnoFabricacao (2012);
	b->setValorAquisicao (1000);
}
void definir_motorizado (Motorizado *m)
{
	m->setNomeDono ("Dono 2");
	m->setNumRodas (4);
	m->setAnoFabricacao (2012);
	m->setValorAquisicao (2000);

	m->setCilindradas (999);
}