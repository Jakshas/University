#include <iostream>
#include <vector>
#include <utility>  
#include <algorithm>

using namespace std;


long long int find(vector<pair<long long int,long long int>> &vt, long long int szukana, long long int poczatek, long long int koniec){
    if(poczatek>koniec) {
        return -1;
    }else{
        long long int s = (poczatek + koniec)/2;
        if (vt[s].first > szukana)
            return find(vt , szukana ,poczatek,s - 1);
        if (vt[s].first < szukana)
            return find(vt , szukana ,s + 1,koniec);
        return s;
    }
}

int main(int argc, char const *argv[])
{
    long long int x;
    long long int wynik = 0;
    scanf("%lld",&x);
    vector<pair<long long int,long long int>> vt;
    for (int i = 0; i < x; i++)
    {
        long long int a,b;
        scanf("%lld %lld",&a , &b);
        vt.push_back(pair<long long int,long long int>(a,b));
    }
    sort(vt.begin(),vt.end());
    for (long long int i = 0; i < x; i++)
    {
        if (vt[i].second == 1)
        {
            wynik++;
        }else{
            while (vt[i].second>0)
            {
            if (vt[i].second%2 == 1)
                {
                    wynik += 1;
                    vt[i].second -= 1;
                }
            if (vt[i].second>0)
                {
                vt[i].first *= 2;
                vt[i].second /= 2;
                long long int pom = find(vt, vt[i].first ,i+1,x-1);
                if (pom != -1)
                    {
                        vt[pom].second += vt[i].second;
                        vt[i].second = 0;
                    }
                }
            }
        }
    }
    printf("%d",wynik);
    return 0;
}
