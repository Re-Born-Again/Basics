package com.class_package.Streams;

import java.util.Collection;
import java.util.List;
import java.util.function.Function;
import java.util.stream.Collectors;

// .collect() // Supplier // Consumer // Collectors
// .toSet() // no parameter
// .toMap() // Function, Function
// .summingInt() // ToIntFunction // similar for .summingLong(), .summingDouble()
// .summarizingInt() // ToIntFunction // similar for .summarizingLong(), .summarizingDouble()
// .joining() // String (delimiter)

public class StreamsCollectors1 {
    public static void main(String[] args){
        var movies = List.of(
                new DummyMovie("a",1),
                new DummyMovie("c",2),
                new DummyMovie("b",3),
                new DummyMovie("a",1)
        );

        var r1 = movies.stream()
                .filter(m->m.getViews()>1)
                .collect(Collectors.toSet()); // also for to.List()
        System.out.println();

        var r2 = movies.stream()
                .filter(m->m.getViews()>1)
                .collect(Collectors.toMap(m->m.getName(),m->m.getViews()));
        System.out.println(r2);

        var r3 = movies.stream()
                .filter(m->m.getViews()>1)
                .collect(Collectors.toMap(m->m.getName(), Function.identity()));
        System.out.println(r3);

        var r4 = movies.stream()
                .collect(Collectors.summingInt(m->m.getViews()));
        System.out.println(r4);

        var r5 = movies.stream()
                .collect(Collectors.summarizingInt(m->m.getViews()));
        System.out.println(r5);

        var r6 = movies.stream()
                .map(DummyMovie::getName)
                .collect(Collectors.joining(", "));
        System.out.println(r6);
    }
}
