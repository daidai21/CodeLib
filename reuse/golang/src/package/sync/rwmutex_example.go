package main

// ref
// https://gist.github.com/lijianying10/93cfdab8e8aa6850ffd58afcb0ef3ba3

import (
	"fmt"
	"strconv"
	"sync"
	"time"
)

var (
	data map[string]string
	lock sync.RWMutex
)

func main() {
	data = make(map[string]string)
	wticker := time.NewTicker(time.Millisecond * 500)
	rticker := time.NewTicker(time.Millisecond * 500)

	// 两个goroutine 可以同时读
	go func() {
		for t := range rticker.C {
			lock.RLock()
			time.Sleep(time.Millisecond * 1500)
			fmt.Println("read 1 at", t, len(data))
			lock.RUnlock()
		}
	}()
	go func() {
		for t := range rticker.C {
			lock.RLock()
			time.Sleep(time.Millisecond * 1500)
			fmt.Println("read 2 at", t, len(data))
			lock.RUnlock()
		}
	}()
	time.Sleep(5 * time.Second)

	// 这个goroutine开始了之后读活动就会被卡住
	go func() {
		counter := 0
		// 下面两个时间点中间是有读操作的，在读操作中是不可以进行写操作的
		fmt.Println("request write data at ", time.Now())
		lock.Lock()
		fmt.Println("start write data at ", time.Now())
		for t := range wticker.C {
			counter++
			fmt.Println("write at", t)
			data[strconv.Itoa(counter)] = strconv.Itoa(counter)
			if counter > 10 {
				break
			}
		}
		lock.Unlock()
	}()
	select {}
}
