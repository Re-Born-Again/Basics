package com.class_package;
/*
* Wildcards are used for flexibility in method parameters and return types.

    <?>: Any type.
    <? extends T>: Any subtype of T.
    <? super T>: Any supertype of T.

* Type Parameters are used for defining specific types for classes, interfaces, and methods.

    <T>: A specific type used throughout the class or method for strong type safety.

*/

import java.util.Arrays;
import java.util.List;

public class Generics2 {
    public static void main(String[] args){

        List<Integer> li = Arrays.asList(1, 2, 3);
        List<String>  ls = Arrays.asList("one", "two", "three");

        typePrint(li);
        typePrint(ls);

        wildcardPrint(li);
        wildcardPrint(ls);

    }

    public static <T> void typePrint(List<T> list) {
        for (T elem: list)
            System.out.print(elem + " ");
        System.out.println();
    }

    public static void wildcardPrint(List<?> list) {
        for (Object elem: list)
            System.out.print(elem + " ");
        System.out.println();
    }
}
