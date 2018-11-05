var net = require( 'net' );

var server = net.createServer( function( Socket ) {
    socket.write( 'Echo server\r\n' );
    socket.pipe( socket );
} );

server.listen( 8080, 'localhost' );


