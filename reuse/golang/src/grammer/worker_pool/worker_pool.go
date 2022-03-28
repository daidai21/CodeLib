package worker_pool

type WorkerPoolTypeEnum int

const (
	IO WorkerPoolTypeEnum = iota + 1
	CPU
)

type TaskHandler func() error

type WorkerPool struct {
	// TODO
}

func NewWorkerPool(max int) *WorkerPool {
	// TODO
}

func (wp WorkerPool) Submit(handler TaskHandler) {
	// TODO
}

func (wp WorkerPool) SubmitAndGet(handler TaskHandler) {
	// TODO
}
