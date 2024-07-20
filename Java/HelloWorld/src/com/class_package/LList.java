package com.class_package;

import java.util.LinkedList;

public class LList {
    public static void main(String[] args) {
        
    }
}

class BuiltinLList{
        LinkedList<Integer> list = new LinkedList<>();
        public void operations(){
            list.addFirst(1);
            list.addFirst(2);
            list.addFirst(3);
            list.addLast(4);
            System.out.println(list);
            list.removeFirst();
            System.out.println(list);
            list.removeLast();
            System.out.println(list);
            System.out.println(list.contains(2));
            System.out.println(list.contains(100));
            System.out.println(list.indexOf(2));
            System.out.println(list.indexOf(100));
        }
}