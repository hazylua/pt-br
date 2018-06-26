#include "cartaoweb.h"

void CartaoWeb::setDestinatario (const string &destinatario)
{
    this->destinatario = destinatario;
}

string CartaoWeb::getDestinatario ()
{
    return destinatario;
}