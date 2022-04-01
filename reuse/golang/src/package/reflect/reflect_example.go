package main

//
// https://pkg.go.dev/reflect
// TODO: https://halfrost.com/go_reflection/

import (
	"fmt"
	"reflect"
	"strings"
)

func main() {
	var A int
	typeOfA := reflect.TypeOf(A)
	// 变量的类型名为 int，种类（Kind）为 int
	fmt.Println(typeOfA.Name(), typeOfA.Kind(), reflect.ValueOf(A))

	fmt.Println(strings.Repeat("=", 10))

	type Cat struct {
	}
	typeOfCat := reflect.TypeOf(Cat{})
	fmt.Println(typeOfCat.Name(), typeOfCat.Kind())
	if v := typeOfCat.Kind(); v == reflect.Struct {
		fmt.Println("typeOfCat.Kind() == reflect.Struct")
	}

	fmt.Println(strings.Repeat("=", 10))

	type AnimalEnum int
	const (
		DogEnum AnimalEnum = 1
		PigEnum AnimalEnum = 2
	)
	typeOfPigEnum := reflect.TypeOf(PigEnum)
	fmt.Println(typeOfPigEnum.Name(), typeOfPigEnum.Kind())

	fmt.Println(strings.Repeat("=", 10))

	assertExample()
}

type InterfaceType interface {
	foo()
}
type StructType struct {
	bar string
}

func (s StructType) foo() {

}

func assertExample() {
	A := StructType{bar: "asd"}

	// 获取类型
	// Ref: https://stackoverflow.com/questions/23172219/cannot-type-switch-on-non-interface-value
	if b, ok := interface{}(A).(InterfaceType); ok {
		fmt.Println(b)
	} else {
		fmt.Println("b := .(InterfaceType) failed")
	}
	if c, ok := interface{}(A).(StructType); ok {
		fmt.Println(c)
	} else {
		fmt.Println("c := .(StructType) failed")
	}
	if d, ok := interface{}(A).(int); ok {
		fmt.Println(d)
	} else {
		fmt.Println("d := .(int) failed")
	}
}
