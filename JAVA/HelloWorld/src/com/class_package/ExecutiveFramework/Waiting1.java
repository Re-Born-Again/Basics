package com.class_package.ExecutiveFramework;

import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;

// .allOf() // param : CompletableFuture
// .anyOf() // param : CompletableFuture
public class Waiting1 {
    public static void main(String[] args){
        var first = CompletableFuture.supplyAsync(()->1);
        var second = CompletableFuture.supplyAsync(()->2);
        var third = CompletableFuture.supplyAsync(()->3);

        var all = CompletableFuture.allOf(first,second,third);
        all.thenRun(()->{
            try {
                System.out.println("Value of first thread : "+first.get());
                System.out.println("Value of second thread : "+second.get());
                System.out.println("Value of third thread : "+third.get());
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            } catch (ExecutionException e) {
                throw new RuntimeException(e);
            }
            System.out.println("All tasks completed successfully!");
        });

        var any = CompletableFuture.anyOf(first,second,third);
        any.thenAccept((thread)->{
            System.out.println("One of the thread completed successfully! : "+thread);
        });
    }
}
