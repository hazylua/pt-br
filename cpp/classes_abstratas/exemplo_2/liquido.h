#ifndef LIQUIDO_H
#define LIQUIDO_H

#include "comida.h"

class Liquido : public Comida
{
	private:
		int viscosidade;
	public:
		//Método abstrato.
		int calorias_pp (const int &);

		//set().
		void setViscosidade (const int &);

		//get().
		int getViscosidade ();
};

#endif