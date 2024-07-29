package com.class_package.questions;

public class Q9 {
    public static void main(String[] args){
        var wm = new WashingMachine();
        var r = new Refrigerator();
        method(wm);
        method(r);
    }

    public static void method(Appliance a){
        if(a instanceof Appliance){
            a.name();
        }
    }
}

abstract class Appliance{
    public abstract void name();
}

class WashingMachine extends Appliance{
    @Override
    public void name() {
        System.out.println("Washing Machine");
    }
}

class Refrigerator extends Appliance{
    @Override
    public void name() {
        System.out.println("Appliance");
    }
}

