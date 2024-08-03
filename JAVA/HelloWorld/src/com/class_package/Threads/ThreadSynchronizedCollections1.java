package com.class_package.Threads;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;

public class ThreadSynchronizedCollections1 {
    public static void main(String[] args){
        Collection<Integer> c = Collections.synchronizedCollection(new ArrayList<>());

        var thread1 = new Thread(()->{
            c.addAll(Arrays.asList(1,2,3));
        });
        var thread2 = new Thread(()->{
            c.addAll(Arrays.asList(4,5,6));
        });

        thread1.start();
        thread2.start();

        try {
            thread1.join();
            thread2.join();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }

        System.out.println("Values in Collection : "+c);
    }
}
