package com.class_package.ExecutiveFramework;

import java.util.concurrent.CompletableFuture;

// .thenCombine() // param : CompletionStage
public class CombiningCompletableFuture1 {
    public static void main(String[] args){
        var first = CompletableFuture.supplyAsync(()->20);
        var second = CompletableFuture.supplyAsync(()->50);

        first
                .thenCombine(second,(num1,num2)->num1*num2)
                .thenAccept(val-> System.out.println(val));
    }
}
