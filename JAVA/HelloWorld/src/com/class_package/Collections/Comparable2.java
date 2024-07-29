package com.class_package.Collections;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Comparable2 {
    public static void main(String[] args){
        List<Student> s = new ArrayList<>();
        Collections.addAll(s,new Student("s3","b"),new Student("s2","a"),new Student("s1","c"));

        Collections.sort(s);
        System.out.println("Sorted by Name : "+s);

        Collections.sort(s,new SectionComparator());
        System.out.println("Sorted by Sec : "+s);
    }
}

class Student implements Comparable<Student>{
    private String name;
    private String sec;

    public Student(String name, String sec) {
        this.name = name;
        this.sec = sec;
    }

    @Override
    public int compareTo(Student o) {
        return name.compareTo(o.name);
    }

    @Override
    public String toString() {
        return "Student{" +
                "name='" + name + '\'' +
                ", sec='" + sec + '\'' +
                '}';
    }

    public String getsec(){
        return sec;
    }
}

class SectionComparator implements Comparator<Student>{

    @Override
    public int compare(Student o1, Student o2) {
        return o1.getsec().compareTo(o2.getsec());
    }
}