package structures;

public interface OrderedSequence <T extends Comparable<T>> {

    void insert(T el);
    void remove(T el);
    T min();
    T max();
    T at(int pos) throws Exception;
    boolean search(T el);
    int index(T el);
}