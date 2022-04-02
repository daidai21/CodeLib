package main

import (
	"fmt"
	"github.com/pkg/errors"
)

func A() error {
	return errors.New("NullPointerException")
}

func B() error {
	return A()
}
func C() error {
	return B()
}

func main() {
	fmt.Printf("Error: %+v", C())
}
