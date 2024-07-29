package com.class_package.Collections;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class List2 {
    public static void main(){
        List<List<Integer>> l1 = new ArrayList<>();
        List<Integer> li1 = new ArrayList<>();

        li1.add(1);
        l1.add(li1);
        System.out.println("Elems in l1 : "+l1);

        li1.addAll(Arrays.asList(1,1));
        l1.add(li1);
        System.out.println("Elems in l1 : "+l1);
    }
}
