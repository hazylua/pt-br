#include "cartaoweb.h"
#include "dianamorados.h"
#include "aniversario.h"
#include "natal.h"

int menu ();

int main ()
{
    int op;
    vector <CartaoWeb *> cartoes;
    string nome;
    while (op != 0)
    {   
        op = menu ();
        switch (op)
        {
            case 1:
            {
                cout << "> Digite o nome do destinatário: ";
                cin >> nome;
                cin.ignore ();
                cartoes.push_back (new DiaDosNamorados (nome));
                cout << endl;
            } break;
            case 2:
            {
                cout << "> Digite o nome do destinatário: ";
                cin >> nome;
                cin.ignore ();
                cartoes.push_back (new Aniversario (nome));
                cout << endl;
            } break;
            case 3:
            {
                cout << "> Digite o nome do destinatário: ";
                cin >> nome;
                cin.ignore ();
                cartoes.push_back (new Natal (nome));
                cout << endl;
            } break;
            case 4:
            {
                for (vector <CartaoWeb *>::iterator it = cartoes.begin (); it != cartoes.end (); it++)
                {
                    (*it)->showMessage ();
                }
                cout << endl;
            } break;
            case 0:
            {
                return 0;
            }
        }
    }
    return 0;
}

int menu ()
{
    int op;
    cout << "0. Sair do programa." << endl;
    cout << "1. Cadastrar cartão do dia dos namorados." << endl;
    cout << "2. Cadastrar cartão de natal." << endl;
    cout << "3. Cadastar cartão de aniversário." << endl;
    cout << "4. Mostrar mensagens de todos os cartões cadastrados." << endl;
    cout << "> Escolha: ";
    cin >> op;
    cin.ignore ();
    cout << endl;
    return op;
}