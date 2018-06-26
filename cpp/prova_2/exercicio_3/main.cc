#include "pessoa.h"
#include "profissao.h"

int menu ();

int main ()
{
    int op = 1, num_trabalhos, i;
    vector <Pessoa *> agenda;
    while (op != 0)
    {   
        op = menu ();
        switch (op)
        {
            case 1:
            {
                vector <Profissao *> profs;
                profs.push_back (new Profissao (10.0, 1000.0));
                profs.push_back (new Profissao (20.0, 2000.0));
                agenda.push_back (new Pessoa ("Aluno", "100", "100", "100", 100.0, 100.0, profs));
            } break;
            case 2:
            {
                int i = 1;
                cout << "*** Relatório dos estudantes cadastrados ***" << endl;
                for (vector <Pessoa *>::iterator it = agenda.begin (); it != agenda.end (); it++)
                {
                    (*it)->getDados ();
                    i++;
                }
                cout << endl;
            } break;
            case 0:
            {
                return 0;
            } break;
        }
    }
    return 0;

    return 0;
}

int menu ()
{
    int op;
    cout << "0. Sair do programa." << endl;
    cout << "1. Cadastrar estudante." << endl;
    cout << "2. Relatório de estudantes cadastrados." << endl;
    cout << "> Escolha: ";
    cin >> op;
    cin.ignore ();
    cout << endl;
    return op;
}