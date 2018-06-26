#ifndef NATAL_H
#define NATAL_H

#include "cartaoweb.h"

class Natal : public CartaoWeb
{
    private:
    public:
        Natal (const string &);
        void showMessage ();
};

#endif