package com.class_package.ExecutiveFramework;

import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;
import java.util.function.Supplier;

// .runAsync() // param : Runnable // to run task that doesn't return value, executes in non-blocking fashion
// .supplyAsync() // param : Supplier // to run task that returns value, executes in non-blocking fashion
public class CompletableFuture1 {
    public static void main(String[] args){
        Runnable task1 = () -> System.out.println("task1 is running");
        CompletableFuture<Void> future = CompletableFuture.runAsync(task1);

        Supplier<Integer> task2 = () -> 1;
        CompletableFuture<Integer> future2 = CompletableFuture.supplyAsync(task2);
        try {
            var result2 = future2.get();
            System.out.println("value of future2 : "+result2);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        } catch (ExecutionException e) {
            throw new RuntimeException(e);
        }
    }
}
