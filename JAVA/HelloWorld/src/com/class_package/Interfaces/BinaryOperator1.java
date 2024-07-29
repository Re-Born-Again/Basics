package com.class_package.Interfaces;

import java.util.function.BinaryOperator;

// Interface BinaryOperator<T>
// extends super interface BiFunction<T,T,T>
// argument(s) : T , T
// return : T
// .apply()

public class BinaryOperator1 {
    public static void main(String[] args){
        BinaryOperator<Integer> add = (a,b) -> {return a+b;};
        BinaryOperator<Integer> mult = (a,b) -> {return a*b;};

        var result = add.apply(5,5);
        System.out.println(result);
        System.out.println(mult.apply(5,5));
    }
}
