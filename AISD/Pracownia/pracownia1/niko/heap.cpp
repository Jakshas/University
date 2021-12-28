#include <iostream>
#include "heap.h"

using namespace std;

void pushup(int* heap, int i) { //by nie bylo elementu pod ktory jest wiekszy
    while (heap[i / 2] > heap[i] && i != 1) 
    {
        int pom = heap[i];
        heap[i] = heap[i / 2];
        heap[i / 2] = pom;
        i = i / 2;
    }
}

void heapdown(int* heap, int n) {
    int i = 1;
    bool stop = true; //dla warunkow wyjscia
    while ((i * 2) + 1 <= n && stop) // dopoki jest kopiec
    {
        if (heap[i * 2] > heap[(i * 2) + 1]) //ktore dziecko mniejsze
        {
            if (heap[(i * 2) + 1] < heap[i]) //czy dziecko jest mniesze od elementu przesuwanego
            {
                int pom = heap[i]; //zamiana 
                heap[i] = heap[(i * 2) + 1];
                heap[(i * 2) + 1] = pom;
                i = (i * 2) + 1;
            }
            else
            {
                stop = false;
            }

        }
        else
        {
            if (heap[i * 2] < heap[i]) //czy dziecko mniejsze od elementu przesuwanego
            {
                int pom = heap[i];
                heap[i] = heap[i * 2];
                heap[i * 2] = pom;
                i = i * 2;
            }
            else
            {
                stop = false;
            }
        }
    }
    if (i * 2 <= n && heap[i * 2] < heap[i]) // gdy dziecko to jedynak
    {
        int pom = heap[i];
        heap[i] = heap[i * 2];
        heap[i * 2] = pom;
    }

}

int heappop(int* heap, int n) {
    int x = heap[1]; //zamiana wartosci z ostatnim elementem
    heap[1] = heap[n];
    heap[n] = x; 
    heapdown(heap, n - 1); //zeby za pierwsyzm elementem nie bylo mniesjzych
    return x;
}

void heapsort(int* tab, int n) { //tablica i rozmiar
    int* heap = new int[n]; //kopia orginalu
    for (int i = 1; i <= n; i++)
    {
        heap[i] = tab[i - 1]; //zapelnienie kopi
        pushup(heap, i); //do kopca
    }

    int newheap = n; //rozmiar kopca
    for (int i = 0; i < n; i++)
    {
        tab[i] = heappop(heap, newheap); //wyciagniecie
        newheap = newheap - 1; // zmniejszamy kopiec
    }
    delete[] heap;
}
