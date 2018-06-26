#include "profissao.h"

Profissao::Profissao (const float &carga_horaria, const float &remuneracao_mensal)
{
    this->carga_horaria = carga_horaria;
    this->remuneracao_mensal = remuneracao_mensal;
}

float Profissao::getCargaHoraria ()
{
    return carga_horaria;
}
float Profissao::getRemuneracaoMensal ()
{
    return remuneracao_mensal;
}