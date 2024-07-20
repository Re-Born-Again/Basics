package com.class_package;

import com.sun.jdi.ArrayReference;

import java.util.ArrayList;
import java.util.Iterator;

public class GenericList<T> implements Iterable<T> {
    private T[] arr = (T[]) new Object[10];
    private int idx = 0;

    public void add(T val){
        arr[idx++] = val;
    }

    public T get(int i){
        return arr[i];
    }

    @Override
    public Iterator<T> iterator() {
        return new ListIterator(this);
    }

    class ListIterator<T> implements Iterator{
        private GenericList<T> list;
        private int count = 0;
        ListIterator(GenericList<T> list){
            this.list = list;
        }

        @Override
        public boolean hasNext() {
            return (count<idx);
        }

        @Override
        public Object next() {
            return (arr[count++]);
        }
    }
}
