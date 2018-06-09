#include "veiculo.h"

int ano_atual = 2014;

void Veiculo::setNomeDono (const string &nome_dono)
{
	this->nome_dono = nome_dono;
}
void Veiculo::setNumRodas (const int &num_rodas)
{
	this->num_rodas = num_rodas;
}
void Veiculo::setAnoFabricacao (const int &ano_fabricacao)
{
	this->ano_fabricacao = ano_fabricacao;
}
void Veiculo::setValorAquisicao (const int &valor_aquisicao)
{
	this->valor_aquisicao = valor_aquisicao;
}

string Veiculo::getNomeDono ()
{
	return nome_dono;
}
int Veiculo::getNumRodas ()
{
	return num_rodas;
}
int Veiculo::getAnoFabricacao ()
{
	return ano_fabricacao;
}
int Veiculo::getValorAquisicao ()
{
	return valor_aquisicao;
}

int Veiculo::getIdadeVeiculo ()
{
	return ano_atual - ano_fabricacao;
}

