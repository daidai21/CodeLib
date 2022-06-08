package main

// https://stackoverflow.com/questions/54926712/is-there-a-way-to-list-keys-in-context-context

import (
	"context"
	"fmt"
	"reflect"
	"unsafe"
)

func printContextInternals(ctx interface{}, inner bool) {
	contextValues := reflect.ValueOf(ctx).Elem()
	contextKeys := reflect.TypeOf(ctx).Elem()

	if !inner {
		fmt.Printf("\nFields for %s.%s\n", contextKeys.PkgPath(), contextKeys.Name())
	}

	if contextKeys.Kind() == reflect.Struct {
		for i := 0; i < contextValues.NumField(); i++ {
			reflectValue := contextValues.Field(i)
			reflectValue = reflect.NewAt(reflectValue.Type(), unsafe.Pointer(reflectValue.UnsafeAddr())).Elem()

			reflectField := contextKeys.Field(i)

			if reflectField.Name == "Context" {
				printContextInternals(reflectValue.Interface(), true)
			} else {
				fmt.Printf("field name: %+v\n", reflectField.Name)
				fmt.Printf("value: %+v\n", reflectValue.Interface())
			}
		}
	} else {
		fmt.Printf("context is empty (int)\n")
	}
}

func main() {
	ctx := context.Background()
	ctx = context.WithValue(ctx, "k1", "v1")
	ctx = context.WithValue(ctx, "k2", "v2")
	ctx = context.WithValue(ctx, "k3", "v3")
	ctx = context.WithValue(ctx, "k4", "v4")
	printContextInternals(ctx, false)
}
