package com.class_package.Streams;

import java.util.Comparator;
import java.util.List;
import java.util.Optional;

// .count()
// .anyMatch() // Predicate
// .allMatch() // Predicate
// .noneMatch() // Predicate
// .findFirst()
// .findAny()
// .max() // Comparator
// .min() // Comparator

// .reduce() // BinaryOperator
// .reduce() // optional,BinaryOperator

public class StreamsReducers1 {
    public static void main(String[] args){
        var movies = List.of(
                new DummyMovie("a",1),
                new DummyMovie("c",2),
                new DummyMovie("b",3),
                new DummyMovie("a",1)
        );

        boolean r1 = movies.stream()
                .anyMatch(m->m.getViews()>2); // checks if any match is there
        System.out.println(r1);

        boolean r2 = movies.stream()
                .allMatch(m->m.getViews()>2); // checks if all are matching
        System.out.println(r2);

        boolean r3 = movies.stream()
                .noneMatch(m->m.getViews()>2); // checks if none matches
        System.out.println(r3);

        var r4 = movies.stream()
                .findFirst()
                .get();
        System.out.println(".findFirst() : "+r4.getName());

        var r5 = movies.stream()
                .findAny()
                .get();
        System.out.println(".findAny() : "+r5.getName());

        var r6 = movies.stream()
                .max(Comparator.comparing(DummyMovie::getViews))
                .get();
        System.out.println(".max() : "+r6.getName());

        var r7 = movies.stream()
                .min(Comparator.comparing(DummyMovie::getViews))
                .get();
        System.out.println(".min() : "+r7.getName());

        Optional<Integer> val = movies.stream()
                .map(DummyMovie::getViews)
                .reduce((a,b)->a+b);
        System.out.println(val);
        System.out.println(val.orElse(0));

        // same as above
        Integer val2 = movies.stream()
                .map(DummyMovie::getViews)
                .reduce(0,Integer::sum);
        System.out.println(val2);
    }
}
