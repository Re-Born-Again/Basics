package com.class_package.ExecutiveFramework;

import java.util.concurrent.CompletableFuture;

// .thenAccept() // param : Consumer // replaces .get() with try-catch block
public class TransformingCompletableFuture1 {
    public static void main(String[] args){
        var future = CompletableFuture.supplyAsync(()->1);
        future
                .thenApply(val->val*2)
                .thenAccept(val-> System.out.println(val));
    }
}
