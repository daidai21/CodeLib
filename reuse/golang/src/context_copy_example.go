package main

import (
	"context"
	"fmt"
	"sync"
	"time"
)

// context都是值传递

var wg sync.WaitGroup

func main() {
	wg.Add(1)
	ctx := context.TODO()
	fmt.Printf("addr ctx %v\n", &ctx)

	go foo(ctx)
	time.Sleep(10 * time.Millisecond)
	ctx1 := context.WithValue(ctx, "a", "b")

	fmt.Printf("addr ctx %v\n", &ctx)
	fmt.Printf("ctx %v\n", ctx)

	fmt.Printf("addr ctx1 %v\n", &ctx1)
	fmt.Printf("ctx1 = %v\n", ctx1)

	wg.Wait()
}

func foo(ctx context.Context) {
	fmt.Printf("foo() addr %v\n", &ctx)
	fmt.Printf("foo() %v\n", ctx)
	time.Sleep(50 * time.Millisecond)
	fmt.Printf("foo() addr %v\n", &ctx)
	fmt.Printf("foo() %v\n", ctx)
	wg.Done()
}
