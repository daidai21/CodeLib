package main

//
// 指针数组
//

import "fmt"

const MAX int = 3

func main() {
	a := []int{10, 100, 200}
	var i int
	for i = 0; i < MAX; i++ {
		fmt.Printf("a[%d] = %d\n", i, a[i])
	}

	a1 := []int{10, 100, 200}
	var i1 int
	var ptr1 [MAX]*int
	for i1 = 0; i1 < MAX; i1++ {
		ptr1[i1] = &a1[i1] /* 整数地址赋值给指针数组 */
	}
	for i1 = 0; i1 < MAX; i1++ {
		fmt.Printf("a1[%d] = %d\n", i1, *ptr1[i1])
	}
}
