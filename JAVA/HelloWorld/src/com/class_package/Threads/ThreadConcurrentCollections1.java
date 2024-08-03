package com.class_package.Threads;

import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

public class ThreadConcurrentCollections1 {
    public static void main(String[] args){
        Map<Integer,String> map = new ConcurrentHashMap<>();

        var thread1 = new Thread(new MapAdd(map));
        var thread2 = new Thread(new MapGet(map));
        var thread3 = new Thread(new MapRemove(map));
        thread1.start();
        thread2.start();
        thread3.start();
    }
}

class MapAdd implements Runnable {
    Map<Integer,String> map;
    MapAdd(Map<Integer,String> map){
        this.map=map;
    }
    @Override
    public void run() {
        System.out.println("Attempt to add 1,a : ");
        map.put(1,"a");
        System.out.println("Added 1,a successfully");
    }
}

class MapGet implements Runnable {
    Map<Integer,String> map;
    MapGet(Map<Integer,String> map){
        this.map=map;
    }
    @Override
    public void run() {
        System.out.println("Attempt to get 1,a : ");
        try {
            String value = map.get(1);
            if (value == null) {
                throw new NullPointerException("Value for key 1 is null");
            }
            System.out.println("Value of map(1) : " + value);
        } catch (NullPointerException e) {
            System.out.println(e.getMessage());
        }
    }
}

class MapRemove implements Runnable {
    Map<Integer,String> map;
    MapRemove(Map<Integer,String> map){
        this.map=map;
    }
    @Override
    public void run() {
        System.out.println("Attempt to remove 1,a");
        map.remove(1);
        System.out.println("Value 1,a removed successfully");
    }
}