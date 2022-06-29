package main

// timer是未来触发单一事件

// timer
// timer#Stop
// timer#Reset
// timer#C

import (
	"fmt"
	"strings"
	"time"
)

func main() {

	timer := time.NewTimer(1 * time.Second)
	select {
	case <-timer.C:
		fmt.Println("等待1秒执行任务")
	}
	timer.Stop() // 这里来提高 timer 的回收

	fmt.Println(strings.Repeat("=", 20))

	timer2 := time.NewTimer(1 * time.Second)
	i := 0
	timer2.Reset(500 * time.Millisecond) // 这样来复用 timer 和修改执行时间
	select {
	case <-timer2.C:
		fmt.Println("等待0.5秒执行任务")
		i++
		if i > 5 {
			break
		}
	}
	timer2.Stop()
}
