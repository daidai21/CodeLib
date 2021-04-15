// 包名
// 文件名与包名没有直接关系，不一定要将文件名与包名定成同一个。
// 文件夹名与包名没有直接关系，并非需要一致。
// 同一个文件夹下的文件只能有一个包名，否则编译报错。
package main

import "fmt"

func main() {
	fmt.Println("Hello, World!")
}

// 当标识符（包括常量、变量、类型、函数名、结构字段等等）以一个大写字母开头，那么使用这种形式的标识符的对象就可以被外部包的代码所使用，这被称为导出（像面向对象语言中的 public）；
// 标识符如果以小写字母开头，则对包外是不可见的，但是他们在整个包的内部是可见并且可用的（像面向对象语言中的 protected ）。

// 一个标识符实际上就是一个或是多个字母(A~Z和a~z)数字(0~9)、下划线_组成的序列，但是第一个字符必须是字母或下划线而不能是数字。