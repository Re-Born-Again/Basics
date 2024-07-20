package com.class_package;
// class names start with capital
// function name start with small
import java.awt.*;
import java.text.NumberFormat;
import java.util.Arrays;
import java.util.Date;
import java.util.Scanner;

// src code(*.java) -> javac -> java byte code(*.class)
// java byte code(*.class) -> JVM -> Native code(windows,Mac,...)

// JRE has JVM, core libraries and supporting files(required by JVM and core libraries)
// JDK has JRE, javac and development tools(debugger, generating document)
// JRE is a part of JDK

public class Main {
    public static void main(String[] args) {
        // primitive data types :
        byte bval=127;
        short sval=32_767;
        int ival=2_147_483_647;
        long lval=9_223_372_036_854_775_807L;
        float fval=3.141_592F;
        double dval=3.14_159_265_358_979_323_846;
        char cval='a';
        boolean boolval=true;
        System.out.println("Long has suffix L/l with lval : "+lval);
        System.out.printf("Float has suffix F/f with fval : %f %n",fval);
        System.out.println();

        // reference data types :
        String strval="Hello"; // to compare string use str1.equals(str2) which returns bool value
        System.out.println("strval value : "+strval);
        System.out.println("strval length : "+strval.length());

        Date now=new Date();
        System.out.println("Time now : "+now);

        Point point1=new Point(1,1);
        Point point2=point1;
        System.out.println("point1 value : "+point1);
        point1.x=2; // value of point2 also changes as the have a common
        System.out.println("point2 value : "+point2);

        // comparison operators are only for primitive types not for reference types. They work different for reference types
        // >, <, ==, !=, <=, >= .... same as c

        // Arrays
        int[] arrval={3,4,2,5,1}; // initially assigned to 0
        // can use : Arrays.fill(arr, 0); also
        System.out.println("arrval length value : "+arrval.length);
        Arrays.sort(arrval);
        String arrstr= Arrays.toString(arrval);
        System.out.println(arrstr);
        System.out.println();

        int [][] arr2={{1,2,3},{4,5,6},{7,8,9}};
        System.out.println("arr2 length (row) : "+arr2.length);
        String arr2str= Arrays.deepToString(arr2);
        System.out.println("arr2 values : "+arr2str);

        // constants
        float a=3.14F;
        a=1;
        System.out.println("PI value : "+a);
        final float b=4F;
        // error for b=1F;
        System.out.println();

        // same as other languages
        double x=10/3; // 3.0
        System.out.println("x value : "+x);
        double y=(double) 10/(double) 3; // 3.333...
        System.out.println("y value : "+y);
        // error for : int y=(double) 10/(double) 3;
        System.out.println();

        // casting
        // to prevent data loss this ordered is followed : byte -> short -> int -> long -> float -> double
        int m=10;
        double n=m+2; // implicit casting
        System.out.println("value of n : "+n);
        // not following the order may cause data loss like :
        double i=2.2;
        int j=(int)i+1; // (int) is explicit casting
        // error for : int j=i+1;
        System.out.println("value of j : "+j);
        // string -> num types
        String s="10";
        int si=Integer.parseInt(s)+3;
        // same for Float.parseFloat(), Short.parseShort(),...
        System.out.println("si value : "+si);
        System.out.println();

        // formatting numbers like $12,123 or 10%
        NumberFormat currency = NumberFormat.getCurrencyInstance(); // cant use : NumberFormat c= new NumberFormat -> because its an abstract class
        String result = currency.format(12345.678);
        System.out.println("Formatted number value : "+result);

        String result2 = NumberFormat.getInstance().format(12.345678); // making it as a single line
        System.out.println("Formatted percent : "+result2);
        System.out.println();

        // condition if-else & switch : same as c,c++

        // loops for, for each, while, do while :  same as c,c++

    }

    public static void user_input(){
        // input from user
        Scanner input=new Scanner(System.in); // System.in for getting input from terminal
        System.out.print("Enter a byte value : "); // %d,%n,... can be used only in printf(), print() is only to display strings
        byte v1= input.nextByte(); // same for short, int, long, float, double, boolean
        // these read only tokens and the remaining white space is queued
        System.out.println("Entered byte value : "+v1);
        // for string,
        System.out.print("Enter str1 value : ");
        String str1= input.next();
        System.out.println("Entered str1 value : "+str1);

        Scanner strip=new Scanner(System.in);
        System.out.print("Enter str2 value : ");
        String str2 = strip.nextLine(); // for line of string as input
        System.out.println("Entered string value : "+str2);
    }

    public static void mortgage(){

        // code for mortgage calculator m=(p*r*((1+r)**n))/(((1+r)**n)-1)
        // p-principle, r-rate of interest, n-no.years
        Scanner input= new Scanner(System.in);
        double mort,p,r;
        int ny;

        System.out.print("Enter principle : ");
        p=input.nextDouble();
        System.out.print("Enter Interest rate per annum : ");
        r=input.nextDouble();
        System.out.print("Enter no. years : ");
        ny=input.nextInt();
        System.out.printf("Entered values for \nPrinciple : %f\nInterest rate : %f\nNo. years : %d\n",p,r,ny);

        r/=12;
        ny*=12;
        double nume,denom;
        nume=p*r*Math.pow(1+r,ny);
        denom=Math.pow(1+r,ny)-1;
        mort=nume/denom;

        String mortgage=NumberFormat.getCurrencyInstance().format(mort);
        System.out.println("Mortgage value : "+mortgage);


    }
    public static void exception_handle(){
        // exception handling program :
        Scanner sc = new Scanner(System.in);
        int t=sc.nextInt();
        for(int i=0;i<t;i++) {
            try {
                long x=sc.nextLong();
                System.out.println(x+" can be fitted in:");
                if(x>=-128 && x<=127)System.out.println("* byte");
                if(x>=-32768 && x<=32767)System.out.println("* short");
                if(x>=-2_147_483_648 && x<=2_147_483_647)System.out.println("* int");
                if(x>=-9_223_372_036_854_775_808L && x<=9_223_372_036_854_775_807L)System.out.println("* long");
                if(x>9_223_372_036_854_775_807L);
                //Complete the code
            }
            catch(Exception e) {
                System.out.println(sc.next()+" can't be fitted anywhere."); // when trying to read invalid num like string or exceeding long type the control jumps to catch block where it reads by sc.next() and prints the value
            }
        }

    }
}