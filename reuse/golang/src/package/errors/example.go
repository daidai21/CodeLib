package main

import (
	"errors"
	"fmt"
	"os"
	"strings"
)

func main() {
	// errors.Is
	// 判断被包装的 error 是否是包含指定错误
	err1 := errors.New("new error")
	err2 := fmt.Errorf("err2: [%w]", err1)
	err3 := fmt.Errorf("err3: [%w]", err2)

	fmt.Println("errors.Is(err3, err2)  ", errors.Is(err3, err2))
	fmt.Println("errors.Is(err3, err1)  ", errors.Is(err3, err1))

	fmt.Println(err1.Error())
	fmt.Println(err2.Error())
	fmt.Println(err3.Error())

	fmt.Println(strings.Repeat("=", 10))

	// errors.As
	if _, err := os.Open("non-existing"); err != nil {
		var pathError *os.PathError
		if errors.As(err, &pathError) {
			fmt.Println("Failed at path: ", pathError.Path)
		} else {
			fmt.Println(err)
		}
	}
}
