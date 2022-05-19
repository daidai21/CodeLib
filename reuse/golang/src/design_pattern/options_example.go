package main

/**
 * ref
 * https://levelup.gitconnected.com/options-pattern-in-golang-9a0384a9d8db
 */
import (
	"fmt"
	"time"
)

type Server struct {
	name          string
	port          uint32
	maxConnection uint32
	timeout       time.Duration
}

func (s *Server) ToString() string {
	return fmt.Sprintf("name=%s, port=%d, maxConnection=%d, timeout=%v", s.name, s.port, s.maxConnection, s.timeout)
}

type Option func(s *Server)

func WithPort(port uint32) Option {
	return func(s *Server) {
		s.port = port
	}
}

func WithMaxConnection(maxConnection uint32) Option {
	return func(s *Server) {
		s.maxConnection = maxConnection
	}
}

func WithTimeout(timeout time.Duration) Option {
	return func(s *Server) {
		s.timeout = timeout
	}
}

func NewServer(name string, options ...Option) *Server {
	server := &Server{
		name: name,
	}

	for _, option := range options {
		option(server)
	}

	return server
}

func main() {
	s1 := NewServer("s1",
		WithPort(123),
		WithMaxConnection(5),
		WithTimeout(100),
	)
	fmt.Println(s1.ToString())
}
