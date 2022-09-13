package main

import (
	"fmt"
	"strconv"
	"time"
)

// 两个goroutine都是append的话，都是for 1000次的话，必须加锁，不然结果len(slice) != 2000
// 同时写结果也可能有问题
// slice 同一个index不同的goroutine操作并不会panic

func main() {
	arr := []string{"a", "b", "c", "d"}
	go func() {
		for {
			arr[2] = strconv.FormatInt(time.Now().Unix(), 10)
		}
	}()

	go func() {
		for {
			fmt.Println(arr[2])
		}
	}()

	go func() {
		for {
			arr[2] = strconv.FormatInt(time.Now().Unix(), 10)
		}
	}()

	time.Sleep(10 * time.Second)
	return
}
