package com.class_package.Collections;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;

public class Collections1 {
    public static void main(String[] args){
        Collection<String> c = new ArrayList<>();
        Collections.addAll(c,"a","b","c","d","e");
        System.out.println("Size : "+c.size());
        System.out.println(c);
        c.remove("c"); // .clear() to clear, also has .isEmpty()
        System.out.println(c);
        System.out.println(".contains() : "+c.contains("a"));

        // to convert Collection to Object Array
        Object[] o = c.toArray();
        // to convert to any specific Array type like String
        String[] s = c.toArray(new String[0]); // can give size of collection or 0 itself is fine
        s[1].toUpperCase();
        System.out.println(Arrays.toString(s)); // no Upper Case printed as Strings are immutable

        Collection<String> c2 = new ArrayList<>();
        c2.addAll(c);
        System.out.println(c==c2);
        System.out.println(c.equals(c2));
    }
}
