#ifndef COMIDA_H
#define COMIDA_H

#include <iostream>
#include <string>

class Comida
{
	private:
		string descricao;
		int qtd_calorica;
	public:
		//Método abstrato.
		virtual int calorias_pp (const int &) = 0;

		//set().
		void setDescricao (const string &);
		void setQtdCalorica (const int &);

		//get().
		string getDescricao ();
		int getQtdCalorica ();
};

#endif