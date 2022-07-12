package main

// ref  https://mp.weixin.qq.com/s?__biz=MzUzNzAzMTc3MA==&mid=2247484210&idx=1&sn=efd134cb9aed86b718b094a0aecff22a&scene=21#wechat_redirect

import "sync"

type Single struct {
	// ...
}

var (
	once   sync.Once
	single *Single
)

// GetSingle instance
func GetSingle() *Single {
	once.Do(func() {
		single = &Single{}
	})
	return single
}
