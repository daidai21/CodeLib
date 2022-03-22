package main

import "fmt"

type Person struct {
	id   int
	name string
}

func main() {
	p := Person{id: 1, name: "tom"}
	fmt.Println(p)
	fmt.Printf("%p\n", &p)

	modifyByVal(p, 2, "jerry")
	fmt.Println(p)

	modifyByRef(&p, 2, "jerry")
	fmt.Println(p)
}

func modifyByVal(person Person, id int, name string) {
	fmt.Printf("%p\n", &person)
	person.id = id
	person.name = name
}

func modifyByRef(person *Person, id int, name string) {
	fmt.Printf("%p\n", person)
	person.id = id
	person.name = name
}
