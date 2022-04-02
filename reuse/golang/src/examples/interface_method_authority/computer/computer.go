package computer

type Computer struct {
	a      int
	b      int
	Result int
}

func (c Computer) GetResult() int {
	c.exec()
	return c.Result
}

func (c *Computer) Init(a, b int) {
	c.a = a
	c.b = b
}

func (c *Computer) exec() {
	c.Result = c.a + c.b
}

// Add1 ///////////////////////////////////
func Add1(a, b int) int {
	return a + b
}
func add2(a, b int) int {
	return a + b
}
