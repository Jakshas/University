#include <string>

using namespace std;

string towers(int* a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    int limit = sum + 1;
    int *tab1 = new int[limit];
    int *tab2 = new int[limit];
    for (int i = 0; i < limit; i++)
    {
        tab1[i] = -1;
        tab2[i] = -1;
    }
    tab1[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < limit; j++) {
            if (tab1[j] != -1)
            {
                int bigger = tab1[j];
                int smaller = tab1[j] - j;
                int newbigger = bigger + a[i - 1];
                int newsmaller = smaller + a[i - 1];
                tab2[newbigger - smaller] = max(newbigger, tab2[newbigger - smaller]);
                tab2[abs(newsmaller - bigger)] = max(max(newsmaller, bigger), tab2[abs(newsmaller - bigger)]);
                tab2[j] = max(tab2[j], tab1[j]);
            }
        }
        delete[] tab1;
        tab1 = move(tab2);
        tab2 = new int[limit];
        for (int i = 0; i < limit; i++)
        {
            tab2[i] = -1;
        }
    }

    int ans = tab1[0];
    delete[] tab2;

    if (ans > 0) {
        delete[] tab1;
        return "TAK\n" + to_string(ans);
    }
    else {
        int l;
        for (int i = 1; i < sum; i++) {
            l = tab1[i];
            if (l != -1 && l != 0 && i != l) {
                delete[] tab1;
                return "NIE\n" + to_string(i);
            }
        }
    }
    return "";
}


int main() {
    int n, temp;
    scanf("%d", &n);
    int *inp = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        inp[i] = temp;
    }
    printf("%s",towers(inp, n).c_str());
    delete[] inp;
}