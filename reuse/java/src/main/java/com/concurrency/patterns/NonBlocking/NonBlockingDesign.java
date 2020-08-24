// package com.concurrency.patterns.NonBlocking;


import java.util.concurrent.atomic.AtomicReference;


public class NonBlockingDesign {
    private AtomicReference<Object> value = new AtomicReference<>(new Object());

    public void modifyValue() {
        Object updatedValue;
        Object old;
        do {
            old = this.value.get();
            updatedValue = new Object();
        } while (!value.compareAndSet(old, updatedValue));
    }

    public Object getValue() {
        return this.value.get();
    }

    public Object newObject() {
        return new Object();
    }
}
