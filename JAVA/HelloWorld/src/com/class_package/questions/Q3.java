package com.class_package.questions;

public class Q3 {
    public static void main(String[] args){
        var g = new Guitar();
        g.play();
    }
}

interface Playable{
    void play();
}

class Guitar implements Playable{

    @Override
    public void play() {
        System.out.println("Ting Ting!");
    }
}
