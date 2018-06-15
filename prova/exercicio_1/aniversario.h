#ifndef ANIVERSARIO_H
#define ANIVERSARIO_H

#include "cartaoweb.h"

class Aniversario : public CartaoWeb
{
    private:
    public:
        Aniversario (const string &);
        void showMessage ();
};

#endif