package com.class_package;

import java.util.Scanner;

public class Calculator {
    public static double calc(double n,double m,char op){
        switch(op){
            case '+' : return n+m;
            case '-' : return n-m;
            case '*' : return n*m;
            case '/' : if(m!=0) return n/m;
            else return Double.NaN;
            default:
                System.out.println("Invalid operator");
                return Double.NaN;
        }
    }
    public static void main(String[] args){
        double num1;
        double num2;
        double ans;
        char op;

        Scanner ip = new Scanner(System.in);

        System.out.print("Enter 2 numbers : ");
        num1 = ip.nextDouble();
        num2 = ip.nextDouble();

        System.out.print("Enter operator : ");
        op = ip.next().charAt(0);

        ans = calc(num1,num2,op);
        System.out.println("Result : "+ans);
    }
}
