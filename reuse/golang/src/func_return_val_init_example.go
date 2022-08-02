package main

// 返回的变量需要自己初始化

import "fmt"

func main() {
	a1, b1, c1 := foo1()
	fmt.Println(a1)
	(*a1)[1] = "aasd"
	fmt.Println(b1)
	(*b1).M1 = 1
	fmt.Println(c1)

	fmt.Println("======")
	a, b, c := foo()
	fmt.Println(a)
	(*a)[1] = "aasd"
	fmt.Println(b)
	fmt.Println(c)
}

func foo1() (mp *map[int]string, st *Bar, e error) {
	m := make(map[int]string)
	return &m, st, e
}

func foo() (mp *map[int]string, st *Bar, e error) {
	return
}

type Bar struct {
	M1 int
	M2 string
}
