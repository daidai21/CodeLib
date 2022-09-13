package main

import (
	"log"
	"sync"
)

// golang不支持全局recover()

var wg sync.WaitGroup

func bug2() {
	defer func() {
		if r := recover(); r != nil {
			log.Println("bug2 catched")
		}
		wg.Done()
	}()

	panic("bug2()")
}

func bug1() {
	go bug2()
}

func main() {

	wg.Add(1)
	bug1()

	wg.Wait()
}
