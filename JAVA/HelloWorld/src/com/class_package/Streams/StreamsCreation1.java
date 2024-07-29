package com.class_package.Streams;

import java.util.Arrays;
import java.util.Collection;
import java.util.List;
import java.util.stream.Stream;

// creating streams -> 4 types

// .forEach() // Consumer
// .generate() // Supplier
// .iterate // Unary operator

public class StreamsCreation1 {
    public static void main(String[] args){
        // every Collection interface can return stream
        Collection<Integer> c = List.of(1,2,3);
        c.stream()
                .forEach((n)->{System.out.println(n);});

        List<String> l = List.of();
        l.stream();

        // for arrays use Arrays class
        int[] arr = {1,2,3};
        Arrays.stream(arr);

        // from arbitrary number of objects
        Stream.of(1,2,3)
                .forEach((n)->{System.out.println(n);});

        // finite & infinite streams
        var s = Stream.generate(()->Math.random());
        s
                .limit(2) // if not given, it produces infinite numbers
                .forEach(n-> System.out.println(n));

        Stream.iterate(1,(n)-> {return n+1;})
                .limit(3) // if not given, it produces infinite numbers
                .forEach(n-> System.out.println(n));
    }
}