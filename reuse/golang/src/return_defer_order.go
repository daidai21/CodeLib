package main

import "fmt"

func main() {
	fmt.Println(fn()) // 结果是4
}

func fn() (res int) {
	defer func() {
		res = 4
	}()
	return 3
}
