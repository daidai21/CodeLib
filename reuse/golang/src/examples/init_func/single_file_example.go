package main

// 初始化顺序：变量初始化->init()->main()

import (
	"fmt"
)

var T int64 = a()

func init() {
	fmt.Println("init in single_file_example.go ")
}

func a() int64 {
	fmt.Println("calling a()")
	return 2
}
func main() {
	fmt.Println("calling main")
}
