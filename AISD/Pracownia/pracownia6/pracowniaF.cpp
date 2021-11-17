#include <stdio.h>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

class Nic
{
public:
    int poczatek;
    int koniec;
    long grubosc;
    Nic(int poczatek, int koniec, long grubosc) {
        this->poczatek = poczatek;
        this->koniec = koniec;
        this->grubosc = grubosc;
    }
    bool operator>(Nic b){
        return this->grubosc > b.grubosc;
    }
};

int Find(vector<pair<int,int>> &tab, int x)
{
    if (tab[x].first != -1){
        tab[x].first = Find(tab, tab[x].first);
        return tab[x].first;
    }
    return x;
}
int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d %d",&n,&m);
    vector<pair<int,int>> tab(n + 1,pair<int,int>(-1,0));
    
    vector<Nic> siec;
    siec.reserve(m+1);
    for (int i = 0; i < m; i++)
    {
        int a,b;
        long w;
        scanf("%d %d %ld", &a,&b,&w);
        siec.push_back(move(Nic(a,b,w)));
    }
    
    sort(siec.begin(), siec.end(), [](Nic a, Nic b){ return a > b;});

    long thicc = 0;
    for (int i = 0; i < m; i++)
    {
        int a = Find(tab, siec[i].poczatek);
        int b = Find(tab, siec[i].koniec);
        if (a != b)
        {            
            if (tab[a].second < tab[b].second)
            {
                int temp = a;
                a = b;
                b = temp;
            }
            thicc = siec[i].grubosc;
            tab[b].first = a;
            tab[a].second++;
        }
    }
    printf("%ld",thicc);

    return 0;
}
