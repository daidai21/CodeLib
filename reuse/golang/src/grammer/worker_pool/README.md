
// TODO
// https://leileiluoluo.com/posts/golang-worker-pool.html
// https://learnku.com/docs/gobyexample/2020/work-pool-worker/6285
// https://github.com/xxjwxc/gowp
// https://brandur.org/go-worker-pool
// https://github.com/gammazero/workerpool
// https://github.com/alitto/pond
// https://github.com/ivpusic/grpool

https://github.com/panjf2000/ants

===

https://github.com/bytedance/gopkg/blob/develop/util/gopool/README.md

workerPool 类似就是协程池； taskPool就是提交的任务池，这里是用的链表保存的

taskPool 包含多个 task （执行的函数和上下问）
workerPool 包含多个 worker 对应 pool
poolMap 包含多个 pool
