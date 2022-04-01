package main

// 判断 type+value是否相等

import "fmt"

func main() {
	var a *int
	var b *int
	var c interface{}
	fmt.Println(a == nil)
	fmt.Println(b == nil)
	fmt.Println(c == nil)

	fmt.Println(a == b)
	fmt.Println(b == c)
}
