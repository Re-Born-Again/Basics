package com.class_package.Interfaces;

import java.util.function.Predicate;

public class PredicateCombining1 {
    public static void main(String[] args){
        Predicate<String> hasA = (str) -> {return str.contains("A");};
        Predicate<String> hasB = (str) -> {return str.contains("B");};

        boolean result = hasA.and(hasB).test("ACE");
        System.out.println(result);

        boolean result2 = hasA.or(hasB).test("ACE");
        System.out.println(result2);

        boolean result3 = hasA.negate().test("ACE");
        System.out.println(result3);

        // Consumer,Supplier,Function,Predicate interfaces has specializations for primitive values to prevent auto-boxing and un-boxing
    }
}
