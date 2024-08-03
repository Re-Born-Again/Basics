package com.class_package.ExecutiveFramework;

import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;

// .get() here is used to get the exception thrown by non-main thread to main thread
// .exceptionally() // param : Function<Throwable,?>
public class HandlingExceptions1 {
    public static void main(String[] args){
        var future = CompletableFuture.supplyAsync(()->{
            System.out.println("Getting value");
            throw new IllegalStateException(); // throwing purposefully to handle later
        });

        try {
            var val = future.exceptionally(ex->123).get(); // future.get(); throws exception which is crashing of application
            // the above statement replaces an exception with a value
            System.out.println(val);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        } catch (ExecutionException e) {
            throw new RuntimeException(e);
        }
    }
}
