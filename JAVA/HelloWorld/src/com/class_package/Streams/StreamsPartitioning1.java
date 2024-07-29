package com.class_package.Streams;

import java.util.List;
import java.util.stream.Collectors;

// .partitioningBy() // Predicate
// .partitioningBy() // Predicate, Collector
public class StreamsPartitioning1 {
    public static void main(String[] args){
        var movies = List.of(
                new DummyMovie("a",1),
                new DummyMovie("c",2),
                new DummyMovie("b",3),
                new DummyMovie("a",1)
        );

        var r1 = movies.stream()
                .collect(Collectors.partitioningBy(m->m.getViews()>1));
        System.out.println(r1);

        var r2 = movies.stream()
                .collect(Collectors.partitioningBy(
                        m->m.getViews()>1,
                        Collectors.mapping(
                                m->m.getName(),
                                Collectors.joining(", ")
                        )
                ));
        System.out.println(r2);
    }
}
