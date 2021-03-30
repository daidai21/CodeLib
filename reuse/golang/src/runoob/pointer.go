package main

import "fmt"

func main() {
	var a int = 10
	fmt.Printf("变量的地址: %x\n", &a)

	var ip *int     /* 指向整型*/
	var fp *float32 /* 指向浮点型 */

	ip = &a /* 指针变量的存储地址 */
	fmt.Printf("a 变量的地址是: %x\n", &a)
	/* 指针变量的存储地址 */
	fmt.Printf("ip 变量储存的指针地址: %x\n", ip)
	/* 使用指针访问值 */
	fmt.Printf("*ip 变量的值: %d\n", *ip)

	fmt.Printf("fp 的值为 : %x\n", fp)

}
