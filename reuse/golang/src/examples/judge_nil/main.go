package main

// TODO

import (
	"fmt"
	"go/types"
)

func main() {
	var a int64
	fmt.Println(check.IsNil(a))
	fmt.Println(types.IsNil(a))

}
