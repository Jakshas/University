#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <string>
#include <random>

using namespace std;

class Que {
public:
    int** tab;
    int n;
    Que(int n) {
        this->n = n;
        tab = new int* [n];
        for (int i = 0; i < n; ++i)
            tab[i] = new int[2];
    }
    int* operator[](int i) {
        return tab[i];
    }
    int* smallest() {
        int minval = INT32_MAX, minw = -1;
        for (int i = 0; i < n; i++)
        {
            if (tab[i][1] == 0 && tab[i][0] < minval)
            {
                minval = tab[i][0];
                minw = i;
            }
        }
        return new int[2]{ minval,minw };
    }
    bool empty() {
        for (int i = 0; i < n; i++)
        {
            if (tab[i][1] == 0)
            {
                return false;
            }
        }
        return true;
    }
};

class GrafM {
public:
    int n;
    int** tab;
    GrafM(int n) {
        this->n = n;
        tab = new int* [n];
        for (int i = 0; i < n; ++i)
            tab[i] = new int[n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                tab[i][j] = -1;
    }
    int* operator[](int i) {
        return tab[i];
    }
};

class GrafL {
public:
    int n;
    vector<vector<pair<int, int>>> tab;
    GrafL(int n) {
        tab = vector<vector<pair<int, int>>>(n);
        this->n = n;
    }
    vector<pair<int, int>>* operator[](int i) {
        return &tab[i];
    }
};

int findin(Que que, int v) {
    for (int i = 0; i < que.n; i++)
    {
        if (i == v && que[i][1] != 1)
        {
            return que[i][0];
        }
    }
    return -1;
}

int findin(vector<pair<int, int>>* que, int v) {
    for (int i = 0; i < que->size(); i++)
    {
        if (que[0][i].second == v)
        {
            return que[0][i].first;
        }
    }
    return -1;
}

void setin(Que que, int v, int n) {
    for (int i = 0; i < que.n; i++)
    {
        if (i == v)
        {
            que[i][0] = n;
            return;
        }
    }
}


string djikstra(GrafM G, int v, int k) {
    int* p = new int[G.n];
    Que que = Que(G.n);
    for (int i = 0; i < G.n; i++)
    {
        p[i] = -1;
        que[i][0] = INT32_MAX;
        que[i][1] = 0;
    }
    for (int i = 0; i < G.n; i++)
    {
        if (que[i][1] == v)
        {
            que[i][0] = 0;
            break;
        }
    }
    while (!que.empty())
    {
        int* u = que.smallest();
        que[u[1]][1] = 1;
        for (int i = 0; i < G.n; i++)
        {
            if (G[u[1]][i] != -1)
            {
                int c = findin(que, i);
                if (c == -1)
                {
                    if (c > u[0] + G[u[1]][i])
                    {
                        setin(que, i, u[0] + G[u[1]][i]);
                        p[i] = u[1];
                    }
                }

            }

        }

    }
    string s;
    if (p[k] != -1)
    {
        while (k != v)
        {
            s = s + to_string(k) + " ";
            k = p[k];
        }
    }
    return s;

}

string djikstra(GrafL G, int v, int k) {
    int* p = new int[G.n];
    Que que = Que(G.n);
    for (int i = 0; i < G.n; i++)
    {
        p[i] = -1;
        que[i][0] = INT32_MAX;
        que[i][1] = 0;
    }
    for (int i = 0; i < G.n; i++)
    {
        if (que[i][1] == v)
        {
            que[i][0] = 0;
            break;
        }
    }
    while (!que.empty())
    {
        int* u = que.smallest();
        que[u[1]][1] = 1;
        for (int i = 0; i < G.n; i++)
        {
            int g = findin(que, i);
            if (g != -1)
            {
                int c = findin(G[u[1]], i);
                if (c != -1)
                {
                    if (g > u[0] + c)
                    {
                        setin(que, i, u[0] + c);
                        p[i] = u[1];
                    }
                }
            }
        }
    }
    cout << que.tab[v][0] << endl ;
    string s;
    if (p[k] != -1)
    {
        while (k != v)
        {
            s = s + to_string(k) + " ";
            k = p[k];
        }
    }
    s = s + to_string(k);
    return s;
}

GrafL losujL(int n, double p) {
    int** h = new int* [n];
    for (int i = 0; i < n; ++i)
        h[i] = new int[n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            h[i][j] = 0;
    double kr = p * n * (n - 1) / 2;
    GrafL g = GrafL(n);
    for (int i = 0; i < kr; i++)
    {
        default_random_engine generator;
        uniform_int_distribution<int> distribution(0, n - 1);
        int dice_roll1 = distribution(generator);
        int dice_roll2 = distribution(generator);
        while (dice_roll1 == dice_roll2 || h[dice_roll1][dice_roll2] != 0)
        {
            dice_roll1 = distribution(generator);
            dice_roll2 = distribution(generator);
        }
        h[dice_roll1][dice_roll2] = 1;
        h[dice_roll2][dice_roll1] = 1;
        int val=distribution(generator);
        pair<int, int> p = pair<int, int>(val, dice_roll2);
        vector<pair<int, int>>* v = g[dice_roll1];
        (*v).push_back(p);
        v = g[dice_roll2];
        p = pair<int, int>(val, dice_roll1);
        (*v).push_back(p);
    }
    return g;
}
GrafM losujM(int n, double p) {
    int** h = new int* [n];
    for (int i = 0; i < n; ++i)
        h[i] = new int[n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            h[i][j] = 0;
    double kr = p * n * (n - 1) / 2;
    GrafM g = GrafM(n);
    for (int i = 0; i < kr; i++)
    {
        default_random_engine generator;
        uniform_int_distribution<int> distribution(0, n - 1);
        int dice_roll1 = distribution(generator);
        int dice_roll2 = distribution(generator);
        while (dice_roll1 == dice_roll2 || h[dice_roll1][dice_roll2] != 0)
        {
            dice_roll1 = distribution(generator);
            dice_roll2 = distribution(generator);
        }
        int val=distribution(generator);
        h[dice_roll1][dice_roll2] = 1;
        h[dice_roll2][dice_roll1] = 1;
        g[dice_roll1][dice_roll2] = val;
        g[dice_roll2][dice_roll1] = val;
    }
    return g;
}

int main(int argc, char const* argv[])
{
    GrafL g = losujL(10, 1);
    cout << djikstra(g, 0, 2);
    return 0;
}
