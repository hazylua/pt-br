#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>

int main()
{
    int sock_sv;
    struct sockaddr_in *endereco;
    int endereco_tam;

    endereco_tam = sizeof( endereco_tam );

    if( (sock_servidor = socket( AF_INET, SOCK_STREAM, 0 )) == 0 )
    {
        printf( "Criação de socket no servidor falhou.\n" );
        return -1;
    }

    endereco.sin_family = AF_INET;
    endereco.sin_addr.s_addr = INADDR_ANY;
    endereco.sin_port = htons( PORT );

    if( bind( sock_servidor, endereco_servidor, endereco_tam ) < 0 )
    {
        printf( "Bind falhou.\n" );
        return -1;
    }

    if( listen( sock_servidor, 3 ) < 0 )
    {
        printf( "Listen falhou.\n" );
        return -1;
    }


    
}