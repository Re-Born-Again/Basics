package com.class_package.Collections;

import java.util.HashMap;
import java.util.Map;

public class Map1 {
    public static <K,V> void disp(Map<K,V> mp){
        for(Map.Entry<K,V> val : mp.entrySet()){ // mp.keySet() for only keys & mp.values() for only values
            System.out.println("Key : "+val.getKey()+", Value : "+val.getValue());
        }
    }
    public static void main(String[] args){
        Map<Integer,String> mp = new HashMap<>();
        mp.put(1,"a"); // to add values
        mp.put(2,"b");
        mp.put(3,"c");
        mp.put(3,"d"); // similar to replace // mp.replace(3,"d");
        mp.put(4,"");
        System.out.println("Map contents : "+mp);

        System.out.println("Accssing values by keys : "+mp.get(1));
        System.out.println("putOrDefault : "+mp.getOrDefault(5,"Nah"));
        System.out.println("Accessing undefined key,val : "+mp.get(10)); // returns null even for int type

        System.out.println("containsKey : "+mp.containsKey(2)); // containsKey() return boolean

        mp.remove(2); // to remove values
        System.out.println("After removing key 2 : ");
        disp(mp); // to iterate values
        mp.remove(1,"a");
        System.out.println("After removing key 1, Val a : ");
        disp(mp);

        mp.putIfAbsent(1,"a"); // puts if the key is not present
        System.out.println("After putIfAbsent : "+mp);
        mp.putIfAbsent(1,"b");
        System.out.println("After puIfAbsent : "+mp);
    }
}
