package main

import "fmt"

func main() {
	b1 := BaseReq{
		ShopID: "123",
	}
	fmt.Println(fnPrint(b1))
	//fmt.Println(fnPrint(*b1))
	fmt.Println(fnPrint(&b1))

	b2 := &BaseReq{
		ShopID: "123",
	}
	fmt.Println(fnPrint(b2))
	//fmt.Println(fnPrint(*b1))
	fmt.Println(fnPrint(&b2))

	fmt.Println("=====")
	fmt.Printf("%v\n", b1)
	fmt.Printf("%+v\n", b1)
	fmt.Printf("%#v\n", b1)
	fmt.Printf("%T\n", b1)
}

func fnPrint(s interface{}) string {
	return fmt.Sprintf("%+v", s)
}

type BaseReq struct {
	ShopID string `thrift:"shop_id,1,required" json:"shop_id"`
	Base   *Base  `thrift:"Base,255" json:"Base,omitempty"`
}

type Base struct {
	LogID  string            `thrift:"LogID,1" json:"LogID"`
	Caller string            `thrift:"Caller,2" json:"Caller"`
	Addr   string            `thrift:"Addr,3" json:"Addr"`
	Client string            `thrift:"Client,4" json:"Client"`
	Extra  map[string]string `thrift:"Extra,6" json:"Extra,omitempty"`
}
