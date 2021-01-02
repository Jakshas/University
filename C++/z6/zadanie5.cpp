#include<string>
#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
    string test = "test"; 
    sort(test.begin(), test.end());
    do{
        cout << test << endl;
    }while(next_permutation(test.begin(), test.end()));
}