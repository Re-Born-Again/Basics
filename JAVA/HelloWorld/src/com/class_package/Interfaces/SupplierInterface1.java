package com.class_package.Interfaces;

import java.util.function.DoubleSupplier;
import java.util.function.Supplier;

// Interface Supply<T>
// argument(s) : -
// return : T
// .get(), .apply()

public class SupplierInterface1 {
    public static void main(String[] args){
        Supplier<Double> getRandom = ()->{return Math.random();};
        var rand = getRandom.get();
        System.out.println("random value : "+rand);

        // Consumer,Supplier,Function,Predicate interfaces has specializations for primitive values to prevent auto-boxing and un-boxing
        DoubleSupplier getRandom2 = ()->{return Math.random();};
        var rand2 = getRandom.get();
        System.out.println("random value (using primitives) : "+rand2);
    }
}
