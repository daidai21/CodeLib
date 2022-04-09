package main

import "fmt"

/**
GO 协程池 - Goroutine复用、限制数量

1. p.work时无缓冲，所以第一次调用Schedule时case p.work <- task: 由于没有协成读work，就不会写入，就为false，
2. p.sem因为有缓冲区，不需要有读协成读就可以写入，所以会执行case p.sem <- struct{}{}，往sem写入一个空对象，接着通过go p.workder(task)开启一个协成处理task。
3. task处理结束后，协成不销毁，会停在task = <-p.work等待接收p.work里的任务
2. 第二次调用Schedule,如果第一次创建的协成等待接收新的task（task = <-p.work），就会执行case p.work <- task，往work的channel写数据，协成就能从p.work取到（task = <-p.work）task执行，不会开启新的协成。
3. 如果task执行时间比较久，第二次调用Schedule时，task()还未执行完，也就是还未执行到task = <-p.work，那么case p.work <- task将无法写入，当p.sem缓冲区没满（还未达到限制size）就会执行case p.sem <- struct{}{}，开启新的协成执行task.
4. 当p.sem缓冲区满了，也就是说达到限制的最大数时，Schedule将会pending，直到某个协成执行到task = <-p.work接收任务
5. defer func() { <-p.sem }()是用在回收，在一些情况下，希望协成销毁，就可以跳出for循环，sem读出数据，也就是线程数数-1
*/

var OpenDebug bool

type Pool interface {
	Go(task func()) error
}

type pool struct {
	work chan func()
	sem  chan struct{} // 计数，限制协成数
}

func New(size int) Pool {
	return &pool{
		work: make(chan func()),
		sem:  make(chan struct{}, size),
	}
}

func (p *pool) Go(task func()) error {
	select {
	case p.work <- task:
		if OpenDebug {
			fmt.Println("Go()  p.work <- task")
		}
	case p.sem <- struct{}{}:
		if OpenDebug {
			fmt.Println("Go()  p.sem <- struct{}{}")
		}
		go p.worker(task)
	}
	return nil
}

func (p *pool) worker(task func()) {
	defer func() { <-p.sem }()
	for {
		task()
		task = <-p.work
	}
}
