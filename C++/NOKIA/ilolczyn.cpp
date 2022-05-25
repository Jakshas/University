#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v = {1,2,3,-4,-5,-6,-7,8,9};
    int s = accumulate(v.begin(), v.end(), 1, [](int s, int v){
        if(v > 0){
            s *= v;
    }return s;
    });
    cout << s;

    int kuba = 0;
    auto x = [&]() {
        cout << kuba;
    };
    sort(v.begin(),v.end(),[](const int &a, const int &b){return a>b;});
    for_each(v.begin(),v.end(),[](int v){cout<<v;});

    return 0;
}

class gowno
{
private:
    int v;
public:
    gowno(int a);
    ~gowno();
    int operator+(gowno a);
};

gowno::gowno(int a)
{
    this->v = a;
}

gowno::~gowno()
{
}
int gowno::operator+(gowno a){
    return this->v + a.v;
}
