package main

import (
	"log"
)

// golang不支持全局recover()
// 但是同一个goroutine内是可以recover的

func bug2() {
	panic("bug2()")
}

func bug1() {
	bug2()
}

func main() {
	defer func() {
		if r := recover(); r != nil {
			log.Println("bug2 catched")
		}
	}()

	bug1()

}
