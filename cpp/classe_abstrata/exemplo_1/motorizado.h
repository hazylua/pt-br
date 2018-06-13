#ifndef MOTORIZADO_H
#define MOTORIZADO_H

#include "veiculo.h"

class Motorizado : public Veiculo
{
	private:
		int cilindradas;
	public:
		void valor_de_venda ();
		
		void setCilindradas (const int &);

		int getCilindradas ();
		
		void getMediaCavaloVapor ();
};

#endif