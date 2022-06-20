package main

import "gorm.io/gorm"

type Person struct {
	// ...
}

type Cat struct {
	// ...
}

func TransactionExample(db *gorm.DB) error {
	return db.Transaction(func(tx *gorm.DB) error {
		if err := tx.Create(&Person{}).Error; err != nil {
			return err
		}

		if err := tx.Create(&Cat{}).Error; err != nil {
			return err
		}

		// commit
		return nil
	})
}
