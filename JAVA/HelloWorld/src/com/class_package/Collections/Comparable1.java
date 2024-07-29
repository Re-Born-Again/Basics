package com.class_package.Collections;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Comparable1 {
    public static void main(String[] args){
        List<Customer> c = new ArrayList<>();
        Collections.addAll(c,new Customer("c","e1"),
                             new Customer("b","e3"),
                             new Customer("a","e2"));
        Collections.sort(c);
        System.out.println("Sorted by Name : "+c);

        Collections.sort(c, new EmailComparator());
        System.out.println("Sorted by Email : "+c);

    }
}

class Customer implements Comparable<Customer>{
    private String name;
    private String email;

    public Customer(String name,String email){
        this.name = name;
        this.email = email;
    }

    @Override
    public int compareTo(Customer o) {
        return name.compareTo(o.name); // return o.name.compareTo(name); -> gives in descending order
    }

    @Override
    public String toString() {
        return "Name : "+name;
    }

    public String getemail(){
        return email;
    }
}

class EmailComparator implements Comparator<Customer>{

    @Override
    public int compare(Customer o1, Customer o2) {
        return o1.getemail().compareTo(o2.getemail());
    }
}