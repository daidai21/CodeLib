package main

//
// 数组
//

import "fmt"

func main() {
	// 声明数组
	// var variable_name [SIZE] variable_type
	var balance [10]float32
	fmt.Println(balance)

	var balance1 = [5]float32{1000.0, 2.0, 3.4, 7.0, 50.0}
	balance2 := [5]float32{1000.0, 2.0, 3.4, 7.0, 50.0}
	fmt.Println(balance1)
	fmt.Println(balance2)

	// 如果数组长度不确定，可以使用 ... 代替数组的长度，编译器会根据元素个数自行推断数组的长度：
	var balance3 = [...]float32{1000.0, 2.0, 3.4, 7.0, 50.0}
	balance4 := [...]float32{1000.0, 2.0, 3.4, 7.0, 50.0}
	fmt.Println(balance3)
	fmt.Println(balance4)

	//  将索引为 1 和 3 的元素初始化
	balance5 := [5]float32{1: 2.0, 3: 7.0}
	balance5[4] = 50.0
	fmt.Println(balance5)

	// 访问数组元素
	var salary float32 = balance[9]
	fmt.Println(salary)

	var n [10]int /* n 是一个长度为 10 的数组 */
	var i, j int
	/* 为数组 n 初始化元素 */
	for i = 0; i < 10; i++ {
		n[i] = i + 100 /* 设置元素为 i + 100 */
	}
	/* 输出每个数组元素的值 */
	for j = 0; j < 10; j++ {
		fmt.Printf("Element[%d] = %d\n", j, n[j])
	}
}
