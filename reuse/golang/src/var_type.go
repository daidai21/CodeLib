package main

import "fmt"

// VarTypeOfString FIXME: not enum all data type
func VarTypeOfString(val interface{}) (result string) {
	switch val.(type) {
	case int:
		result = "int"
	case bool:
		result = "bool"
	case string:
		result = "string"
	case byte:
		result = "byte"
	default:
		result = "unknown"
	}
	return
}

func main() {
	fmt.Println(VarTypeOfString(1))
	fmt.Println(VarTypeOfString("123"))
	fmt.Println(VarTypeOfString(nil))
}
