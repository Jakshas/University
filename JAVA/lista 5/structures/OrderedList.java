package structures;

import java.util.Iterator;

public class OrderedList<T extends Comparable<T>> implements OrderedSequence<T>, Iterable<T> {
    class Node<T extends Comparable<T>> {
        private Node<T> next;
        private T data;

        Node(T el) {
            this.data = el;
            this.next = null;
        }

        Node(T el, Node<T> next) {
            this.data = el;
            this.next = next;
        }
    }

    private Node<T> start;

    public OrderedList() {
        this.start = null;
    }

    @Override
    public String toString() {
        Node<T> pom = this.start;
        String s = "";
        while (pom != null) {
            s = s + " " + pom.data;
            pom = pom.next;
        }
        return s;
    }

    @Override
    public void insert(T el) {
        if (el == null) {
            throw new NullPointerException();
        }
        if (start == null) {
            start = new Node<T>(el);
        } else {
            if (start.data.compareTo(el) > 0) {
                start = new Node<T>(el, start);
            } else {
                Node<T> pom = this.start;
                Node<T> pop = pom;
                while (pom != null && el.compareTo(pom.data) >= 0) {
                    pop = pom;
                    pom = pom.next;
                }
                pop.next = new Node<T>(el, pom);
            }
        }
    }

    @Override
    public void remove(T el) {
        if (el == null) {
            throw new NullPointerException();
        }
        if (start.data.compareTo(el) == 0) {
            start = start.next;
        }
        Node<T> pom = this.start;
        Node<T> pop = pom;
        while (pom != null && el.compareTo(pom.data) != 0) {
            pop = pom;
            pom = pom.next;
        }
        if (pom == null) {

        } else {
            pop.next = pom.next;
        }
    }

    @Override
    public T min() {
        return start.data;
    }

    @Override
    public T max() {
        Node<T> pom = this.start;
        while (pom.next != null) {
            pom = pom.next;
        }
        return pom.data;
    }

    @Override
    public T at(int pos) throws Exception {
        if (pos < 0) {
            throw new Exception("zła wartosc");
        }
        Node<T> pom = this.start;
        for (int i = 0; i < pos && pom != null; i++) {
            pom = pom.next;
        }
        if (pom == null) {
            throw new Exception();
        }
        return pom.data;
    }

    @Override
    public boolean search(T el) {
        if (el == null) {
            throw new NullPointerException();
        }
        Node<T> pom = this.start;
        while (pom.next != null && pom.data.compareTo(el) != 0) {
            pom = pom.next;
        }
        if (pom.data.compareTo(el) == 0) {
            return true;
        } else {
            return false;
        }
    }

    @Override
    public int index(T el) {
        if (el == null) {
            throw new NullPointerException();
        }
        int i = 0;
        Node<T> pom = this.start;
        while (pom.next != null && pom.data.compareTo(el) != 0) {
            pom = pom.next;
            i++;
        }
        if (pom.data.compareTo(el) == 0) {
            return i;
        } else {
            return -1;
        }
    }

    /**
     * Itt
     */
    class Itt implements Iterator<T>{
        
        Node<T> current;
        Node<T> previous;
        public Itt(OrderedList<T> orderedList) 
        {
            current=orderedList.start;
        }

        @Override
        public boolean hasNext() {
            return current != null;
        }

        @Override
        public T next() {
            T data=current.data;
            previous=current;
            current=current.next;
            return data;
        }
        
        @Override
        public void remove() {
            OrderedList.this.remove(previous.data);
        }
        
    }

    @Override
    public Iterator<T> iterator() {
        return new Itt(this);
    }
}