package com.class_package.Streams;

import java.util.List;

// .peek() // Consumer

public class StreamsPeeking1 {
    public static void main(String[] args){
        var movies = List.of(
                new DummyMovie("a",1),
                new DummyMovie("c",2),
                new DummyMovie("b",3),
                new DummyMovie("a",1)
        );

        movies.stream()
                .peek(m-> System.out.println(m.getName()+" "+ m.getViews()))
                .map(DummyMovie::getViews)
                .peek(m-> System.out.println("mapped : "+m))
                .distinct()
                .peek(m-> System.out.println("distinct : "+m))
                .forEach(m-> System.out.println("sout : "+m));
    }
}
