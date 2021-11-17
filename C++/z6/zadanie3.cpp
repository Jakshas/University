#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

auto znajdz(vector<int>& x)
{
    unordered_map<int, int> liczniki;
    for (auto i : x)
    {
        ++liczniki[i];
    }
    vector<pair<int, int>> wynik;
    vector<pair<int, int>> pom;
    for(auto const& [key, value] : liczniki)
    {
        pom.push_back(make_pair(key, value));
    }
    sort(pom.begin(), pom.end(), [] (pair<int, int>& a, pair<int, int>& b) {return a.second < b.second; });
    int &counter = pom[pom.size() - 1].second; 
    for_each(pom.rbegin(), pom.rend(), [&] (pair<int, int> a) {
        if(a.second == counter)
            wynik.push_back(a);
    });
    return wynik;
}

int main()
{
    vector<int> test =  {1, 1, 3, 5, 8, 9, 5, 8, 8, 5};
    for(auto x : znajdz(test))
    {
        cout << "{" << x.first << "," << x.second << "}" << endl;
    }
}