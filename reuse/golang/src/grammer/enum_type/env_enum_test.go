package enum_type

import (
	"fmt"
	"testing"
)

func TestEnvEnum(t *testing.T) {
	//
	var cur EnvEnum
	fmt.Println(cur)
	cur = Pro
	fmt.Println(cur)
	//
	var cur2 EnvEnum = Pre
	fmt.Println(cur2)
	// 错误的
	cur3 := Pro
	fmt.Println(cur3)
	//
	cur4 := NewEnvEnum(3)
	fmt.Println(cur4)
}
