package com.class_package.Interfaces;

import java.util.function.Function;

// Interface Function<T,R>
// argument(s) : T
// return : R
// .andThen() , .compose(), .apply()

public class FunctionInterface1 {
    public static void main(String[] args){
        Function<String,Integer> map = (str) -> str.length();
        var len = map.apply("abcd");
        System.out.println(len);

        // Consumer,Supplier,Function,Predicate interfaces has specializations for primitive values to prevent auto-boxing and un-boxing
    }
}
