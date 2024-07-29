package com.class_package;

public class TextBox {
    static int count; // instance members belong to classes not objects
    String text; // instance members belong to objects not classes
    public TextBox() {
        // here this() is used for constructor overloading
        /* this("Non-parameter constructor"); // need to use this() as a first line
        System.out.println("The above statement is printed by parameter constructor");
        */
        System.out.println("TextBox constructor called!");
        count++;
    }
    public TextBox(String text) {
        System.out.println("TextBox constructor called with value: " + text+" !");
        count++;
    }
    public void setText(String text){
        this.text = text; // "this" keyword is used to refer current object
    }
    public void printText(){
        System.out.println("Text : "+text);
    }
    public static void count(){
        System.out.println("Total objects created : "+count);
    }
}

// throw new IllegalArgumentException("Msg to print"); this is for telling user to enter valid values, can be printed with conditional statements
