package com.class_package.ExecutiveFramework;

import java.util.concurrent.CompletableFuture;

public class ComposingCompletableFuture1 {
    public static CompletableFuture<String> getemailAsync(){
        return CompletableFuture.supplyAsync(()->"email");
    }
    public static CompletableFuture<String> getplaylistAsync(){
        return CompletableFuture.supplyAsync(()->"playlist");
    }
    public static void main(String[] args){
        CompletableFuture.supplyAsync(()->"email")
                .thenCompose(email->CompletableFuture.supplyAsync(()->"playlist"))
                .thenAccept(playlist-> System.out.println(playlist));

        // same as :
        getemailAsync()
                .thenCompose(email->getplaylistAsync())
                .thenAccept(playlist-> System.out.println(playlist));
    }
}
