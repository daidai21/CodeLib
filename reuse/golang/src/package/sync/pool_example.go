package main

/**
Pool大小不固定，受GC影响
如果有Put过，优先Get到的是之前Put缓存的对象，否则就是New的新对象
*/
import (
	"fmt"
	"strings"
	"sync"
)

var pool *sync.Pool

type Person struct {
	Name string
}

func initPool() {
	pool = &sync.Pool{
		New: func() interface{} {
			fmt.Println("create a new person.")
			return new(Person)
		},
	}
}

func main() {
	initPool()
	p := pool.Get().(*Person)
	fmt.Println("首次从 pool 里获取：", p)

	p.Name = "first"
	fmt.Printf("设置 p.Name = %s\n", p.Name)

	pool.Put(p)

	fmt.Println("Pool 里已有一个对象：&{first}，调用 Get: ", pool.Get().(*Person))
	fmt.Println("Pool 没有对象了，调用 Get: ", pool.Get().(*Person))

	pool.Put(p)
	fmt.Println("归还")
	fmt.Println("借取", pool.Get().(*Person))

	fmt.Println(strings.Repeat("=", 10))

	p2 := pool.Get().(*Person)
	fmt.Printf("p addr %p \n", &p)
	fmt.Printf("p2 addr %p \n", &p2)

	fmt.Println(strings.Repeat("=", 10))

	ppool := &sync.Pool{
		New: func() interface{} {
			fmt.Println("create a new person.")
			return new(Person)
		},
	}
	pp1 := ppool.Get().(*Person)
	pp2 := ppool.Get().(*Person)
	pp3 := ppool.Get().(*Person)
	fmt.Printf("pp1 addr %p %s \n", &pp1, pp1)
	fmt.Printf("pp2 addr %p %s \n", &pp2, pp2)
	fmt.Printf("pp3 addr %p %s \n", &pp3, pp3)
	pp1.Name = "pp1"
	ppool.Put(pp1)
	pp4 := ppool.Get().(*Person)
	pp5 := ppool.Get().(*Person)
	fmt.Printf("pp4 addr %p %s \n", &pp4, pp4)
	fmt.Printf("pp5 addr %p %s \n", &pp5, pp5)

}
