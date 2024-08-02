package com.class_package.Threads;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

// one of the strategy for thread safety
// Synchronize keyword -> performs activity same as lock but with some limitations
public class ThreadSynchronizedKeyword1 {
    public static void main(String[] args){

        var dstat = new DownloadStatusS();
        for(int i=0;i<10;i++){
            Thread thread = new Thread(new DownloadTaskFileS(dstat));
            thread.start();
        }

        System.out.println(dstat.getStatus());
    }
}

class DownloadStatusS{
    private int status;
    private int status2;
    private Object statusLock = new Object();
    private Object statusLock2 = new Object();
    // 2 objects are created coz synchronize() will take an object as parameter to keep a lock
    // if 2 objects are not created instead "this" keyword is given then it is similar to having a same lock for status and status2 which leads to too much wait time

    public void incrementStatus(){
        synchronized (statusLock) {
            status++;
        }
    }
    public synchronized void incrementStatus2(){
        // using synchronized keyword here is same as
        // synchronize(this){status2++;}
        status2++;
    }
    public int getStatus() {
        return status;
    }

    public int getStatus2() {
        return status2;
    }
}

class DownloadTaskFileS implements Runnable{
    private final DownloadStatusS dstat;
    public DownloadTaskFileS(DownloadStatusS dstat) {
        this.dstat = dstat;
    }
    @Override
    public void run() {
        for(int i=0;i<10_000;i++){
            dstat.incrementStatus();
        }
    }
}