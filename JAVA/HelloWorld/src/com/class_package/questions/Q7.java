package com.class_package.questions;

public class Q7 {
    public static void main(String[] args){
        var e = new Employee("abcd",20,"Abcd123");

    }
}

class Person{
    private String name;
    private int age;

    public Person(String name, int age){
        this.name = name;
        this.age = age;
    }
}

class Employee extends Person{
    private String id;
    public Employee(String name, int age, String id) {
        super(name, age);
        this.id = id;
    }
}
