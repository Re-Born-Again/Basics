package com.class_package.Collections;

import java.util.*;

public class Set1 {

    public static Set<String> s1 = new HashSet<>();
    public static Set<String> s2 = new HashSet<>();

    public static void set_set(){
        s1.clear();
        s2.clear();
        Collections.addAll(s1,"a","b","c");
        Collections.addAll(s2,"b","c","d");
    }

    public static void main(String[] args){

        Set<String> s = new HashSet<>(); // keeps vals in ascending order without duplicates (case sensitive)
        Collections.addAll(s,"C","b","a","c","b");
        System.out.println(s);

        Set<String> ss =new HashSet<>(Arrays.asList("m","n","o"));
        System.out.println(ss);

        Collection<String> c = new ArrayList<>();
        Collections.addAll(c,"Z","y","x","y");
        Set<String> set = new HashSet<>(c); // giving collections to set to use its properties
        System.out.println(set);

        // operations -> union, intersection, difference

        // union
        set_set();
        s1.addAll(s2); // store result on s1
        System.out.println("Union : "+s1);

        // intersection
        set_set();
        s1.retainAll(s2); // store result on s1
        System.out.println("Intersection : "+s1);

        // difference
        set_set();
        s1.removeAll(s2); // store result on s1
        System.out.println("Difference : "+s1);
    }
}
