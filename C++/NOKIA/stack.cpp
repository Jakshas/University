#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;
template<typename T>
struct node
{
    T val;
    node* next;
};

template<typename T>
struct stack
{
    node<T>* first = nullptr;
    T pop(){
        if (first != nullptr)
        {
            node<T> * next = first->next;
            T val = first->val;
            delete first;
            first = next;
            return val;
        }
        throw invalid_argument("Stak pusty");
    }
    void push(T v){
        node<T> * f = new node<T>();
        f->val=v;
        f->next = first;
        first = f;
    }
};



int main(int argc, char const *argv[])
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    return 0;
}
