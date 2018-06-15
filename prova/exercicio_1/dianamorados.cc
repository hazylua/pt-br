#include "dianamorados.h"

DiaDosNamorados::DiaDosNamorados (const string &nome)
{
    this->setDestinatario (nome);
}

void DiaDosNamorados::showMessage ()
{
    cout << "Feliz Dia dos Namorados, " << this->getDestinatario () << "!" << endl;
}