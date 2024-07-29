package com.class_package;

// the public class should be the file name

public class Inherit_Main {
    public static void main(String[] args) {
        var p=new parent("parent");
        var c=new child();
        c.disp();
        System.out.println(c); // equal to System.out.println(c.toString()); coz sout automatically calls .toString() for any objects passed
    }
}
class parent {

    public parent(String arg){
        System.out.println("Value inside parent class : "+arg);
    }
    public void disp(){
        System.out.println("parent disp");
    }
}

class child extends parent {

    public child(){
        super("child"); // "super()" is used to give parameter to its parent class
        System.out.println("Inside child class!");
    }
    public void disp(){
        System.out.println("child disp");
    }

    @Override // sometimes not necessary for this keyword but better to use it for clear understanding
    public String toString(){
        System.out.println("toString is a method from object class, but it gets overridden with arg : ");
        return "return value of toString";
    }
}
