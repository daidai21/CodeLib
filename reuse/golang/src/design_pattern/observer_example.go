package main

import "fmt"

type Event struct {
	Data int
}

type Observer interface {
	OnNotify(event Event)
}

type observer struct {
	id int
}

func (o *observer) OnNotify(e Event) {
	fmt.Printf("observer %d recived event %d\n", o.id, e.Data)
}

type Notifier interface {
	Register(observer Observer)
	UnRegister(observer Observer)
	Notify(event Event)
}

type notifier struct {
	observers map[Observer]struct{}
}

func (n *notifier) Register(o Observer) {
	n.observers[o] = struct{}{}
}

func (n *notifier) UnRegister(o Observer) {
	delete(n.observers, o)
}

func (n *notifier) Notify(e Event) {
	for o := range n.observers {
		o.OnNotify(e)
	}
}

func main() {
	n := notifier{
		observers: map[Observer]struct{}{},
	}
	n.Register(&observer{1})
	n.Register(&observer{2})

	n.Notify(Event{1})
	n.Notify(Event{101})
	n.Notify(Event{9999})
}
