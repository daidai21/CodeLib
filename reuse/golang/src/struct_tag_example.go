package main

import (
	"encoding/json"
	"fmt"
	"strings"
)

type People struct {
	Id       int
	UserName string
}

type PeopleTag struct {
	Id       int    `json:"id"`
	UserName string `json:"user_name"`
}

func main() {
	//实例化结构体
	p := People{1, "tom"}
	// 把p1结构体给转换成json
	ps, err := json.Marshal(p)
	if err != nil {
		fmt.Println(err)
	}
	//打印转换成json之后的结构体
	fmt.Println(string(ps))

	fmt.Println(strings.Repeat("=", 10))

	p2 := PeopleTag{2, "tom"}
	ps2, err := json.Marshal(p2)
	if err != nil {
		fmt.Println(err)
	}
	//打印转换成json之后的结构体
	fmt.Println(string(ps2))

}
