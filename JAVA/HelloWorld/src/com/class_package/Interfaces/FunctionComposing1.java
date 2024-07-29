package com.class_package.Interfaces;

import java.util.function.Function;

public class FunctionComposing1 {
    public static void main(String[] args){
        Function<String,String> replaceSpace = (msg) -> {return msg.replace(" ","-");};
        Function<String,String> addBraces = (str) -> {return "{ "+str+" }";};

        // declarative programming
        var result = addBraces.andThen(replaceSpace).apply("Hello World");
        System.out.println("using .andThen() : "+result);

        // .compose() is opposite to .andThen() ie. reverse execution
        var result2 = addBraces.compose(replaceSpace).apply("Hello World");
        System.out.println("Using .compose() : "+result2);

        // Consumer,Supplier,Function,Predicate interfaces has specializations for primitive values to prevent auto-boxing and un-boxing
    }
}
