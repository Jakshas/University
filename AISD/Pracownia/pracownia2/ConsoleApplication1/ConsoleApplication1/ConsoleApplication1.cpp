// CPP implementation for the above mentioned
// Dynamic Programming  approach

#include <limits.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to find the maximum subset sum
string maxSum(vector<int>& a, int n) {
    // sum of all elements
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];

    int limit = sum + 1;
    // bottom up lookup table;
    int** tab = new int* [2];
    tab[0] = new int[limit];
    tab[1] = new int[limit];

    // initialising tab table with INT_MIN
    // where, INT_MIN means no solution
    fill_n(tab[0], limit, -1);
    fill_n(tab[1], limit, -1);

    // Case when diff is 0
    tab[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < limit; j++) {
            if (tab[0][j] != -1)
            {
                int bigger = tab[0][j];
                int smaller = tab[0][j] - j;
                int newbigger = bigger + a[i - 1];
                int newsmaller = smaller + a[i - 1];
                tab[1][newbigger - smaller] = max(newbigger, tab[1][newbigger - smaller]);
                tab[1][abs(newsmaller - bigger)] = max(max(newsmaller, bigger), tab[1][abs(newsmaller - bigger)]);
                tab[1][j] = max(tab[1][j], tab[0][j]);

            }
        }
        for (int i = 0; i < limit; i++)
        {
            cout << tab[1][i] << " ";
        }
        cout << "\n";
        delete[] tab[0];
        tab[0] = move(tab[1]);
        tab[1] = new int[limit];
        fill_n(tab[1], limit, -1);
    }
    for (int i = 0; i < limit; i++)
    {
        cout << tab[0][i] << " ";
    }

    int res = tab[0][0];
    delete[] tab[1];

    if (res > 0) {
        delete[] tab[0];
        delete[] tab;
        return "TAK\n" + to_string(res);
    }
    else {
        int l;
        for (int i = 1; i < sum; i++) {
            l = tab[0][i];
            if (l != -1 && (l != 0 || i != l)) {
                delete[] tab[0];
                delete[] tab;
                return "NIE\n" + to_string(i);
            }
        }
    }
    return "";
}

// Driver code

int main() {
    ios_base::sync_with_stdio(false);
    int n, temp;
    vector<int> inp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        inp.push_back(temp);
    }
    cout << maxSum(inp, n) << endl;
    //return 0;
}