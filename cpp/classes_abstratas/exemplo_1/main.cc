//Exemplo 1:
//Superclasse que encapsula um veículo.
//Tal veículo possui os seguintes atributos: o nome do seu dono, número de rodas, ano de fabricação e o valor de aquisição do veículo.
//Possui um método abstrato: valor de venda.
//A classe abstrata de veículo possui outras duas classes filhas não-abstratas, uma encapsulando uma bicicleta e outra encapsulando um veículo motorizado.
//Uma bicicleta sofre uma desvalorização de 15% por ano em seu valor de venda.
//Um veículo motorizado tem os seguintes atributos adicionais: um atributo cilindrada, em litros, e um método que retorna a média de cavalo-vapor (litros vezes o número de rodas). Um veículo motorizado sofre uma desvalorização de 8% por ano em seu valor de venda.

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