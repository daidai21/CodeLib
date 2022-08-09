package main

import (
	"log"
	"os"
)

func init() {
	log.SetPrefix("[example] ")
	log.SetFlags(log.Ldate | log.Ltime | log.Lmicroseconds | log.Lshortfile | log.Lmsgprefix)
	fs, e := os.OpenFile("example.log", os.O_CREATE|os.O_WRONLY|os.O_APPEND, 0666)
	if e != nil {
		panic(e.Error())
	}
	log.SetOutput(fs)
}

func main() {
	log.Print("hello")
}
