#include "natal.h"

Natal::Natal (const string &nome)
{
    this->setDestinatario (nome);
}

void Natal::showMessage ()
{
    cout << "Feliz Natal, " << this->getDestinatario () << "!" << endl;
}