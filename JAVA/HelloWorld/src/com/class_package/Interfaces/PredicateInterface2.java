package com.class_package.Interfaces;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Predicate;

public class PredicateInterface2 {

    public static <T> List<T> pred(List<T> l, Predicate<T> pred){
        List<T> ans= new ArrayList<>();
        for(T elem : l){
            if(pred.test(elem)){
                ans.add(elem);
            }
        }
        return ans;
    }

    public static void main(String[] args){
        List<Integer> l1=List.of(1,2,3,4,5,6);
        System.out.println(pred(l1,n->n%2==0));
        System.out.println(pred(l1,n->n>3));

        List<String> l2=List.of("a","b","c");
        System.out.println(pred(l2,n->n.startsWith("b")));
    }

}
