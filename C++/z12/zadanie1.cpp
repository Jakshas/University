#include <iostream>       
#include <thread>         
#include <chrono>
#include <random>

using namespace std;

random_device rn;
mt19937 gen( rn());
uniform_int_distribution<> dist(500,1000);


void f(int i){
        while (true)
        {
            int r = dist(gen);
            this_thread::sleep_for (chrono::milliseconds(r));
            cout<<i<<endl;
        }
}

int main() 
{
    thread f1 {f,1};
    thread f2 {f,2};
    thread f3 {f,3};
    this_thread::sleep_for(chrono::seconds(60));
    f1.~thread();
    f2.~thread();
    f3.~thread();
    return 0;
}