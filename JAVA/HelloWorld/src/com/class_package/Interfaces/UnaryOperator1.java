package com.class_package.Interfaces;

// Interface UnaryOperator<T>
// extends super interface Function<T,T>
// argument(s) : T
// returns : T
// .apply(), .andThen(), .compose()
import java.util.function.UnaryOperator;

public class UnaryOperator1 {
    public static void main(String[] args){
        UnaryOperator<Integer> sq = (a) -> {return a*a;};
        UnaryOperator<Integer> inc = (a) -> {return a+1;};

        var result = sq.andThen(inc).apply(5);
        System.out.println(result);
        System.out.println(sq.compose(inc).apply(5));

    }
}
