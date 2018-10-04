#include <stdio.h>
#include <math.h>

unsigned long long int multiplica( int, int, int );

int main() {

    int u = 10000000, v = 7, n = 8;
    printf( "u = %d, v = %d, n = %d\n", u, v, n );
    printf("%llu\n", multiplica(u, v, n));
    return 0;
}

unsigned long long int multiplica( int u, int v, int n ) {

    if( n == 1 )    
        return (u * v);
    else {
        int k = (n / 2);
        int q = pow( 10, k );

        int a = (u / q);
        int b = (u % q);

        int c = (v / q);
        int d = (v % q);

        int ac = multiplica( a, c, k );
        int bd = multiplica( b, d, k );
        int ad = multiplica( a, d, k );
        int bc = multiplica( b, c, k );

        unsigned long long int x = ac * pow(10, 2 * k) + (ad + bc) * pow(10, k) + bd;
        
        return x;
    }
}
