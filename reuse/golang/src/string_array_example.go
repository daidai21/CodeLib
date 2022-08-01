package main

import "fmt"

func main() {
	ss := make([]string, 0)
	fmt.Println(ss)
	ss = append(ss, "a")
	ss = append(ss, "")
	ss = append(ss, "c")
	fmt.Println(ss)
	fmt.Println(len(ss))
}
