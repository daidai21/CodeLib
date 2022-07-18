package main

import (
	"fmt"
	"math/rand"
	"runtime"
	"time"
)

// select+channel 控制goroutine退出

func main() {

	for i := 0; i < 10; i++ {
		fmt.Println("============= SyncWithTimeout")
		res := SyncWithTimeout(func() {
			// 随机随眠
			r := randRangeInt(1, 3)
			fmt.Printf("sleep %v ms\n", r)
			time.Sleep(time.Duration(r) * time.Millisecond)
		}, 2*time.Millisecond)

		fmt.Println(res)

	}
	// 子协程退出了
	fmt.Println("runtime.NumGoroutine() ", runtime.NumGoroutine())
}

func SyncWithTimeout(fn func(), timeout time.Duration) bool {
	done := make(chan bool, 1)
	go func(quit chan bool) {
		fn()
		quit <- true
	}(done)
	select {
	case <-done:
		return true
	case <-time.After(timeout):
		return false
	}
}

var randRangeInt = func(start, end int) int {
	return start + rand.Intn(end-start)
}
