package com.class_package;

// <T> -> for single template(generic)
// <K, V, ...> -> such for multiple templates(generics)
// the values of templates can only be reference types ie. "Integer" rather than "int"

// parent_class variable = new child_class(); is valid as child class is a subtype of parent class.
// class<parent_class> variable = new class<child_class>(); is not valid as class<child_class> is not a subtype of class<parent_class>.
// above the "class" represents name of a class and "<>" rep. template(generic) and "parent_class" & "child_class" rep. datatype the template should handle

public class Generics {
    public static void main(String[] args){
        var s = new Sample<Integer>(); // need to specifically declare what type this object handles
        s.add(5);
        s.index(5);
        s.value(0);

        Sample2.dummy(2,4);
    }
}

// Generic Class
class Sample<T>{
    private T[] variable = (T[]) new Object[10];
    // cannot initialize like : T[] variable = new T[];
    int count = 0;
    public void add(T val){
        variable[count++] = val;
        System.out.println("Value '"+val+"' added successfully");
    }
    public void value(int idx){
        System.out.println("Value at index '"+idx+"' : "+variable[idx]);
    }
    public void index(T val){
        for(int i=0;i<count;i++){
            if(variable[i]==val){
                System.out.println("Value '"+val+"' found at index : "+i);
                break;
            }
        }
    }
}

// Generic method
class Sample2{
    public static <T> void dummy(T first, T second){ // the return type can also be T
        System.out.println("Value passed are : "+first+" "+second);
    }
}