package com.class_package.Streams;

import java.util.List;

// .distinct()

public class StreamsUnique1 {
    public static void main(String[] args){
        var movies = List.of(
                new DummyMovie("a",1),
                new DummyMovie("c",2),
                new DummyMovie("b",3),
                new DummyMovie("a",1)
        );

        movies.stream()
                .map(DummyMovie::getViews)
                .distinct()
                .forEach(System.out::println);
    }
}
