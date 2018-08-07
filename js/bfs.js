var nos = [
    {
        //...
    }, {
        //...
    },
]

function bfs ( start ) {
    var lista = [ start ];
    
    nos[ start ].cor = "branco";

    while ( lista.length > 0 ) {
        var u = lista.shift ();
        no [ u ].adj.forEach ( function ( v ) {
            if ( no[ v ].cor == "branco" ) {
                nos [ v ].cor = "cinza";
                lista.push ( v );
            }
        } );
        nos [ v ].cor == "preto";
    }
}

bfs ( 0 );