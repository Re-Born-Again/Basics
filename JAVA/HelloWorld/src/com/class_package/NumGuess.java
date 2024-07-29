package com.class_package;

import java.util.Scanner;

public class NumGuess {
    public static void main(String[] args){
        int min=50;
        int max=100;
        int att=3;
        int i=0;
        int n;
        boolean flag = false;
        int num = min+(int) (Math.random()*(max-min+1));

        System.out.println("Guess the number with "+att+" attempts.");
        Scanner ip = new Scanner(System.in);

        do{
            i++;
            System.out.print("Attempt "+i+" : ");
            n = ip.nextInt();
            if(n==num){
                System.out.println("Correct guess!");
                flag = true;
            }
            else if(n<num){
                System.out.println("Answer is greater than "+n);
            }
            else{
                System.out.println("Answer is lesser than "+n);
            }
        }while(i<att && !flag);

        if(!flag){
            System.out.println("Correct answer is "+num);
        }
    }
}
