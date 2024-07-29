package com.class_package.questions;

public class Q6 {
    public static void main(String[] args){
        var cal = new AdvancedCalculator();
        cal.add(5,10);
        cal.add(5.5,6.5);
    }
}

class Calculator{
    void add(int a,int b){
        System.out.println("Sum in Calc : "+(a+b));
    }
    void add(double a,double b){
        System.out.println("Sum in Calc : "+(a+b));
    }
}

class AdvancedCalculator extends Calculator{
    @Override
    void add(int a,int b){
        System.out.println("Sum in Adv Calc: "+(a+b));
    }
}