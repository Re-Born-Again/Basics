package com.class_package.Threads;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

// one of the strategy for thread safety
// Confinement -> instead of making multiple threads accessing a same resource, we create n resources for n threads
public class ThreadConfinement1 {
    public static void main(String[] args){

        List<Thread> threadList = new ArrayList<>();
        List<DownloadStatusC> statusCList = new ArrayList<>();

        for(int i=0;i<10;i++){
            var dstat = new DownloadStatusC();
            Thread thread = new Thread(new DownloadTaskFileC(dstat));
            threadList.add(thread);
            statusCList.add(dstat);
            thread.start();
        }

        for(var t : threadList){
            try {
                t.join();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }

        var status = statusCList.stream()
                        .map(s->s.getStatus())
                        .reduce(Integer::sum);

        System.out.println("Total : "+status);
    }
}

class DownloadStatusC{
    private int status;
    public void incrementStatus(){
        status++;
    }
    public int getStatus() {
        return status;
    }
}

class DownloadTaskFileC implements Runnable{
    private final DownloadStatusC dstat;
    public DownloadTaskFileC(DownloadStatusC dstat) {
        this.dstat = dstat;
    }
    @Override
    public void run() {
        for(int i=0;i<10_000;i++){
            dstat.incrementStatus();
        }
    }
}