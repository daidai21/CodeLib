package main

// `select {}` 阻塞 goroutine
// `for {}` 会将CPU运行到 100% ；  `select {}` 会将CPU运行到 0%
// https://stackoverflow.com/questions/48769062/whats-difference-between-select-and-for-in-golang
