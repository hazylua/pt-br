#include "aniversario.h"

Aniversario::Aniversario (const string &nome)
{
    this->setDestinatario (nome);
}

void Aniversario::showMessage ()
{
    cout << "Feliz Aniversário, " << this->getDestinatario () << "!" << endl;
}