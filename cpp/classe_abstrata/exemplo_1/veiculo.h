#ifndef VEICULO_H
#define VEICULO_H

#include <iostream>
#include <string>

using namespace std;

class Veiculo
{
	private:
		string nome_dono;
		int num_rodas;
		int ano_fabricacao;
		int valor_aquisicao;
	public:
		virtual void valor_de_venda () = 0;

		void setNomeDono (const string &);
		void setNumRodas (const int &);
		void setAnoFabricacao (const int &);
		void setValorAquisicao (const int &);

		string getNomeDono ();
		int getNumRodas ();
		int getAnoFabricacao ();
		int getValorAquisicao ();

		int getIdadeVeiculo ();
};

#endif