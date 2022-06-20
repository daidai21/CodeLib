package main

import (
	"fmt"
	"gorm.io/driver/sqlite"
	"gorm.io/gorm"
)

type BaseModel struct {
	gorm.Model
}

func main() {
	db, err := gorm.Open(sqlite.Open("test.db"), &gorm.Config{})
	fmt.Println(err)

	if err != nil {
		panic(err)
	}
	fmt.Println(db)

	var e error
	e = db.AutoMigrate(&BaseModel{})
	if e != nil {
		fmt.Println(e.Error())
	}

	e = db.Create(&BaseModel{}).Error
	if e != nil {
		fmt.Println(e.Error())
	}

}
