package com.class_package;

import java.text.NumberFormat;
import java.util.Scanner;

public class Mort {
    private double p, r, y, mort;
    public void set_ip(){
        Scanner ip=new Scanner(System.in);
        System.out.print("Enter Principle : ");
        p=ip.nextDouble();
        if(p<0){
            throw new IllegalArgumentException("Enter value greater than 0!");
        }
        System.out.print("Enter rate per annum : ");
        r=ip.nextDouble();
        if(r<0){
            throw new IllegalArgumentException("Enter value greater than 0!");
        }
        System.out.print("Enter no. years : ");
        y=ip.nextDouble();
        if(y<0){
            throw new IllegalArgumentException("Enter value greater than 0!");
        }
    }
    public void calc_mort(){
        r/=12;
        y*=12;
        double nume,denom;
        nume=p*r*Math.pow(1+r,y);
        denom=Math.pow(1+r,y)-1;
        mort=nume/denom;
    }
    public void show_mort(){
        String mortgage= NumberFormat.getCurrencyInstance().format(mort);
        System.out.println("Mortgage value : "+mortgage);
    }
}
