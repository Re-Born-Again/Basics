package com.class_package.questions;

public class Q2 {
    public static void main(String[] args){
        Animal[] ani = new Animal[3];
        ani[0] = new Dog();
        ani[1] = new Cat();
        ani[2] = new Horse();

        for(int i=0;i<ani.length;i++){
            ani[i].makeSound();
        }
    }
}

class Cat extends Animal{
    @Override
    protected void makeSound() {
        System.out.println("Meow Meow!");
    }
}

class Horse extends Animal{
    @Override
    protected void makeSound() {
        System.out.println("Heeh Heeh!");
    }
}