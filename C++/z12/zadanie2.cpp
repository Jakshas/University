#include <iostream>       
#include <thread>     
#include <chrono>         
 

  void f(int i){
    std::this_thread::sleep_for (std::chrono::seconds(i));
    std::cout << "program skonczy sie za "<< 10 - i << " s"<< std::endl;
  };

int main() 
{
    std::thread t1 {f , 10};
    std::thread t2 {f , 5};
    std::thread t3 {f , 7};
    std::thread t4 {f , 9};
    t1.join();
    return 0;
}