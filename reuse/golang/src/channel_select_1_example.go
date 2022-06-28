package main

// select的default逻辑

import (
	"sync"
	"time"
)

var wg sync.WaitGroup

func main() {
	wg.Add(1)
	ch := make(chan string)

	go func() {
		defer wg.Done()

		for _ = range [10]int{} {
			time.Sleep(1 * time.Millisecond)
			select {
			case i := <-ch:
				println(i)
			default:
				println("default")
			}
		}
	}()

	ch <- "1"
	time.Sleep(1 * time.Millisecond)
	ch <- "2"
	time.Sleep(1 * time.Millisecond)
	ch <- "3"
	time.Sleep(1 * time.Millisecond)
	ch <- "4"
	time.Sleep(1 * time.Millisecond)
	ch <- "5"

	close(ch)
	wg.Wait()
}
