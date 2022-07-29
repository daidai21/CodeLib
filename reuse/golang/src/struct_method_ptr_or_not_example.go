package main

import "fmt"

func main() {
	var c1 Circle
	fmt.Println(c1)
	c1.changeRadiusVal(1)
	fmt.Println(c1)
	c1.changeRadiusRef(1)
	fmt.Println(c1)

}

type Circle struct {
	Radius float64
}

func (c Circle) changeRadiusVal(radius float64) {
	c.Radius = radius
}

func (c *Circle) changeRadiusRef(radius float64) {
	c.Radius = radius
}
