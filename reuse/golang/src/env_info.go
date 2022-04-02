package main

// 获取系统相关硬件、软件、运行时环境的信息库
// https://github.com/shirou/gopsutil

import (
	"fmt"
	"os"
	"runtime"
)

func main() {
	// 硬件
	fmt.Println("CPU核心数： ", runtime.NumCPU())

	// 系统
	fmt.Println("操作系统名称： ", runtime.GOOS)
	fmt.Println("操作系统架构： ", runtime.GOARCH)

	// CPU使用率
	// 内存使用率
	// 磁盘使用率

	// env
	if hostname, err := os.Hostname(); err == nil {
		fmt.Println("hostname: ", hostname)
	} else {
		fmt.Println("hostname: ", "get failed")
	}

}
