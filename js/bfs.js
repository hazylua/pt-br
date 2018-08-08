// adj represente o nó adjacente, sendo que o primeiro número dos pares deste vetor represente o nó adjacente e o segundo número representa a distância entre esses nós. 
var nos = [
    {
        // Vértice 1
        nome: 'a',
        adj: [ [ 2,4 ], [ 8,8 ] ],
        cor: "branco"
    }, {
        // Vértice 2
        nome: 'b',
        adj: [ [1,4 ], [ 8,11 ], [ 3,8 ] ],
        cor: "branco"
    }, {
        // Vértice 3
        nome: 'c',
        adj: [ [ 2,8 ], [ 9,2 ], [ 6,4 ], [ 4,7 ] ],
        cor: "branco"
    }, {
        // Vértice 4
        nome: 'd',
        adj: [ [ 3,7 ], [ 6,14 ], [ 5,9 ] ],
        cor: "branco"
    }, {
        // Vértice 5
        nome: 'e',
        adj: [ [ 4,9 ], [ 6,10 ] ],
        cor: "branco"
    }, {
        // Vértice 6
        nome: 'f',
        adj: [ [ 5,10 ], [ 4,14 ], [ 3,4 ], [ 7,2 ] ],
        cor: "branco"
    }, {
        // Vértice 7
        nome: 'g',
        adj: [ [ 6,2 ], [ 9,1 ], [ 8,1 ] ],
        cor: "branco"
    }, {
        // Vértice 8
        nome: 'h',
        adj: [ [ 1,8 ], [ 2,11 ], [ 9,7 ], [ 7,1 ] ],
        cor: "branco"
    }, {
        // Vértice 9
        nome: 'i',
        adj: [ [ 3,2 ], [ 8,7 ], [ 7,1 ] ],
        cor: "branco"
    }
]

function bfs( s ) {
    var lista = [ s ];
    
    nos[ s ].cor = "branco";

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