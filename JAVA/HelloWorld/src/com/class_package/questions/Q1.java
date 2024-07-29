package com.class_package.questions;

public class Q1 {
    public static void main(String[] args){

        var d = new Dog();
        d.makeSound();

    }
}

abstract class Animal{
    protected abstract void makeSound();
}

class Dog extends Animal{
    @Override
    public void makeSound() {
        System.out.println("Bow Bow !");
    }
}
