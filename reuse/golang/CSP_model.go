package main


// 
// https://blog.csdn.net/tianmaxingkong_/article/details/104190969
// https://www.zhihu.com/question/26192499
// 


import "fmt"

var ch = make(chan string)

func message(){
    msg := <- ch
    fmt.Println(msg)    
}

func main(){
    go message()
    ch <- "Hello,CSP."
}
