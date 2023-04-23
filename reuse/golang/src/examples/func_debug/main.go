package main

import (
	"fmt"
	"time"
)

var isDebug = false

func foo(s string) (ret string, err error) {
	var (
		start = time.Now()
	)
	defer func() {
		if isDebug {
			time.Sleep(1 * time.Second)
			fmt.Println("foo() defer() ", s, ret, err, time.Now().Sub(start).Seconds())
		}
	}()

	fmt.Println("foo() start deal...")

	ret = "output"

	return
}

func main() {
	{
		isDebug = false
		s, err := foo("input")
		if err != nil {
			fmt.Println("main() err=", err)
		}
		fmt.Println("main() s=", s)

		time.Sleep(1 * time.Second)
	}

	fmt.Println("=====")
	{
		isDebug = true
		s, err := foo("input")
		if err != nil {
			fmt.Println("main() err=", err)
		}
		fmt.Println("main() s=", s)

		time.Sleep(1 * time.Second)
	}
}
