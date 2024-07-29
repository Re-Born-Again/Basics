package com.class_package.Interfaces;

// Interface Predicate<T>
// argument(s) : T
// return : boolean
// .test(), .and(), .or(), .negate()

import java.util.function.Predicate;

public class PredicateInterface1 {
    public static void main(String[] args){
        Predicate<String> islongThan5 = (str) -> {return str.length() >5 ;};

        boolean result = islongThan5.test("hello");
        System.out.println(result);

        // Consumer,Supplier,Function,Predicate interfaces has specializations for primitive values to prevent auto-boxing and un-boxing
    }
}
