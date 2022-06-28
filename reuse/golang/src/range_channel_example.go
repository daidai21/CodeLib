package main

import (
	"fmt"
	"sync"
)

var wg sync.WaitGroup

func main() {
	wg.Add(1)

	que := make(chan string)

	go func() {
		defer wg.Done()

		for v := range que {
			fmt.Println(v)
		}
	}()

	que <- "1"
	que <- "2"
	que <- "3"

	close(que)
	wg.Wait()
}
