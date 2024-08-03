package com.class_package.Threads;

public class ThreadSignalling1 {
    public static void main(String[] args){
        var dstat = new DownloadStatusSI();

        var thread1 = new Thread(new DownloadTaskFileSI(dstat));
        var thread2 = new Thread(()->{
            synchronized (dstat){
                while(!dstat.getisDone()){
                    try {
                        dstat.wait();
                    } catch (InterruptedException e) {
                        throw new RuntimeException(e);
                    }
                }
                System.out.println("Thread ended");
            }
        });

        thread1.start();
        thread2.start();
    }
}

class DownloadStatusSI{
    private volatile boolean isDone;
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

class DownloadTaskFileSI implements Runnable{
    private DownloadStatusSI dstat;

    public DownloadTaskFileSI(DownloadStatusSI dstat) {
        this.dstat = dstat;
    }
    @Override
    public void run() {
        dstat.falseisDone();
        for(int i=0;i<1_000_000;i++){
            if(Thread.currentThread().isInterrupted()) return;
        }
        synchronized (dstat){
            dstat.trueisDone(); // Set the status to done
            dstat.notifyAll(); // Notify waiting threads
        }
        System.out.println("Done status : "+dstat.getisDone());
    }
}
