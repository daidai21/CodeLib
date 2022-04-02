package main

import (
	"fmt"
	"strings"
)

func catchErrorExample() {
	defer func() {
		fmt.Println("defer start")
		if err := recover(); err != nil {
			fmt.Println("catch err: ", err)
		}
		fmt.Println("recover end")
		fmt.Println("defer end")
	}()
	fmt.Println("func running ... ")
	panic("self throw err")
}

func main() {
	// 配置错误就不启动
	//if !checkConfig() {
	//	panic(nil)
	//}

	fmt.Println(strings.Repeat("=", 10))
	catchErrorExample()
}
