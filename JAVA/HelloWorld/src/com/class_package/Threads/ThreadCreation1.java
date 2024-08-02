package com.class_package.Threads;

import java.util.ArrayList;
import java.util.List;

public class ThreadCreation1 {
    public static void main(String[] args){
        // fun1();
        // fun2();
    }

    public static void fun1(){
        System.out.println(Thread.activeCount()); // to see active threads at the current process // main and garbage collector
        System.out.println(Runtime.getRuntime().availableProcessors()); // to get total available threads

        System.out.println("Thread running at main : "+Thread.currentThread().getName());
        Thread thread = new Thread(new DownloadTaskFile()); // if parameter given then should implement Runnable Interface
        thread.start();

        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }

        List<Thread> threadList = new ArrayList<>();
        Thread thread2 = null;
        System.out.println("Creating threads using loop : ");
        for(int i=0;i<10;i++){
            thread2 = new Thread(new DownloadTaskFile());
            thread2.start();
            threadList.add(thread2);
        }

        try {
            for(var t : threadList){
                t.join();
            }
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
        System.out.println("All threads completed!");
    }

    public static void fun2(){
        Thread thread3 = new Thread(new DownloadTaskFileInterrupt());
        thread3.start();
        try {
            thread3.sleep(100);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
        thread3.interrupt(); // calling alone doesn't interrupt, need to check inside the class for .isInterrupted()
    }
}

class DownloadTaskFile implements Runnable{
    @Override
    public void run() {
        System.out.println("Downloading file on "+Thread.currentThread().getName());
    }
}

class DownloadTaskFileInterrupt implements Runnable{
    @Override
    public void run() {
        System.out.println(Thread.currentThread().getName());
        for(int i=0;i<Integer.MAX_VALUE;i++){
            if(Thread.currentThread().isInterrupted()) break;
            System.out.println("Downloaded byted : "+i);
        }
    }
}
