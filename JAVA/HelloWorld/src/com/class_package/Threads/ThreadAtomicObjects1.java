package com.class_package.Threads;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.atomic.LongAdder;

// one of the strategy for thread safety
// Atomic data types -> changes values at atomic level using compare & swap rather and 3 steps
public class ThreadAtomicObjects1 {
    public static void main(String[] args){

        List<Thread> threadList = new ArrayList<>();
        var dstat = new DownloadStatusAO();

        for(int i=0;i<10;i++){
            Thread thread = new Thread(new DownloadTaskFileAO(dstat));
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

class DownloadStatusAO{
    private LongAdder status = new LongAdder();
    public void incrementStatus(){
        status.increment();
    }
    public int getStatus() {
        return status.intValue();
    }
}

class DownloadTaskFileAO implements Runnable{
    private final DownloadStatusAO dstat;
    public DownloadTaskFileAO(DownloadStatusAO dstat) {
        this.dstat = dstat;
    }
    @Override
    public void run() {
        for(int i=0;i<10_000;i++){
            dstat.incrementStatus();
        }
    }
}
