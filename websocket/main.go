package main

import (
	"fmt"
	"net/http"
	"time"

	"github.com/gorilla/websocket"
)

var upgrader = websocket.Upgrader{}

type handler int

func main() {
	var handle handler
	http.HandleFunc("/", handle.init)
	http.HandleFunc("/echo/", handle.echo)
	http.ListenAndServe(":8080", nil)
}

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
	timer := time.Tick(60 * time.Second)
	for range timer {
		return
	}
}
