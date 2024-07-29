package com.class_package.Streams;

import java.util.List;
import java.util.function.Predicate;

// .filter() // Predicate

public class StreamsFiltering1 {
    public static void main(String[] args){
        var movies = List.of(
                new DummyMovie("a",1),
                new DummyMovie("b",2),
                new DummyMovie("c",3)
        );

        movies.stream()
                .filter(movie->movie.getViews()>1)
                .forEach(movie-> System.out.println(movie.getName()));

        // can also declare like this
        Predicate<DummyMovie> pred = movie -> movie.getViews()>2;
        movies.stream()
                .filter(pred)
                .forEach(movie-> System.out.println(movie.getName()));
    }
}
