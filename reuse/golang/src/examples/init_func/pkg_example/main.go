package main

import (
	"fmt"

	"github.com/daidai21/CodeLib/reuse/golang/src/examples/init_func/pkg_example/pkg1"
)

func init() {
	fmt.Println("main.init()")
}

func main() {
	fmt.Println("main.main() start")
	pkg1.Foo()
	fmt.Println("main.main() end")

}
