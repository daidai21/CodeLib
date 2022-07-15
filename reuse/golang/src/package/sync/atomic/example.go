package main

import (
	"fmt"
	"sync"
	"sync/atomic"
	"time"
)

// ref   http://www.codebaoku.com/it-go/it-go-202710.html

func main() {
	test1()
	test2()
}

func test1() {
	var wg sync.WaitGroup
	count := 0
	t := time.Now()
	for i := 0; i < 50000; i++ {
		wg.Add(1)
		go func(wg *sync.WaitGroup, i int) {
			count++ //count不是并发安全的
			wg.Done()
		}(&wg, i)
	}

	wg.Wait()
	fmt.Println(time.Now().Sub(t))
	fmt.Println("count====>", count) //count的值<50000
	fmt.Println("exit")
}

func test2() {
	var wg sync.WaitGroup
	count := int64(0)
	t := time.Now()
	for i := 0; i < 50000; i++ {
		wg.Add(1)
		go func(wg *sync.WaitGroup, i int) {
			atomic.AddInt64(&count, 1) //原子操作
			wg.Done()
		}(&wg, i)
	}

	wg.Wait()
	fmt.Println(time.Now().Sub(t))
	fmt.Println("count====>", count) //count的值为50000
	fmt.Println("exit")
}
