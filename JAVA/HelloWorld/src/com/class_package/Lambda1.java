package com.class_package;

public class Lambda1 {
    public static void main(String[] args){
        // lambda to function
        IArith add = new Add();
        Arith(add);

        IArith sub = new Sub();
        Arith(sub);

        Arith((int a,int b)->{
            int ans = a*b;
            System.out.println("Multiplication : "+ans);
        });

        // lambda to variable
        IArith aaa = new Add();
        aaa.operation(1,2);

        IArith bbb = (int a,int b)->{
            int ans = a*b;
            System.out.println("Multiplication : "+ans);
        };
        bbb.operation(1,2);

        Arith(bbb);

        // the lambda function can also use the local variable
        int val = 10;
        Arith((int a,int b)->{
            System.out.println("Value of val : "+val);
        });

    }

    public static void Arith(IArith arith){
        int a = 5;
        int b= 10;
        arith.operation(a,b);
    }

}

interface IArith{
    void operation(int a,int b);
}

class Add implements IArith{
    @Override
    public void operation(int a, int b) {
        int ans = a+b;
        System.out.println("Addition : "+ans);
    }
}

class Sub implements IArith{

    @Override
    public void operation(int a, int b) {
        int ans = a-b;
        System.out.println("Subtraction : "+ans);
    }
}