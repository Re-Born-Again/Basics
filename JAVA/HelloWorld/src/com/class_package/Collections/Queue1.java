package com.class_package.Collections;

import java.util.ArrayDeque;
import java.util.Queue;

public class Queue1 {
    public static void main(String[] args){
        Queue<String> q =new ArrayDeque<>(); // deque -> 2 way queue
        q.add("a"); // add val // throw exception if queue full
        q.add("b");
        q.add("c");
        q.offer("d"); // same as add // return false in other queue types if queue full
        System.out.println(q);

        System.out.println(q.peek());// shows first val added // returns null if queue empty
        System.out.println(q.element()); // same as peek // throws exception if queue empty

        System.out.println(q.remove()); // remove first val // throw exception if queue empty
        System.out.println(q);
        System.out.println(q.poll()); // same as remove // returns null if queue empty
        System.out.println(q);

    }
}
