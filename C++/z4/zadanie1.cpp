#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

template<typename T,int min,int max>
void printa(T el){   
    if(el>min && el<max){
        cout<<el<<" ";
    }
}
template<typename T>
class Printb
{
private:
   int p, k, i = 0;
public:
    Printb(int a, int b): p(a), k(b) {}
        void operator () (const T& x) {
        if(p > 0) {
            p--;
            return;
        }
        i++;
        if(i % k == 0) 
            std::cout << x << " ";
    }
};



int main(int argc, char const *argv[])
{
    vector<double> v;
    list<string> l;
    set<int> s;
    for (int i=1; i<=10; ++i) {
        s.insert(i);
        }
    for (double i=1.0; i<=10.0; ++i) {
        v.push_back(i);
        }
    for (int i=1; i<=10; ++i) {
        l.push_back("string"+to_string(i));
        }
    for_each(v.cbegin(),v.cend(),printa<double,2, 6>);
        cout<<endl;
    for_each(l.cbegin(),l.cend(),[] (const string& el){
        if(el > "string2" && el < "string5"){
        cout<<el<<" ";
    }});
        cout<<endl;
    for_each(s.cbegin(),s.cend(),printa<int,2, 6>);
        cout<<endl;

    std::for_each(v.begin(), v.end(), Printb<double>(1,2));
    std::cout << std::endl;
    std::for_each(l.begin(), l.end(), Printb<std::string>(1,2));
    std::cout << std::endl;
    std::for_each(s.begin(), s.end(), Printb<int>(1,2));
    std::cout << std::endl;

    cout <<accumulate(v.cbegin(),v.cend(),0.0,[v] (double acc, const double elem) {
        return acc + (elem/v.size());
    }) <<endl;
        cout <<accumulate(s.cbegin(),s.cend(),0.0,[s] (double acc, const double elem) {
        return acc+(elem/s.size());
    }) <<endl;

    vector<double>::iterator itv=v.begin();
    pair<vector<double>::iterator, vector<double>::iterator> min_maxv(v.begin(), v.begin());
    for_each(v.begin(), v.end(), [&min_maxv,&itv] (const double& elem) {
        if(*min_maxv.first > elem)
            min_maxv.first = itv;
        if(*min_maxv.second < elem)
            min_maxv.second = itv;
        itv++;
    });
    cout << "v " << *min_maxv.first << " " << *min_maxv.second << endl;

    list<string>::iterator itl=l.begin();
    pair<list<string>::iterator, list<string>::iterator> min_maxl(l.begin(), l.begin());
    for_each(l.begin(), l.end(), [&min_maxl,&itl] (const string elem) {
        if(*min_maxl.first > elem)
            min_maxl.first = itl;
        if(*min_maxl.second < elem)
            min_maxl.second = itl;
        itl++;
    });
    cout << "l " << *min_maxl.first << " " << *min_maxl.second << endl;

    set<int>::iterator its=s.begin();
    pair<set<int>::iterator, set<int>::iterator> min_maxs(s.begin(), s.begin());
    for_each(s.begin(), s.end(), [&min_maxs,&its] (const int& elem) {
        if(*min_maxs.first > elem)
            min_maxs.first = its;
        if(*min_maxs.second < elem)
            min_maxs.second = its;
        its++;
    });
    cout << "s " << *min_maxs.first << " " << *min_maxs.second << endl;

    cout << "" << accumulate(v.begin(), v.end(), 0.0, [&] (double acc, const double& elem) {
        return acc + elem;
    }) << endl;

    string output;
    for_each(l.begin(), l.end(), [&output] (const string& elem) {
        output += elem;
    });
    cout << output << endl;

    cout << accumulate(s.begin(), s.end(), 0, [&] (int acc, const int& elem) {
        return acc + elem;
    }) << endl;
    return 0;
}
