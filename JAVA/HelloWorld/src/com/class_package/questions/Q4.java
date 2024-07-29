package com.class_package.questions;

import java.util.Scanner;

public class Q4 {
    public static void main(String[] args){
        var c = new Circle();
        var r = new Rectangle();
        c.calculateArea();
        r.calculateArea();
    }
}

abstract class Shape{
    protected abstract void calculateArea();
}

class Circle extends Shape{
    @Override
    protected void calculateArea() {
        float r,a;
        Scanner ip = new Scanner(System.in);
        System.out.print("Enter radius : ");
        r = ip.nextFloat();
        if(r<0) {
            System.out.println("Invalid input!");
            return;
        }
        a = (float) (0.5*r*r);
        System.out.println("Area of circle : "+a);
    }
}

class Rectangle extends Shape{
    @Override
    protected void calculateArea() {
        float l,b;
        Scanner ip = new Scanner(System.in);
        System.out.print("Enter length, breadth : ");
        l = ip.nextFloat();
        b = ip.nextFloat();
        if(l<0 || b<0) {
            System.out.println("Invalid input!");
            return;
        }
        System.out.println("Area of rectangle : "+l*b);
    }
}