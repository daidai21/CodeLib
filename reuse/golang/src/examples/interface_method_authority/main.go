package main

import (
	"fmt"
	"strings"
)
import "main/computer"

func main() {
	c := computer.Computer{}

	c.Init(1, 2)

	// Unexported field 'a' usage
	// Unexported method 'exec' usage
	//c.a = 1
	//c.b = 2
	//c.exec()

	fmt.Println(c.GetResult())
	fmt.Println(c.Result)

	fmt.Println(strings.Repeat("=", 10))
	fmt.Println(computer.Add1(1, 1))
	//Unexported function 'add2' usage
	//fmt.Println(computer.add2(2, 3))
}
