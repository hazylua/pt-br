#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main()
{
    int socket_cliente;
    char buffer[255];
    struct sockaddr_in servidor_endereco;
    socklen_t endereco_tam;

    socket_cliente = socket( PF_INET, SOCK_STREAM, 0 );

    servidor_endereco.sin_family = AF_INET;
    servidor_endereco.sin_port = htons( 8080 );
    servidor_endereco.sin_addr.s_addr = inet_addr( "127.0.0.1" );
    memset( servidor_endereco.sin_zero, '\0', sizeof (servidor_endereco.sin_zero) );

    endereco_tam = sizeof( servidor_endereco );
    
    while( 1 )
    {
        connect( socket_cliente, (struct sockaddr *) &servidor_endereco, endereco_tam );

        recv( socket_cliente, buffer, 255, 0 );

        printf( "Recebido: %s\n", buffer );
    }

    return 0;
}