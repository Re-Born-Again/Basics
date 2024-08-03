package com.class_package.ExecutiveFramework;

import java.util.concurrent.CompletableFuture;

// can convert a synchronous method to asynchronous by wrapping it inside CompletableFuture object
public class AsynchronousAPI1 {
    public static void main(String[] args){
        var m = new Msg();
        m.sendMsg();
        System.out.println("This is a delayed msg!");

        var m2 = new Msg();
        m.sendAsync();
        System.out.println("This is not a delayed msg!");

        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }
}

class Msg{
    public void sendMsg(){
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
        System.out.println("msg sent!");
    }
    public CompletableFuture<Void> sendAsync(){
        return CompletableFuture.runAsync(()-> System.out.println("msg sent asynchronously"));
    }
}