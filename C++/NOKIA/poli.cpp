#include <iostream>

using namespace std;

class A{
    public:
        virtual void f()=0;
};
class B : public A{
    public:
        void f() override {
            cout<< "b";
        }
};
class C : public A{
    public:
        void f() override {
            cout<< "c";
        }
};

int main(int argc, char const *argv[])
{
    A *b = new B();
    A *c = new C();
    b->f();
    c->f();
    return 0;
}
