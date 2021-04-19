#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <string>
#include <random>

using namespace std;

class GrafM{
    public:
        int n;
        int **tab;
        GrafM(int n){
            this->n = n;
            tab = new int*[n];
            for(int i = 0; i < n; ++i)
                tab[i] = new int[n];
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    tab[i][j]=-1;
        }
        int* operator[](int i){
            return tab[i];
        }
};

class GrafL{
    public:
        int n;
        vector<pair<int,int>> *tab[];
        GrafL(int n){
            for(int i = 0; i < n; ++i)
                tab[i] = new vector<pair<int,int>>[];
        }
        vector<pair<int,int>>* operator[](int i){
            return tab[i];
        }
};

int findin(vector<pair<int,int>> que, int v){
    for (int i = 0; i < que.size(); i++)
    {
        if (que[i].second == v)
        {
            return que[i].first;
        }
    }
    return -1;
}

int findin(vector<pair<int,int>> *que, int v){
    for (int i = 0; i < que->size(); i++)
    {
        if (que[0][i].second == v)
        {
            return que[0][i].first;
        }
    }
    return -1;
}

void setin(vector<pair<int,int>> que, int v,int n){
    for (int i = 0; i < que.size(); i++)
    {
        if (que[i].second == v)
        {
            que[i].first = n;
            return;
        }
    }
}


void djikstra(GrafM G, int v, int k){
    int *p = new int[G.n];
    vector<pair<int,int>> que;
    for (int i = 0; i < G.n; i++)
    {
        p[i]=-1;
        que.push_back(pair<int,int>(INT32_MAX,i));
        push_heap(que.begin(),que.end());
    }
    for (int i = 0; i < G.n; i++)
    {
        if (que[i].second == v)
        {
            que[i].first = 0;
            break;
        }
    }
    make_heap(que.begin(),que.end());
    while (!que.empty())
    {
        int u = que.front().second;
        int val = que.front().first;
        pop_heap(que.begin(),que.end());
        for (int i = 0; i < G.n; i++)
        {
            if (G[u][i] != -1)
            {
                int c = findin(que,i);
                if (c == -1)
                {
                    if (c > val + G[u][i])
                    {
                        setin(que,i,val + G[u][i]);
                        p[i] = u;
                    }
                }

            }
            
        }
        
    }
    if (p[k] != -1)
    {
        string s;
        while (k != v)
        {
            s=s+to_string(k)+" ";
            k = p[k];
        }
    }
    

}

void djikstra(GrafL G, int v, int k){
    int *p = new int[G.n];
    vector<pair<int,int>> que;
    for (int i = 0; i < G.n; i++)
    {
        p[i]=-1;
        que.push_back(pair<int,int>(INT32_MAX,i));
        push_heap(que.begin(),que.end());
    }
    for (int i = 0; i < G.n; i++)
    {
        if (que[i].second == v)
        {
            que[i].first = 0;
            break;
        }
    }
    make_heap(que.begin(),que.end());
    while (!que.empty())
    {
        int u = que.front().second;
        int val = que.front().first;
        pop_heap(que.begin(),que.end());
        for (int i = 0; i < G.n; i++)
        {
            int g = findin(que,i);
            if (g != -1)
            {
                int c = findin(que,i);
                if (c == -1)
                {
                    if (c > val + g)
                    {
                        setin(que,i,val + g);
                        p[i] = u;
                    }
                }

            }
            
        }
        
    }
    if (p[k] != -1)
    {
        string s;
        while (k != v)
        {
            s=s+to_string(k)+" ";
            k = p[k];
        }
    }
}

GrafL* losuj(int n, double p){
    int **h = new int*[n];
    for(int i = 0; i < n; ++i)
        h[i] = new int[n];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            h[i][j]=0;
    double kr = p*n*(n-1)/2;
    for (int i = 0; i < kr; i++)
    {
        default_random_engine generator;
        uniform_int_distribution<int> distribution(0,n);
        int dice_roll1 = distribution(generator);
        int dice_roll2 = distribution(generator);
        while (dice_roll1 != dice_roll2 || h[dice_roll1][dice_roll2] != 0)
        {
            dice_roll1 = distribution(generator);
            dice_roll2 = distribution(generator);
        }
        GrafL *g= new GrafL(n);
        g[0][dice_roll1]->push_back(pair<int, int>(distribution(generator),dice_roll2));
    }
    
} 

int main(int argc, char const *argv[])
{
    
    return 0;
}
