package main

import (
	"fmt"
	"time"
)

func NewFuture(f func() (interface{}, error)) func() (interface{}, error) {
	var res interface{}
	var err error

	c := make(chan struct{}, 1)
	go func() {
		defer close(c)
		res, err = f()
	}()
	return func() (interface{}, error) {
		<-c
		return res, err
	}
}

func foo() (interface{}, error) {
	for i := 0; i < 3; i++ {
		time.Sleep(1 * time.Second)
		fmt.Println("foo()...")
	}
	return "foo", nil
}

func bar() (interface{}, error) {
	for i := 0; i < 3; i++ {
		time.Sleep(1 * time.Second)
		fmt.Println("bar()...")
	}
	return "bar", nil
}

func main() {
	// submit and run task
	f := NewFuture(foo)
	b := NewFuture(bar)

	// get result
	fr, fe := f()
	br, be := b()

	// print
	fmt.Println(fr, fe)
	fmt.Println(br, be)
}
