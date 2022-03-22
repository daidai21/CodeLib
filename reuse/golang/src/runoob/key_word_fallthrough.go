package main

import "fmt"

func main() {
	switch {
	case true:
		fmt.Println("The integer was <= 5")
		fallthrough
	case false:
		fmt.Println("The integer was <= 6")
		fallthrough
	default:
		fmt.Println("default case")
	}
}
