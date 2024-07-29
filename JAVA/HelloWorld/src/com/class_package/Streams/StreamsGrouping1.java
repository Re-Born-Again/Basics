package com.class_package.Streams;

import java.util.List;
import java.util.stream.Collectors;

// .groupingBy() // Function
// .groupingBy() // Function, Collector
// .mapping() // Function, Collector

public class StreamsGrouping1 {
    public static void main(String[] args){
        var movies = List.of(
                new DummyMovie("a",1),
                new DummyMovie("c",2),
                new DummyMovie("b",3),
                new DummyMovie("a",1)
        );

        var r1 = movies.stream()
                .collect(Collectors.groupingBy(m->m.getName()));
        System.out.println(r1);

        var r2 = movies.stream()
                .collect(Collectors.groupingBy(m->m.getName(),Collectors.toSet()));
        System.out.println(r2);

        var r3 = movies.stream()
                .collect(Collectors.groupingBy(m->m.getName(),Collectors.mapping(
                        m->m.getName(),Collectors.joining(", ")
                )));
        // can't give .joining() instead of .mapping() coz it works on stream of Strings not on stream of DummyMovie
        System.out.println(r3);
    }
}
