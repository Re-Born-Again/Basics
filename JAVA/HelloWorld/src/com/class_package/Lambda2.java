package com.class_package;

// method references
// class/object :: method

public class Lambda2 {
    public Lambda2(String msg){
    }

    public static void main(String[] args){
        greet(new Greet());
        greet((msg)->{
            System.out.println(msg);
        });

        // for built-in methods
        greet((String msg)->{
            System.out.println("Hello from lambda");
        });
        greet(System.out::println); // same as above

        // for static method
        greet(msg -> method1(msg));
        greet(Lambda2::method1); // same as above

        // for non-static method
        var demo = new Lambda2("ignore");
        greet(msg -> demo.method2(msg));
        greet(demo::method2); // same as above

        // for constructor
        var dem = new Lambda2("Lambda2");
        greet(msg -> new Lambda2(msg));
        greet(Lambda2::new); // same as above
    }

    public static void greet(Printer print){
        print.print("Hello from greet");
    }

    public static void method1(String msg){
        System.out.println("method1 prints : "+msg);
    }

    public void method2(String msg){
        System.out.println("method2 prints : "+msg);
    }
}

interface Printer{
    void print(String msg);
}

class Greet implements Printer{
    @Override
    public void print(String msg) {
        System.out.println(msg);
    }
}