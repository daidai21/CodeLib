package main

import (
	"log"
	"sync"
)

// 同一个goroutine内可以global recover()

func bug2() {
	panic("bug2()")
}

func bug1() {
	var wg sync.WaitGroup
	wg.Add(1)
	go func() {
		defer func() {
			if r := recover(); r != nil {
				log.Println("bug1 catched")
			}
			wg.Done()
		}()
		bug2()
	}()
	wg.Wait()
}

func main() {
	bug1()
}
