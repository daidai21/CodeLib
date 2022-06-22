package main

// ref
// https://github.com/halfrost/Halfrost-Field/blob/master/contents/Go/go_reflection.md#go-reflection-%E4%B8%89%E5%AE%9A%E5%BE%8B%E4%B8%8E%E6%9C%80%E4%BD%B3%E5%AE%9E%E8%B7%B5

import (
	"fmt"
	"reflect"
)

type Foo interface {
	Hello()
}

type foo struct {
	Name string
}

func (f foo) Hello() {
	fmt.Printf("foo::hello")
}

func main() {

	// 反射对象
	var interfaceVar Foo
	interfaceVar = &foo{
		Name: "xxx",
	}
	fmt.Println(interfaceVar)

	// 反射对象 -> Type
	typeVar := reflect.TypeOf(interfaceVar)
	fmt.Println(typeVar)

	// Type -> *Type
	typePtrVar := reflect.PtrTo(typeVar)
	fmt.Println(typePtrVar)

	// *Type -> Type
	fmt.Println(typePtrVar.Elem())

	// Type -> Value
	valueVar := reflect.New(typeVar)
	fmt.Println(valueVar)

	// Value -> Type
	fmt.Println(valueVar.Type())

	// interface -> Value
	valueVar = reflect.ValueOf(interfaceVar)
	fmt.Println(valueVar)

	// Value -> interface
	interfaceVar = valueVar.Interface().(Foo)
	fmt.Println(interfaceVar)

	// Value -> *Value
	interfaceVar2 := foo{
		Name: "123",
	}
	fmt.Println(interfaceVar2)
	valueVar2 := reflect.ValueOf(&interfaceVar2).Elem().Addr()
	fmt.Println(valueVar2)
	valuePtrVar2 := valueVar2.Interface()
	fmt.Println(valuePtrVar2)

	// *Value -> Value
	valueVar2 = reflect.ValueOf(&interfaceVar2).Elem()
	fmt.Println(valueVar2)
	valueVar = reflect.Indirect(reflect.ValueOf(&interfaceVar2))
	fmt.Println(valueVar)
}
