package com.class_package.Streams;

import java.util.Comparator;
import java.util.List;

// .sorted() // the used reference (here DummmyMovie) should implement Comparable interface
// .sorted() // Comparator
// .reversed()

public class StreamsSorting1 {
    public static void main(String[] args){
        var movies = List.of(
                new DummyMovie("a",1),
                new DummyMovie("c",2),
                new DummyMovie("b",3)
        );

        movies.stream()
                .sorted(Comparator.comparing(m->m.getName())) // (a,b) -> {return a.getName().compareTo(b.getName());}
                .forEach(movie->{System.out.println(movie.getName());});

        movies.stream()
                .sorted(Comparator.comparing(DummyMovie::getName).reversed())
                .forEach(m-> System.out.println(m.getName()));
    }
}
