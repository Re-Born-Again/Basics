package com.class_package.Threads;

// one of the strategy for thread safety
// Volatile keyword -> doesn't solve race condition but solves visibility problem ie. every thread can see the changes by others
public class ThreadVolatileKeyword1 {
    public static void main(String[] args){
        var dstat = new DownloadStatusV();
        Thread thread1 = new Thread(new DownloadTaskFileV(dstat));
        thread1.start();
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
        dstat.trueisDone();
        System.out.println("isDone turned to true");
    }
}

class DownloadStatusV{
    private volatile boolean isDone; // volatile keyword is given to the variable which is shared among threads

    public boolean getisDone() {
        return isDone;
    }
    public void trueisDone(){
        isDone = true;
    }
    public void falseisDone(){
        isDone = false;
    }
}

class DownloadTaskFileV implements Runnable{
    private DownloadStatusV dstat;

    public DownloadTaskFileV(DownloadStatusV dstat) {
        this.dstat = dstat;
    }
    @Override
    public void run() {
        dstat.falseisDone();
        while(!dstat.getisDone()){}
    }
}