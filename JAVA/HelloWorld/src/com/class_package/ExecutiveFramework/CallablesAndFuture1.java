package com.class_package.ExecutiveFramework;

import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

// Callables return some values
// .get() in threads forces the current thread(here main thread) until the .get() result is received
//which causes synchronous problem
public class CallablesAndFuture1 {
    public static void main(String[] args){
        ExecutorService executor = Executors.newFixedThreadPool(2);
        System.out.println(executor.getClass().getName());

        try{
            Future<Integer> future = executor.submit(() -> {
                Task.simulate();
                return 1;
            });
            System.out.println("Working...");
            try {
                var result = future.get();
                System.out.println("future : "+result);
            } catch (ExecutionException | InterruptedException e) {
                throw new RuntimeException(e);
            }
        }finally{
            executor.shutdown();
        }
    }
}

class Task{
    public static void simulate(){
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }
}