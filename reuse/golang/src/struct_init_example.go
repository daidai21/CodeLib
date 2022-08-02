package main

import "fmt"

// var 是可以初始化结构体的
// https://yourbasic.org/golang/structs-explained/

func main() {
	var s1 Ss
	s1.A = 1
	s1.B = "asd"
	fmt.Println(s1)
}

type Ss struct {
	A int
	B string
}
