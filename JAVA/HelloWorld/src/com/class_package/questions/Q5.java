package com.class_package.questions;

public class Q5 {
    public static void main(String[]  args){
        var v = new Vehicle();
        v.move();
        v.stop();

        var c = new Car();
        c.move();
        c.stop();
    }
}

interface Movable{
    void move();
    void stop();
}

class Vehicle implements Movable{
    @Override
    public void move() {
        System.out.println("Vehicle Movable!");
    }

    @Override
    public void stop() {
        System.out.println("Vehicle Stoppable!");
    }
}

class Car extends Vehicle{
    @Override
    public void move() {
        System.out.println("Car Movable!");
    }

    @Override
    public void stop() {
        System.out.println("Car stoppable!");
    }
}