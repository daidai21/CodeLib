package main

import (
	"fmt"
)

// Phone 方法接口
type Phone interface {
	call()
}

// NokiaPhone 对象，保存要存储的属性
type NokiaPhone struct {
	size uint
}

func (nokiaPhone NokiaPhone) call() {
	fmt.Println("I am Nokia, I can call you!")
}

// IPhone 对象，保存要存储的属性
type IPhone struct {
	color string
}

func (iPhone IPhone) call() {
	fmt.Println("I am iPhone, I can call you!")
}

func main() {
	var phone Phone

	phone = new(NokiaPhone)
	phone.call()

	phone = new(IPhone)
	phone.call()

	phone = NokiaPhone{size: 123}
	fmt.Println(phone)
	phone = IPhone{color: "red"}
	fmt.Println(phone)
}
