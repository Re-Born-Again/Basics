package com.class_package.Threads;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.atomic.AtomicInteger;

public class ThreadAdders1 {
    public static void main(String[] args){

        List<Thread> threadList = new ArrayList<>();
        var dstat = new DownloadStatusA();

        for(int i=0;i<10;i++){
            Thread thread = new Thread(new DownloadTaskFileA(dstat));
            threadList.add(thread);
            thread.start();
        }

        for(var t : threadList){
            try {
                t.join();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }

        System.out.println("Total : "+dstat.getStatus());
    }
}

class DownloadStatusA{
    private AtomicInteger status = new AtomicInteger();
    public void incrementStatus(){
        status.incrementAndGet();
    }
    public int getStatus() {
        return status.get();
    }
}

class DownloadTaskFileA implements Runnable{
    private final DownloadStatusA dstat;
    public DownloadTaskFileA(DownloadStatusA dstat) {
        this.dstat = dstat;
    }
    @Override
    public void run() {
        for(int i=0;i<10_000;i++){
            dstat.incrementStatus();
        }
    }
}
