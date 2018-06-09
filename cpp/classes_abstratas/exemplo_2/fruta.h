#ifndef FRUTA_H
#define FRUTA_H

#include "comida.h"

class Fruta : public Comida
{
	private:
		string validade;
	public:
		//Métoo
		int calorias_pp (const int &);

		void setValidade (const string &);

		string getValidade ();
};

#endif;