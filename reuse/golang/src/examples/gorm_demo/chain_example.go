package main

import "gorm.io/gorm"

type User struct {
	gorm.Model
	// ...
}

func ChainExample(db *gorm.DB) (ret []*User, err error) {

	tx := db.Where("name = ?", "jinzhu2")
	if tx.Error != nil {
		return ret, tx.Error
	}

	tx = tx.Where("age = ?", 20)
	if tx.Error != nil {
		return ret, tx.Error
	}

	tx = tx.Find(ret)
	if tx.Error != nil {
		return ret, tx.Error
	}

	return ret, nil
}
