#include <iostream>
#include <vector>
#include <exception>
#include <cmath>
#include <stdint.h>
#include <utility>
#include <algorithm>
using namespace std;

struct node {
    node(int64_t n, int64_t c) : number(n), count(c) {}
    int64_t number;
    int64_t count;

    bool operator<(const node& a) const {
        return number < a.number;
    }
    bool operator>(const node& a) const {
        return number > a.number;
    }
    bool operator==(const node& a) const {
        return number == a.number && count == a.count;
    }
    friend ostream& operator<<(ostream& os, const node& a) {
        os << a.number << " and " << a.count;
        return os;
    }
};

template <typename T>
void quicksort(vector<T> &A, int64_t start, int64_t end) {
    if(start >= end) return;

    T pivot = A[(end + start) / 2];
    int64_t position = 0, i, j;
    swap(A[end], A[(end + start) / 2]);

    for(i = start; i < end; i++) {
        if(A[i] > pivot) {
            for(j = end - 1; j > i; j--) {
                if(A[j] < pivot) {
                    swap(A[i], A[j]);
                    break;
                }
            }
            if(j <= i) {
                swap(A[i], A[end]);
                position = i;
                break;
            }
        }
    }
    quicksort(A, start, position - 1);
    quicksort(A, position + 1, end);
}

template <typename T>
int64_t binary_search(const vector<T> &A, int64_t el, int64_t start, int64_t end) {
    if(end < start)
        return -1;

    int64_t mid = (end + start) / 2;
    node pivot = A[mid];
    if(el == pivot.number)
        return mid;
    else if(el > pivot.number)
        return binary_search(A, el, mid + 1, end);
    else
        return binary_search(A, el, start, mid - 1);
}

template <typename T>
void print(const vector<T> &A) {
    for(int i = 0; i < A.size(); i++) {
        cout << A[i] << endl;
    }
}

int64_t strings(vector<node> &A) {
    int64_t res = 0;
    for(int64_t i = 0; i < A.size(); i++) {
        if(A[i].count == 1) {
            res++;
            A[i].number = -1;
            A[i].count = -1;
            continue;
        }
        if(A[i].count & 1 == 1) {
            res++;
            A[i].count--;
        }

        int64_t number = A[i].number;
        while(A[i].count != 1) {
            if(A[i].count & 1 == 1) {
                A[i].count--;
                int64_t exists = binary_search(A, number, i, A.size() - 1);
                if(exists != -1)
                    A[exists].count++;
                else
                    res++;
            }
            else {
                A[i].count = A[i].count >> 1;
                number = number << 1;
                int64_t exists = binary_search(A, number, i, A.size() - 1);
                if(exists != -1) {
                    A[exists].count += A[i].count;
                    A[i].number = -1;
                    A[i].count = -1;
                    break;
                }
                else
                    if(A[i].count == 1)
                        res++;
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<node> input;
    int64_t n, nr, c;
    cin >> n;
    for(int64_t i = 0; i < n; i++) {
        cin >> nr;
        cin >> c;
        input.push_back(node(nr, c));
    }
    sort(input.begin(), input.end());
    // quicksort(input, 0, input.size() - 1);
    cout << strings(input);
}
