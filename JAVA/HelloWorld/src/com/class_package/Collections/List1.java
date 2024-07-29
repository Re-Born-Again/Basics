package com.class_package.Collections;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class List1 {
    public static void main(String[] args){
        List<Integer> l1 = new ArrayList<>();
        l1.add(10); // can also give 1st parameter as index to add like (1,10), adds 10 at index 1
        l1.add(20);
        l1.add(30);
        System.out.println("List1 : "+l1);
        System.out.println("List1 size : "+l1.size());
        System.out.println("Sublist of l1 0,2 : "+l1.subList(0,2) ); // toIndex is inclusive and fromIndex is exclusive

        List<Integer> l2 = new ArrayList<>(); // can also give like : List<Integer> l2 = new ArrayList<>(Array.list(30,40));
        l2.addAll(Arrays.asList(30,40)); // to add more than 1 elem at a time
        System.out.println("List2 : "+l2);

        l1.addAll(l2); // can have 1st parameter as "from index" to append like (1,l2), adds l2 values from index 1 in l1
        System.out.println("Merged list : "+l1);

        System.out.println("l1.contains(10) : "+l1.contains(10));

        l1.remove(1); // remove from index
        System.out.println("After remove(1) : "+l1);

        l1.set(0,50); // replace value in "index" to "new value"
        System.out.println("After set(0,50) : "+l1);

        int idx1 = l1.indexOf(30);
        int idx2 = l1.lastIndexOf(30);
        System.out.println("1st occurence of 30 found at index : "+idx1);
        System.out.println("Last occurence of 30 found at index : "+idx2);

        System.out.println("Value at index 2 : "+l1.get(2)); // .get(index) more like arr[2] in c++ ie. accessing element

        l1.clear(); // removes all values from the list
        System.out.println("After l1.clear() : "+l1);
    }
}
