package main

// ref
// https://juejin.cn/post/6844904052749238280
import (
	"fmt"
	"time"
)

var CacheMap = make(map[string]Cache)

type Cache struct {
	Value      string
	ExpireTime time.Time
}

func WithCache(cacheKey string, expireTime int64, fn func() (string, error)) (string, error) {
	if value, ok := CacheMap[cacheKey]; ok {
		if value.ExpireTime.After(time.Now()) {
			fmt.Println("get from cache")
			return value.Value, nil
		}
	}
	value, err := fn()
	if err != nil {
		return "", err
	}
	//此处应该加锁
	CacheMap[cacheKey] = Cache{
		Value:      value,
		ExpireTime: time.Now().Add(time.Duration(expireTime) * time.Second),
	}
	return value, nil
}

func queryDbData(param string) (string, error) {
	return WithCache(param, 4, func() (s string, err error) {
		fmt.Println("get from db")
		CacheMap["abc"] = Cache{
			Value:      "123",
			ExpireTime: time.Now().Add(10 * time.Second),
		}
		return "123", nil
	})

}

func main() {
	data, _ := queryDbData("abc")
	fmt.Println(data)
	data, _ = queryDbData("abc")
	fmt.Println(data)
}
