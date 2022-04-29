package main

import "fmt"

// 多态 例子
// Dog, Cat, Human是Mammal的三种不同实现

type Mammal interface {
	Say()
}

type Dog struct{}

func (d Dog) Say() {
	fmt.Println("woof")
}

type Cat struct{}

func (c Cat) Say() {
	fmt.Println("meow")
}

type Human struct{}

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
