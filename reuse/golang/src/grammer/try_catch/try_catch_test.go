package try_catch

import (
	"testing"
	"try_catch"
)

func Test_example(t *testing.T) {
	try_catch.This(func() {
		panic("my panic")
	}).Finally(func() {
		t.Log("this must be printed after the catch")
	}).Catch(func(e try_catch.E) {
		// Print crash
		t.Log(e)
	})

	var obj interface{}
	obj = 2
	try_catch.This(func() {
		// this operation will panic because obj is an integer
		text := obj.(string)
		t.Log(text)
	}).Catch(func(e try_catch.E) {
		// Print crash
		t.Log(e)
	})

	try_catch.This(func() {
		panic("my panic")
	}).Finally(func() {
		t.Log("this must be printed after the catch")
	}).Catch(func(_ try_catch.E) {
		t.Log("exception catched") // print
		// try_catch.Throw()          // rethrow current exception!!
	})

	try_catch.This(func() {
		try_catch.This(func() {
			panic("my panic")
		}).Catch(func(e try_catch.E) {
			t.Log("fixing stuff") // print
			try_catch.Throw()     // rethrow current exception!!
		})
	}).Catch(func(e try_catch.E) {
		// print
		t.Log(e)
	})
	t.Log("hey")
}
