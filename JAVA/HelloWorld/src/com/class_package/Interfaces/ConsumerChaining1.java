package com.class_package.Interfaces;

import java.util.List;
import java.util.function.Consumer;

public class ConsumerChaining1 {
    public static void main(String[] args){
        List<String> l = List.of("a","b","c");
        Consumer<String> print = (item) -> {System.out.println("print : "+item);};
        Consumer<String> printUpperCase = (item) -> {System.out.println("printUpperCase : "+item.toUpperCase());};

        l.forEach(print.andThen(printUpperCase.andThen(print)));

        // Consumer,Supplier,Function,Predicate interfaces has specializations for primitive values to prevent auto-boxing and un-boxing
    }
}
