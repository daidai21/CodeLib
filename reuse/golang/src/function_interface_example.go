package main

// 接口型函数

import "fmt"

type Handler interface {
	Do(k, v interface{})
}

type HandlerFunc func(k, v interface{})

func (f HandlerFunc) Do(k, v interface{}) {
	f(k, v)
}

// Each
// Map的遍历接口
func Each(m map[interface{}]interface{}, h Handler) {
	if m != nil && len(m) > 0 {
		for k, v := range m {
			h.Do(k, v)
		}
	}
}

func EachFunc(m map[interface{}]interface{}, f func(k, v interface{})) {
	Each(m, HandlerFunc(f))
}

// ====================  业务使用 ====================

func selfInfo(k, v interface{}) {
	fmt.Printf("大家好,我叫%s,今年%d岁\n", k, v)
}

type welcome string

func (w welcome) selfInfo(k, v interface{}) {
	fmt.Printf("%s,我叫%s,今年%d岁\n", w, k, v)
}

func main() {
	persons := make(map[interface{}]interface{})
	persons["张三"] = 20
	persons["李四"] = 23
	persons["王五"] = 26

	EachFunc(persons, selfInfo)
	fmt.Println("=====")
	Each(persons, HandlerFunc(selfInfo))
	fmt.Println("=====")
	var w welcome = "大家好"
	EachFunc(persons, w.selfInfo)
}
