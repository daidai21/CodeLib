package main

import (
	"errors"
	"fmt"
	"strings"
)

func foo(returnRes, returnErr bool) (res int, err error) {
	if returnRes {
		res = 123
	}
	if returnErr {
		err = errors.New("err")
	}
	return
}

func main() {
	fmt.Println(strings.Repeat("=", 10))
	res, err := foo(true, true)
	fmt.Println(res, err)
	res1, err1 := foo(false, true)
	fmt.Println(res1, err1)
	res2, err2 := foo(false, false)
	fmt.Println(res2, err2)

	fmt.Println(strings.Repeat("=", 10))
	res21, _ := foo(true, true)
	fmt.Println(res21)
	_, err22 := foo(true, true)
	fmt.Println(err22)
}
