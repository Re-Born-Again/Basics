package com.class_package.questions;

public class Q10 {
    public static void main(String[] args){
        var s = new Student("student1",16,"ABCD123");
        s.displayInfo();
        s.study();
    }
}

class Person1{
    private String name;
    private int age;

    public Person1(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void displayInfo() {
        System.out.println("Name : "+name);
        System.out.println("Age : "+age);
    }
}

interface Study{
    void study();
}

class Student extends Person1 implements Study{
    private String id;

    public Student(String name, int age, String id){
        super(name,age);
        this.id = id;
    }
    @Override
    public void study() {
        System.out.println("Student studies");
    }

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("ID : "+id);
    }
}