package main

import (
	"fmt"
	"testing"
	"time"
)

func TestEnvEnum(t *testing.T) {
	OpenDebug = true
	p := New(2)

	for i := 0; i < 1000; i += 1 {
		p.Go(func() {
			time.Sleep(10 * time.Microsecond)
			fmt.Println("task run ...")
		})
	}

	fmt.Println("===== All task run done =====")
}
