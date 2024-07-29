package com.class_package.questions;

public class Q8 {
    public static void main(String[] args){
        var d = new Duck();
        d.doFly();
        d.doSwim();
    }
}

interface Swimmable{
    void doSwim();
}
 interface Flyable{
    void doFly();
 }

 class Duck implements Swimmable,Flyable{

     @Override
     public void doFly() {
         System.out.println("Yes!");
     }

     @Override
     public void doSwim() {
         System.out.println("Yes!");
     }
 }