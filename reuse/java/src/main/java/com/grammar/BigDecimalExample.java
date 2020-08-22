package com.grammar;


import java.math.BigDecimal;
import java.math.RoundingMode;


public class BigDecimalExample {
    public static void main(String[] args) {
        BigDecimal d1 = new BigDecimal("123.456789");
        BigDecimal d2 = d1.setScale(4, RoundingMode.HALF_UP);
        BigDecimal d3 = d1.setScale(4, RoundingMode.DOWN);
        System.out.println(d2);
        System.out.println(d3);
    }
}
