package main

import "fmt"


// make([]int64, 0) 和 nil 区别
// [Correct way to initialize empty slice](https://stackoverflow.com/questions/29164375/correct-way-to-initialize-empty-slice)

func main() {
	var nilSlice []int
	var emptySlice1 = []int{}
	var emptySlice2 = make([]int, 0) // 返回值
	var emptySlice3 = new([]int) // 返回指针

	fmt.Println("name | ==nil | len | cap")
	fmt.Println("nilSlice", nilSlice==nil, len(nilSlice), cap(nilSlice))
	fmt.Println("emptySlice1", emptySlice1==nil, len(emptySlice1), cap(emptySlice1))
	fmt.Println("emptySlice2", emptySlice2==nil, len(emptySlice2), cap(emptySlice2))
	fmt.Println("emptySlice3", emptySlice3==nil, len(*emptySlice3), cap(*emptySlice3))
}
