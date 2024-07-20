package com.class_package;
// objects are stores in heap memory
// primitive and other short lived variables are stored in stack

public class TextBox_Main {
    public static void main(String[] args) {
        var text1=new TextBox(); // first JRE evaluate right side of assignment operator
                                // creates TextBox object and store it in heap, say addr:100
                                // then left side of the assignment operator
                                // then for "text1" allocate memory on stack then store addr of object on heap ie. 100
                                // thats why its called as reference types
        System.out.println("after text1 declaration : ");
        text1.setText("New Text");
        text1.printText();
        System.out.println();

        var text2=new TextBox();
        System.out.println("after text2 declaration : ");
        text2.printText();
        text2.setText("New Text2");
        text2.printText();

        text1.printText();
        System.out.println();

        var text3=text1; // has same object as text1 ie. both text1 & text2 in stack are pointing the same object in heap
                        // so can modify the object using both text1 & text3
        System.out.println("after text3 declaration : ");
        text3.printText();
        text3.setText("New Text3");
        text3.printText();

        text1.printText();
        System.out.println();

        System.out.println("Total objects created : "+TextBox.count);
        TextBox.count(); // both lines perform same task


    }// when exiting a method JRE deallocates all the variable stored in stack
    // JRE has garbage collector which deallocates the objects created after a period of time fromm the heap

}
