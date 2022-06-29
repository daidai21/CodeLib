package main

import (
	"fmt"
	"sync"
	"time"
)

func main() {
	// 关键人物出场
	m := sync.Map{}
	m.Store(1, 1)
	go do(m)
	go do(m)

	time.Sleep(1 * time.Second)
	fmt.Println(m.Load(1))
}

func do(m sync.Map) {
	i := 0
	for i < 10000 {
		m.Store(1, 1)
		i++
	}
}
