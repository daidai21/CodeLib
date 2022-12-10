package main

// ref
// https://www.jianshu.com/p/30638336cf0a

import (
	"fmt"
	"time"
)

// EventHandler 事件处理器
type EventHandler func(event Event) //声明函数回调

//EventListener 事件监听器
type EventListener struct {
	Handler EventHandler //事件处理器
}

//NewEventListener 创建事件监听器
func NewEventListener(handler EventHandler) *EventListener {
	listener := new(EventListener)
	listener.Handler = handler
	return listener
}

//IEventDispatcher 事件调度接口
type IEventDispatcher interface {
	AddListener(eventType string, listener *EventListener)         //添加事件监听
	RemoveListener(eventType string, listener *EventListener) bool //移除事件监听
	HasListener(eventType string) bool                             //是否包含事件
	DispatchEvent(event Event) bool                                //事件派发
}

//Event 事件类型基类
type Event struct {
	Type   string           //事件类型
	Target IEventDispatcher //事件触发器实例
	Data   interface{}      //事件携带数据源
}

//Clone 克隆事件
func (e *Event) Clone() *Event {
	evt := new(Event)
	evt.Type = e.Type
	evt.Target = e.Target
	return evt
}

//ToString 打印输出
func (e *Event) ToString() string {
	return fmt.Sprintf("Event Type %v", e.Type)
}

//NewEvent 创建事件
func NewEvent(eventType string, data interface{}) Event {
	return Event{Type: eventType, Data: data}
}

//EventSaver 事件调度器中存放的单元
type EventSaver struct {
	Type      string
	Listeners []*EventListener
}

//EventDispatcher 事件调度器/事件分发器
type EventDispatcher struct {
	Savers []*EventSaver
}

//AddListener 事件调度器 添加监听
func (ed *EventDispatcher) AddListener(eventType string, listener *EventListener) {
	//循环遍历判断是否存在
	for _, saver := range ed.Savers {
		if saver.Type == eventType {
			saver.Listeners = append(saver.Listeners, listener)
			return
		}
	}
	saver := &EventSaver{Type: eventType, Listeners: []*EventListener{listener}}
	ed.Savers = append(ed.Savers, saver)
}

//RemoveListener 事件调度器 移除监听
func (ed *EventDispatcher) RemoveListener(eventType string, listener *EventListener) bool {
	for _, saver := range ed.Savers {
		saverType := saver.Type
		if saverType != eventType {
			continue
		}
		saverListeners := saver.Listeners
		for index, item := range saverListeners {
			if item != listener {
				continue
			}
			saver.Listeners = append(saverListeners[:index], saverListeners[index+1:]...)
			return true
		}
	}
	return false
}

//HasListener 事件调度器 是否存在某类监听
func (ed *EventDispatcher) HasListener(eventType string) bool {
	for _, saver := range ed.Savers {
		if saver.Type == eventType {
			return true
		}
	}
	return false
}

// DispatchEvent 事件调度器 事件派发
func (ed *EventDispatcher) DispatchEvent(event Event) bool {
	for _, saver := range ed.Savers {
		if saver.Type == event.Type {
			for _, listener := range saver.Listeners {
				event.Target = ed
				listener.Handler(event)
			}
			return true
		}
	}
	return false
}

//NewEventDispatcher 创建事件调度器
func NewEventDispatcher() *EventDispatcher {
	return new(EventDispatcher)
}

//EventTest 测试事件
const EventTest = "event_test"

//test 事件处理函数
func test(event Event) {
	fmt.Println(event.ToString())
}
func main() {
	event := NewEvent(EventTest, nil)
	dispatcher := NewEventDispatcher()
	listener := NewEventListener(test)
	dispatcher.AddListener(EventTest, listener)
	time.Sleep(time.Second * time.Duration(2))
	dispatcher.DispatchEvent(event)
}
