package com.class_package.Streams;

import java.util.List;

// .limit() // maxsize
// .skip() // nth to jump
// .takeWhile() // Predicate
// .dropWhile() // Predicate

public class StreamsSlicing1 {
    public static void main(String[] args){
        var movies = List.of(
                new DummyMovie("a",1),
                new DummyMovie("b",2),
                new DummyMovie("c",3),
                new DummyMovie("d",1)
        );

        System.out.println(".limit() : ");
        movies.stream()
                .limit(2)
                .forEach(movie-> System.out.println(movie.getName()));

        System.out.println(".skip() : ");
        movies.stream()
                .skip(2)
                .forEach(movie-> System.out.println(movie.getName()));

        // usually above 2 helps in paging like,
        // for 1000 movies
        // 10 movies per page (page size)
        // for 3rd page
        // skip( (page_no-1) * page_size )
        // limit(page_size)

        System.out.println(".takeWhile() : ");
        movies.stream()
                .takeWhile(movie->movie.getViews()<3) // execute all till views<3 then don't execute
                .forEach(movie-> System.out.println(movie.getName()));

        System.out.println(".dropWhile() : ");
        movies.stream()
                .dropWhile(movie->movie.getViews()<2) // don't execute till view<2 then execute all
                .forEach(movie-> System.out.println(movie.getName()));
    }
}
