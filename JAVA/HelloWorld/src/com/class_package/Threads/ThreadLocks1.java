package com.class_package.Threads;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

// one of the strategy for thread safety
// Locks -> used for synchronizing threads
public class ThreadLocks1 {
    public static void main(String[] args){

        List<Thread> threadList = new ArrayList<>();
        var dstat = new DownloadStatusL();

        for(int i=0;i<10;i++){
            Thread thread = new Thread(new DownloadTaskFileL(dstat));
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

class DownloadStatusL{
    private int status;
    private Lock lock = new ReentrantLock();
    public void incrementStatus(){
        lock.lock();
        try{ // if exception occurred then finally block and rest of the code gets executed
            // else try, finally, rest of the code gets executed
            status++;
        }
        finally{
            lock.unlock();
        }
    }
    public int getStatus() {
        return status;
    }
}

class DownloadTaskFileL implements Runnable{
    private final DownloadStatusL dstat;
    public DownloadTaskFileL(DownloadStatusL dstat) {
        this.dstat = dstat;
    }
    @Override
    public void run() {
        for(int i=0;i<10_000;i++){
            dstat.incrementStatus();
        }
    }
}
