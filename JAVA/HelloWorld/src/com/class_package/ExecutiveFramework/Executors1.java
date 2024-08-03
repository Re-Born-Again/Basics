package com.class_package.ExecutiveFramework;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

// .submit() -> assign a task for the set of threads to execute // can pass Runnable and Callable objects
// .shutdown() -> to terminate the program after finishing the allocated task
// they are given in try finally block so ensure the .shutdown() executes even though some exceptions are thrown and program ends without running .shutdown()
public class Executors1 {
    public static void main(String[] args){
        ExecutorService executor = Executors.newFixedThreadPool(2);
        System.out.println(executor.getClass().getName());

        try{
            for (int i=0;i<10;i++) {
                executor.submit(() -> {
                    System.out.println(Thread.currentThread().getName());
                });
            }
        }finally{
            executor.shutdown();
        }
    }
}
