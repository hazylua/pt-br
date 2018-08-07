const nos = [
    {
        //...
    }, {
        //...
    },
]

const dfs = s => {
    const lista = [ s ];
    
    nos[ s ].cor = "branco";

    while ( lista.length ) {
        const u = lista.pop ();
        
        nos[ u ].adj.forEach ( v => {
            if ( nos[ v ].cor == "branco" )
                lista.push ( v );
            nos[ v ].cor = "cinza";
        } );
        nos[ u ].cor = "preto";
    }
}

dfs ( 0 );