package main

import "fmt"

// 多态 例子

type Mammal interface {
	Say()
}

type Dog struct{}

type Cat struct{}

type Human struct{}

func (d Dog) Say() {
	fmt.Println("woof")
}

func (c Cat) Say() {
	fmt.Println("meow")
}

func (h Human) Say() {
	fmt.Println("speak")
}

func main() {
	var m Mammal
	m = Dog{}
	m.Say()
	m = Cat{}
	m.Say()
	m = Human{}
	m.Say()
}
