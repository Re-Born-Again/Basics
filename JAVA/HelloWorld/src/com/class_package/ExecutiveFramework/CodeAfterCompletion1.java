package com.class_package.ExecutiveFramework;

import java.util.concurrent.CompletableFuture;

// .thenRun() // param : Runnable action
// .thenAccept() // param : Consumer
public class CodeAfterCompletion1 {
    public static void main(String[] args){

        CompletableFuture<Integer> future1 = CompletableFuture.supplyAsync(()->1);

        future1.thenRun(()-> {
            System.out.println("Done Task 1 synchronously by thread : ");
            System.out.println(Thread.currentThread().getName());
        });

        future1.thenRunAsync(()-> {
            System.out.println("Done Task 1 asynchronously by thread : ");
            System.out.println(Thread.currentThread().getName());
        });

        // same exists for Consumer Interface to get the result of the CompletableFuture

        var future2 = CompletableFuture.supplyAsync(()->1);

        future2.thenAccept(r->{
            System.out.println("result of future2 : "+r+", is done synchronously by thread : ");
            System.out.println(Thread.currentThread().getName());
        });

        future2.thenAcceptAsync(r->{
            System.out.println("result of future2 : "+r+", is done asynchronously by thread : ");
            System.out.println(Thread.currentThread().getName());
        });
    }
}
