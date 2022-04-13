package pkg1

import "fmt"

func init() {
	fmt.Println("pkg1.util.init()")
}

func Foo() {
	fmt.Println("call pkg1.util.foo()")
}
