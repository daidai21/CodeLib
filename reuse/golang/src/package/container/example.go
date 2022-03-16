package main

import (
	"container/list"
	"fmt"
	"strings"
)

// TODO: QA 这里list的元素是强类型还是弱类型？
func listExample() {
	lst := list.New()
	lst.PushFront(1)
	lst.PushBack("1")
	for e := lst.Front(); e != nil; e = e.Next() {
		fmt.Println(e.Value)
	}
	fmt.Println(lst)
}

// heap
func heapExample() {
	// TODO

}

// ring
func ringExample() {
	// TODO

}

func main() {
	fmt.Println(strings.Repeat("=", 10))
	listExample()
	fmt.Println(strings.Repeat("=", 10))

}
