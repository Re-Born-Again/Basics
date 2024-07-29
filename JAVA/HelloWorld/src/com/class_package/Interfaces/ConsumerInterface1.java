package com.class_package.Interfaces;

import java.util.List;

// Interface Consumer<T>
// argument(s) : T
// return : -
// .andThen(), .apply()

public class ConsumerInterface1 {
    public static void main(String[] args){
        List<Integer> l = List.of(1,2,3,4);

        // Imperative programming like for, if/else, while
        for(var item : l)
            System.out.println(item);

        // Declarative programming
        l.forEach((item)-> System.out.println(item));

        // Consumer,Supplier,Function,Predicate interfaces has specializations for primitive values to prevent auto-boxing and un-boxing
    }
}