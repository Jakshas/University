#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <random>
#include <chrono>

using namespace std;

random_device rd;
mt19937 gen( rd() );
uniform_int_distribution<> dist(30, 200);

condition_variable c_cv;
condition_variable p_cv;
mutex mut;

unsigned int ile=0;
unsigned int pojemnosc=10;

void cons_thread()
{
    while(true)
    {
        unique_lock<mutex> lockk(mut);

        if( ile != 0)
        {
            ile=ile-1;
            cout << "Zabrano zostało " << ile << '\n';
            p_cv.notify_all();
        }
        else
        {
            c_cv.wait(lockk, [&] () { return ile != 0; });
            ile=ile-1;
            cout << "Zabrano zostało " << ile << '\n';
            p_cv.notify_all();
        }
        auto time = dist(gen);
        lockk.unlock();
        this_thread::sleep_for( chrono::milliseconds( time ) );
    }
}

void prod_thread()
{
    while(true)
    {
        unique_lock<mutex> lockk(mut);

        if( ile != pojemnosc )
        {
            ile = ile + 1;
            cout << "Dodano jest " << ile << '\n';
            c_cv.notify_all();
        }
        else
        {
            p_cv.wait(lockk, [&] () { return ile != 0; });
        }

        lockk.unlock();
        this_thread::sleep_for( chrono::milliseconds( dist(gen) ) );
    }
}

int main()
{
    thread consumer(cons_thread);
    thread producer(prod_thread);

    consumer.join();
    producer.join();    
}