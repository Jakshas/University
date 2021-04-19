#include <iostream>
#include <random>

using namespace std;

void pushup(int* heap, int i) {
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
    bool stop = true;
    while ((i * 2) + 1 <= n && stop)
    {
        if (heap[i * 2] > heap[(i * 2) + 1])
        {
            if (heap[(i * 2) + 1] < heap[i])
            {
                int pom = heap[i];
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
            if (heap[i * 2] < heap[i])
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
    if (i * 2 <= n && heap[i * 2] < heap[i])
    {
        int pom = heap[i];
        heap[i] = heap[i * 2];
        heap[i * 2] = pom;
    }

}

int heappop(int* heap, int n) {
    int x = heap[1];
    heap[1] = heap[n];
    heap[n] = x;
    heapdown(heap, n - 1);
    return x;
}

void heapsort(int* tab, int n) {
    int* heap = new int[n];
    for (int i = 1; i <= n; i++)
    {
        heap[i] = tab[i - 1];
        pushup(heap, i);
    }
    int nh = n;
    for (int i = 0; i < n; i++)
    {
        tab[i] = heappop(heap, nh);
        nh = nh - 1;
    }
}

int main(int argc, char const* argv[])
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 10);
    int* tab = new int[10];
    for (int n = 0; n < 10; ++n) {
        tab[n] = dis(gen);
    }
    heapsort(tab, 10);
    for (int n = 0; n < 10; n++) {
        cout << tab[n] << " ";
    }
    return 0;
}


