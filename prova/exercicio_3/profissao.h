#ifndef PROFISSAO_H
#define PROFISSAO_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Profissao
{
    private:
        float carga_horaria;
        float remuneracao_mensal;
    public:
        Profissao (const float &, const float &);

        float getCargaHoraria ();
        float getRemuneracaoMensal ();
};

#endif
