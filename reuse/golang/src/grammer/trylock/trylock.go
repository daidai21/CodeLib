package main

import (
	"fmt"
	"sync"
	"sync/atomic"
	"unsafe"
)

const mutexLocked = 1 << iota

type Mutex struct {
	sync.Mutex
}

func (m *Mutex) TryLock() bool {
	fmt.Println("  ", unsafe.Pointer(&m.Mutex))
	return atomic.CompareAndSwapInt32((*int32)(unsafe.Pointer(&m.Mutex)), 0, mutexLocked)
}

func TryLockByUnsafe(m *sync.Mutex) bool {
	const mutexLocked = 1 << iota
	//fmt.Println("  ", unsafe.Pointer(&m))
	//fmt.Println("    ", &m)
	//fmt.Println("      ", (*int32)(unsafe.Pointer(&m)))
	//fmt.Println("        ", m)
	//fmt.Printf("  %p\n", m)

	return atomic.CompareAndSwapInt32((*int32)(unsafe.Pointer(m)), 0, mutexLocked)
}

func main() {
	var m sync.Mutex = sync.Mutex{}
	//fmt.Printf("&m  %p\n", &m)
	fmt.Println(TryLockByUnsafe(&m))
	//fmt.Printf("&m  %p\n", &m)
	fmt.Println(TryLockByUnsafe(&m))
	//fmt.Printf("&m  %p\n", &m)
	//fmt.Println(TryLockByUnsafe(&m))

	m.Unlock()
	fmt.Println(TryLockByUnsafe(&m))

	fmt.Println("===========")
	var m2 Mutex
	fmt.Println(m2.TryLock())
	fmt.Println(m2.TryLock())
}
