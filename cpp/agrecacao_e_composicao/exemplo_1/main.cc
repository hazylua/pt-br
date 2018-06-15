#include "pessoa.h"
#include "telefone.h"

int main ()
{
    Pessoa *p = new Pessoa ("João");
    vector <Telefone *> t;

    t.push_back (new Telefone ("64", "9 9999 9999"));
    t.push_back (new Telefone ("64", "9 9999 9999"));
    t.push_back (new Telefone ("64", "9 9999 9999"));

    p->setContatos (t);

    vector <Telefone *> v = p->getContatos ();
    for (vector <Telefone *>::iterator it = v.begin (); it != v.end (); it++)
    {
        cout << "(" << (*it)->getDdd () << ") " << (*it)->getNumTel () << endl;
    }
    return 0;
}