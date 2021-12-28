#include<string>
#include<iostream>
#include<algorithm>
#include <random>

using namespace std;

    
thread_local mt19937 gen{random_device{}()};
 
template<typename T>
T random(T min, T max) {
    return std::uniform_int_distribution<T>{min, max}(gen);
}
void perm(string inp, int i)
{
    sort(inp.begin(), inp.end());
    int j=0;
    do{
        if(j==i){
            cout<<inp<<endl;
        }
         j++;
    }while(next_permutation(inp.begin(), inp.end()));
}

int silnia(int n){
    int silnia=1;
    for(int i=n;i>1;i--)
		silnia*=i;
return silnia;
}

int main()
{
    string test = "test"; 

    perm(test,random(0,12));
}