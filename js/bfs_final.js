var nos = [
    {
        // Cabeça
        nome: null
    }, {
        // Vértice 1
        nome: 'a',
        adj: [ 2, 8 ],
        cor: "branco",
        d: null,
        pi: null
    }, {
        // Vértice 2
        nome: 'b',
        adj: [ 1, 8, 3 ],
        cor: "branco",
        d: null,
        pi: null
    }, {
        // Vértice 3
        nome: 'c',
        adj: [ 2, 9, 6, 4 ],
        cor: "branco",
        d: null,
        pi: null
    }, {
        // Vértice 4
        nome: 'd',
        adj: [ 3, 6, 5 ],
        cor: "branco",
        d: null,
        pi: null
    }, {
        // Vértice 5
        nome: 'e',
        adj: [ 4, 6 ],
        cor: "branco",
        d: null,
        pi: null
    }, {
        // Vértice 6
        nome: 'f',
        adj: [ 5, 3, 3, 7 ],
        cor: "branco",
        d: null,
        pi: null
    }, {
        // Vértice 7
        nome: 'g',
        adj: [ 6, 9, 8 ],
        cor: "branco",
        d: null,
        pi: null
    }, {
        // Vértice 8
        nome: 'h',
        adj: [ 1, 2, 9, 7 ],
        cor: "branco",
        d: null,
        pi: null
    }, {
        // Vértice 9
        nome: 'i',
        adj: [ 3, 8, 7 ],
        cor: "branco",
        d: null,
        pi: null
    }
]

function bfs( s ) {
    var lista = [ s ];
    
    nos[ s ].d = 0;

    while( lista.length > 0 ) {
        var u = lista.shift ();
        nos[ u ].adj.forEach( function( v ) { 
            if( nos[ v ].cor == "branco" ) {
                nos[ v ].cor = "cinza";
                nos[ v ].d = nos[ u ].d + 1;
                nos[ v ].pi = u; 
                lista.push ( v );
            }
        } );
        nos[ u ].cor = "preto";
        nos.forEach( function( x ) { console.log( x.d )} );
    }
}

// Começa no vértice A (1)
bfs ( 1 );
