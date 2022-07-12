package main

import (
	"github.com/daidai21/CodeLib/reuse/golang/src/package/net/http/pprof/demo"
	"log"
	"net/http"
	_ "net/http/pprof"
)

func main() {
	go func() {
		for {
			log.Println(demo.Add("https://github.com/EDDYCJY"))
		}
	}()

	http.ListenAndServe("0.0.0.0:6060", nil)
}
