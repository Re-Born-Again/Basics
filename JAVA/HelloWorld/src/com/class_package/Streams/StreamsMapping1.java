package com.class_package.Streams;

import java.util.List;
import java.util.stream.Stream;

// .map() // Function
// .mapToInt() // ToIntFunction // returns primitive
// .flatMap() // Function

public class StreamsMapping1 {
    public static void main(String[] args){
        var movies = List.of(
                new DummyMovie("a",1),
                new DummyMovie("b",2),
                new DummyMovie("b",3)
        );

        movies.stream()
                .map(movie->movie.getName())
                .forEach(System.out::println);

        movies.stream()
                .mapToInt(movie-> movie.getViews())
                .forEach(System.out::println);

        var str = Stream.of(List.of(1,2,3),List.of(4,5,6));
        str
                .forEach(list-> System.out.println(list));

        // Stream<List<obj>> -> Stream<x> // not only list but also map, set ,Array, ...
        var str2 = Stream.of(List.of(1,2,3),List.of(4,5,6));
        str2
                .flatMap(list->list.stream())
                .forEach(list-> System.out.println(list));
    }
}
