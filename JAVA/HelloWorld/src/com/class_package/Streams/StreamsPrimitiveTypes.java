package com.class_package.Streams;

import java.util.stream.DoubleStream;
import java.util.stream.IntStream;
import java.util.stream.LongStream;

public class StreamsPrimitiveTypes {
    public static void main(String[] args){
        IntStream.range(1,5)
                .forEach(System.out::print);

        System.out.println();

        LongStream.rangeClosed(1,5)
                .forEach(System.out::print);
    }
}
