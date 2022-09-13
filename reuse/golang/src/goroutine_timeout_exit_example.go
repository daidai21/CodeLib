package main

import (
	"fmt"
	"time"
)

// 使用channel ,主线程等待消费，超时不再消费
// 没法停止子 goroutine，那就让继续执行计算，但是返回的结果不再append就行
// 以 chanNode/func 都可为计算step（chanNode<-就行 为一个step）

// chanNode 消费和生产交互的节点
type chanNode struct {
	Id       int
	FuncName string
	Result   string
}

func concurrentExec1(id int, resultChan chan chanNode) {

	for i := 0; i < 5; i++ {
		res := chanNode{}
		res.Id = id
		res.FuncName = "concurrentExec1"
		res.Result = "concurrentExec1 result"
		resultChan <- res

		time.Sleep(1 * time.Second)
	}
}

func concurrentExec2(id int, resultChan chan chanNode) {

	for i := 0; i < 5; i++ {
		res := chanNode{}
		res.Id = id
		res.FuncName = "concurrentExec2"
		res.Result = "concurrentExec2 result"

		resultChan <- res

		time.Sleep(1 * time.Second)
	}

}

func main() {
	var result []string
	// 通信channel
	resultChan := make(chan chanNode, 10)
	// 子goroutine concurrentExec1 和 concurrentExec2 往 ResultChan 写数据
	go concurrentExec1(1, resultChan)
	go concurrentExec2(2, resultChan)

	// 主goroutine消费数据
	done := time.NewTicker(time.Second * 2)
	for {
		select {
		case <-done.C:
			fmt.Println("time.After")
			goto Loop
		case v := <-resultChan: // 消费append
			fmt.Println("case consumer append")
			result = append(result, v.Result)
		}
	}
Loop:
	fmt.Println("Loop")
	//close(resultChan)

	// 输出结果
	fmt.Println(result)
	fmt.Println(len(result))
}
