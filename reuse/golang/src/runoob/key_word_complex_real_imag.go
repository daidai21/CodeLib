package main

import "fmt"

func main() {
	var x complex128 = complex(1, 2) // 1+2i

	fmt.Println(x)
	fmt.Println(real(x))
	fmt.Println(imag(x))
}
