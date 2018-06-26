#ifndef CARTAOWEB_H
#define CARTAOWEB_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CartaoWeb
{
    private:
        string destinatario;
    public:
        virtual void showMessage () = 0;

        void setDestinatario (const string &);

        string getDestinatario ();
};

#endif