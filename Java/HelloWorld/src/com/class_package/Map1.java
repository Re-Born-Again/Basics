package com.class_package;

import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public class Map1 {
    public static <K,V> void disp(Map<K,V> mp){
        for(Map.Entry<K,V> val : mp.entrySet()){
            System.out.println("Key : "+val.getKey()+", Value : "+val.getValue());
        }
    }
    public static void main(String[] args){
        Map<Integer,String> mp = new HashMap<>();
        mp.put(1,"a"); // to add values
        mp.put(2,"b");
        mp.put(3,"c");
        mp.put(3,"d"); // similar to replace
        System.out.println(mp);

        mp.remove(2); // to remove values
        System.out.println("After removing key 2 : ");
        disp(mp); // to iterate values
        mp.remove(1,"a");
        System.out.println("After removing key 1, Val a : ");
        disp(mp);

        mp.putIfAbsent(1,"a"); // puts if the key is not present
        System.out.println(mp);
        mp.putIfAbsent(1,"b");
        System.out.println(mp);
    }
}
