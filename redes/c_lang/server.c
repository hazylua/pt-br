#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main()
{
    int socket_welcome, socket_new;
    char buffer[255];
    struct sockaddr_in servidor_endereco;
    struct sockaddr_storage servidor_storage;
    socklen_t endereco_tam;

    socket_welcome = socket( PF_INET, SOCK_STREAM, 0 );

    servidor_endereco.sin_family = AF_INET;
    servidor_endereco.sin_port = htons( 8080 );
    servidor_endereco.sin_addr.s_addr = inet_addr( "127.0.0.1" );
    memset( servidor_endereco.sin_zero, '\0', sizeof (servidor_endereco.sin_zero) );

    bind( socket_welcome, (struct sockaddr *) &servidor_endereco, sizeof( servidor_endereco ) );

    while( 1 )
    {    
        if( listen(socket_welcome, 5) == 0 )
            printf( "Listening.\n" );
        else
            printf( "Erro.\n" );
        
        endereco_tam = sizeof( servidor_storage );
        socket_new = accept( socket_welcome, (struct sockaddr *) &servidor_storage, &endereco_tam);

        printf( "Mensagem: " );
        scanf( "%s", buffer );
        //strcpy( buffer,"Hello World\n" );
        send( socket_new, buffer, 255, 0 );
    }    
    return 0;

}