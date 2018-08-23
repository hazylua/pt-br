#ifndef COMIDA_H
#define COMIDA_H

#include <iostream>
#include <string>

using namespace std;

class Comida
{
	private:
		string descricao;
		int qtd_calorica;
	public:
		virtual int calorias_pp (const int &) = 0;

		void setDescricao (const string &);
		void setQtdCalorica (const int &);

		string getDescricao ();
		int getQtdCalorica ();
};

#endif