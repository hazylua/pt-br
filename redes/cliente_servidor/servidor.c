#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>

int main()
{
    int sock_servidor;
    if( (sock_serivdor = socket( AF_INET, SOCK_STREAM, 0 )) == 0 )
    {
        printf( "Criação de socket no servidor falhou.\n" );
        return -1;
    }
    
}