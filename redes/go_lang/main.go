package main

import (
	"fmt"
	"net/http"
	"time"

	//Implementação de WebSocket para Go.
	"github.com/gorilla/websocket"
)

var upgrader = websocket.Upgrader{}

//Define handler.
type handler int

func main() {
	var handle handler

	//Adicionam handlers a DefaultServerMux
	
	//Ao ser acessado localhost:8080, uma página html será inicializada.
	http.HandleFunc("/", handle.init)
	//Toda vez que o cliente enviar uma mensagem ao servidor, é estabelecida uma conexão entre eles.
	http.HandleFunc("/echo/", handle.echo)


	//Inicia o servidor com uma handler (nil = DefaultServerMux).
	http.ListenAndServe(":8080", nil)
}

//	Equivalente a:
//	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
//		fmt.Fprintf(w, "Hello, %q", html.EscapeString(r.URL.Path))
//	})

func (h handler) init(w http.ResponseWriter, r *http.Request) {
	fmt.Println("Home page served...")
	http.ServeFile(w, r, "index.html")
}

func (h handler) echo(w http.ResponseWriter, r *http.Request) {
	n := 0
	conn, _ := upgrader.Upgrade(w, r, nil)

	go readConnection(conn, &n)
	go writeConnection(conn)
}

func readConnection(con *websocket.Conn, n *int) {
	for {
		_, _, err := con.ReadMessage()
		fmt.Println(err)
		if err == nil {
			(*n) = *n + 1
			fmt.Println("Handling connection! ", *n)
		} else {
			fmt.Println("Connection lost or closed!")
			con.Close()
			return
		}
	}
}

func writeConnection(con *websocket.Conn) {

	for {
		timer()
		fmt.Println("Time's up!")
	}

}
func timer() {

	timer := time.Tick(120 * time.Second)
	for range timer {
		return
	}
}
