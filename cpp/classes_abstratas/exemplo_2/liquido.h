#ifndef LIQUIDO_H
#define LIQUIDO_H

#include "comida.h"

class Liquido : public Comida
{
	private:
		int viscosidade;
	public:
		int calorias_pp (const int &);

		void setViscosidade (const int &);

		int getViscosidade ();
};

#endif