#include "funcionario.h"
#include "vendedor_externo.h"
#include "vendedor_interno.h"

int menu ();

int main ()
{
    int op = 1, i = 1;
    vector <VendedorExterno *> ve;
    vector <VendedorInterno *> vi;
    string nome, telefone, cpf;
    float salario, vendas, gasolina, vale_transporte;
    while (op != 0)
    {   
        op = menu ();
        switch (op)
        {
            case 1:
            {
                cout << "*** Cadastro de vendedor externo ***" << endl;
                cout << "> Nome: ";
                cin >> nome;
                cin.ignore ();
                cout << "> Telefone: ";
                cin >> telefone;
                cin.ignore ();
                cout << "> CPF: ";
                cin >> cpf;
                cin.ignore ();
                cout << "> Salário (em R$): ";
                cin >> salario;
                cin.ignore ();
                cout << "> Vendas (em R$): ";
                cin >> vendas;
                cin.ignore ();
                cout << "> Gasolina gasta (em R$): ";
                cin >> gasolina;
                cin.ignore ();
                ve.push_back (new VendedorExterno (nome, telefone, cpf, salario, vendas, gasolina));
                cout << endl;
            } break;
            case 2:
            {
                cout << "*** Cadastro de vendedor interno ***" << endl;
                cout << "> Nome: ";
                cin >> nome;
                cin.ignore ();
                cout << "> Telefone: ";
                cin >> telefone;
                cin.ignore ();
                cout << "> CPF: ";
                cin >> cpf;
                cin.ignore ();
                cout << "> Salário (em R$): ";
                cin >> salario;
                cin.ignore ();
                cout << "> Vendas (em R$): ";
                cin >> vendas;
                cin.ignore ();
                cout << "> Vale transporte (em R$): ";
                cin >> vale_transporte;
                cin.ignore ();
                vi.push_back (new VendedorInterno (nome, telefone, cpf, salario, vendas, vale_transporte));
                cout << endl;
            } break;
            case 3:
            {
                i = 1;
                cout << "*** Relatório dos vendedores externos ***" << endl;
                for (vector <VendedorExterno *>::iterator it = ve.begin (); it != ve.end (); it++)
                {
                    cout << "> Vendedor #" << i << endl;
                    cout << "Nome: " << (*it)->getNome () << endl;
                    cout << "Telefone: " << (*it)->getTelefone () << endl;
                    cout << "CPF: " << (*it)->getCpf () << endl;
                    cout << "Salario: " << (*it)->getSalarioExterno () << endl;
                    i++;
                }
                cout << endl;
            } break;
            case 4:
            {
                i = 1;
                cout << "*** Relatório dos vendedores internos ***" << endl;
                for (vector <VendedorInterno *>::iterator it = vi.begin (); it != vi.end (); it++)
                {
                    cout << "> Vendedor #" << i << endl;
                    cout << "Nome: " << (*it)->getNome () << endl;
                    cout << "Telefone: " << (*it)->getTelefone () << endl;
                    cout << "CPF: " << (*it)->getCpf () << endl;
                    cout << "Salario: " << (*it)->getSalarioInterno () << endl;
                    i++;
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
    cout << "1. Cadastrar vendedor externo." << endl;
    cout << "2. Cadastrar vendedor interno." << endl;
    cout << "3. Mostrar relatório dos vendedores externos." << endl;
    cout << "4. Mostrar relatório dos vendedores internos." << endl;
    cout << "> Escolha: ";
    cin >> op;
    cin.ignore ();
    cout << endl;
    return op;
}