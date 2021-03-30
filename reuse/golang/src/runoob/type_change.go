package main

import "fmt"

func main() {
	// 类型转换
	// type_name(expression)
	var sum int = 17
	var count int = 5
	var mean float32
	mean = float32(sum) / float32(count)
	fmt.Printf("mean 的值为: %f\n", mean)

	// 不支持隐式转换类型
	var a int64 = 3
	var b int32
	b = int32(a)
	fmt.Printf("b 为 : %d", b)
}
