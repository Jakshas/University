public class Mergesort implements Runnable {
    int tablica[];
    int l, r;

    public void merge() {
        int m = (l + r) / 2;
        int n1 = m - l + 1;
        int n2 = r - m;
        int L[] = new int[n1];
        int R[] = new int[n2];
        for (int i = 0; i < n1; ++i)
            L[i] = tablica[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = tablica[m + 1 + j];
        int i = 0, j = 0;
        int k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                tablica[k] = L[i];
                i++;
            } else {
                tablica[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            tablica[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            tablica[k] = R[j];
            j++;
            k++;
        }
    }

    public void run() {
        if (l < r) {
            int m = (l + r) / 2;
            Mergesort rr = new Mergesort(tablica, l, m);
            Thread rt = new Thread(rr);
            rt.start();
            Mergesort ll = new Mergesort(tablica, m + 1, r);
            Thread lt = new Thread(ll);
            lt.start();
            try {
                lt.join();
                rt.join();
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
            merge();
        }
    }

    public Mergesort(int tablica[], int l, int r) {
        this.tablica = tablica;
        this.l = l;
        this.r = r;
    }

    public static void main(String[] args) throws InterruptedException {
        int tablica[] = { 2, 4, 1, 9, 4, 3, 4, 12, 2 };
        Mergesort tabl = new Mergesort(tablica, 0, tablica.length - 1);
        Thread tab = new Thread(tabl);
            tab.start();
            tab.join();
        for(int i=0;i<9;i++){
            System.out.println(tabl.tablica[i]);
        }
    }
}