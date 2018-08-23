var nos = [
    {
        // Cabeça
        nome: null,
    }, {
        // Vértice 1
        nome: 'a',
        adj: [ 2, 8 ],
        cor: "branco",
        d: null,
        pi: null,
        f: null,
    }, {
        // Vértice 2
        nome: 'b',
        adj: [ 1, 8, 3 ],
        cor: "branco",
        d: null,
        pi: null,
        f: null,
    }, {
        // Vértice 3
        nome: 'c',
        adj: [ 2, 9, 6, 4 ],
        cor: "branco",
        d: null,
        pi: null,
        f: null,
    }, {
        // Vértice 4
        nome: 'd',
        adj: [ 3, 6, 5 ],
        cor: "branco",
        d: null,
        pi: null,
        f: null,
    }, {
        // Vértice 5
        nome: 'e',
        adj: [ 4, 6 ],
        cor: "branco",
        d: null,
        pi: null,
        f: null,
    }, {
        // Vértice 6
        nome: 'f',
        adj: [ 5, 3, 3, 7 ],
        cor: "branco",
        d: null,
        pi: null,
        f: null,
    }, {
        // Vértice 7
        nome: 'g',
        adj: [ 6, 9, 8 ],
        cor: "branco",
        d: null,
        pi: null,
        f: null,
    }, {
        // Vértice 8
        nome: 'h',
        adj: [ 1, 2, 9, 7 ],
        cor: "branco",
        d: null,
        pi: null,
        f: null,
    }, {
        // Vértice 9
        nome: 'i',
        adj: [ 3, 8, 7 ],
        cor: "branco",
        d: null,
        pi: null,
        f: null,
    }
]

var tempo = 0;

function dfs( s ) {
    const lista = [ s ];

    while( lista.length > 0 ) {
        var u = lista.pop();
        
        nos[ u ].adj.forEach( function ( v ) {
            if( nos[ v ].cor == "branco" )
                dfs_visit( nos[ v ] );
        } );
    }
}

function dfs_visit( u ) {
    tempo += 1;
    u.d = tempo;
    u.cor = "cinza";
    u.adj.forEach( function( v ) { 
        if( nos[ v ].cor == "branco" ) {
            nos[ v ].pi = u;
            dfs_visit( nos[ v ] );
        }
    } );
    u.cor = "preto";
    tempo += 1;
    u.f = tempo;
}

dfs( 1 );