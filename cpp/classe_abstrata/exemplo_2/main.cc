//Exemplo 2:
//Superclasse abstrata encapsulando uma comida qualquer.

#include "comida.h"
#include "liquido.h"
#include "fruta.h"

void definir_fruta (Fruta *);
void definir_liquido (Liquido *);

int main ()
{
	Fruta *f = new Fruta ();
	Liquido *l = new Liquido ();

	definir_fruta (f);
	definir_liquido (l);

	cout << "*** Fruta ***" << endl;
	cout << "Calorias totais: " << f->calorias_pp (5) << endl;

	cout << "*** Líquido ***" << endl;
	l->getDescricao ();
	cout << "Calorias totais: " << f->calorias_pp (5) << endl;

	delete (f);
	delete (l);
	return 0;
}

void definir_fruta (Fruta *f)
{
	f->setDescricao ("Descrição");
	f->setQtdCalorica (100);
	f->setValidade ("01/01/2019");
}
void definir_liquido (Liquido *l)
{
	l->setDescricao ("Descricação");
	l->setQtdCalorica (200);
	l->setViscosidade (100);
}