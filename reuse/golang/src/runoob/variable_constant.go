package main

// 变量和常量

import (
	"fmt"
	"unsafe"
)

// ***** 变量 *****
var i1, i2 int
var ( // 这种因式分解关键字的写法一般用于声明全局变量
	j1 int
	j2 bool
)
var k1, k2 int = 1, 2
var s1, s2 = 123, "hello"

// ***** 常量 *****
// 常量还可以用作枚举
const (
	Unknown = 0
	Female  = 1
	Male    = 2
)

const (
	ca = "abc"
	cb = len(ca)
	cc = unsafe.Sizeof(ca)
)

func main() {
	// ***** 变量 *****
	var a string = "Runoob"
	fmt.Println(a)

	var b, c int = 1, 2
	fmt.Println(b, c)

	// 声明一个变量并初始化
	var d = "RUNOOB"
	fmt.Println(d)

	// 没有初始化就为零值
	var e int
	fmt.Println(e)

	// bool 零值为 false
	var f bool
	fmt.Println(f)

	var i int
	var g float64
	var h bool
	var s string
	fmt.Printf("%v %v %v %q\n", i, g, h, s)

	// ":="  是一个声明语句
	// 这种不带声明格式的只能在函数体中出现
	k := "Runoob" // var f string = "Runoob"
	fmt.Println(k)

	fmt.Println(i1, i2, j1, j2, k1, k2, s1, s2)

	// _,numb,strs := numbers() //只获取函数返回值的后两个

	// 值类型和引用类型
	// TODO

	// ***** 常量 *****
	const LENGTH int = 10
	const WIDTH int = 5
	var area int
	const a3, b3, c3 = 1, false, "str" //多重赋值

	area = LENGTH * WIDTH
	fmt.Printf("面积为 : %d", area)
	println()
	println(a3, b3, c3)

	// 常量可以用len(), cap(), unsafe.Sizeof()函数计算表达式的值。常量表达式中，函数必须是内置函数，否则编译不过
	println(ca, cb, cc)

	// iota，特殊常量，可以认为是一个可以被编译器修改的常量。
	const (
		iota_a = iota //0
		iota_b        //1
		iota_c        //2
		iota_d = "ha" //独立值，iota += 1
		iota_e        //"ha"   iota += 1
		iota_f = 100  //iota +=1
		iota_g        //100  iota +=1
		iota_h = iota //7,恢复计数
		iota_i        //8
	)
	println(iota_a, iota_b, iota_c, iota_d, iota_e, iota_f, iota_g, iota_h, iota_i)

	const (
		iota_i1 = 1 << iota
		iota_j1 = 3 << iota
		iota_k1
		iota_l1
	)
	fmt.Println("iota_i1=", iota_i1)
	fmt.Println("iota_j1=", iota_j1)
	fmt.Println("iota_k1=", iota_k1)
	fmt.Println("iota_l1=", iota_l1)
}
