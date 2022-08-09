package main

import "fmt"

func main() {
	v1 := &foo{}
	fmt.Printf("%p\n", &v1)
	var v2 Foo = v1
	fmt.Printf("%p\n", &v2)
	v3 := interface{}(v2).(*Foo)
	fmt.Printf("%p\n", &v3)

	FnM(v1)
	FnM(v2)
}

type Foo interface {
	Bar()
}

type foo struct {
}

func (f *foo) Bar() {
	fmt.Println("foo.Bar()")
}

func FnM(f Foo) {
	fmt.Printf("FnM()\n")
}
