package main

// 是一个定时触发的计时器，它会以一个间隔(interval)往Channel发送一个事件(当前时间)，而Channel的接收者可以以固定的时间间隔从Channel中读取事件。下面的例子中ticker每500毫秒触发一次，你可以观察输出的时间。

import (
	"fmt"
	"strings"
	"time"
)

func main() {
	ticker := time.NewTicker(100 * time.Millisecond)
	i := 0
	for v := range ticker.C {
		fmt.Printf("每隔100ms秒执行任务  %v\n", v)
		i++
		if i > 10 {
			break
		}
	}
	ticker.Stop()

	fmt.Println(strings.Repeat("=", 20))

	j := 0
	for v := range time.Tick(time.Second) {
		fmt.Printf("每隔1s秒执行任务  %v \n", v)
		j++
		if j > 3 {
			break
		}
	}
}
