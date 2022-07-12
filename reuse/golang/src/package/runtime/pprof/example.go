package main

import (
	"fmt"
	"os"
	"runtime/pprof"
)

func main() {
	//CPU Profile
	f, err := os.Create("./cpuprofile")
	if err != nil {
		fmt.Println(err)
		return
	}
	defer f.Close()
	pprof.StartCPUProfile(f)
	defer pprof.StopCPUProfile()

	//Memory Profile
	fm, err := os.Create("./memoryprofile")
	if err != nil {
		fmt.Println(err)
		return
	}
	defer fm.Close()
	pprof.WriteHeapProfile(fm)

	for i := 0; i < 100; i++ {
		fmt.Println("程序员麻辣烫")
	}
}
