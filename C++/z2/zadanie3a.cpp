#include <iostream>
#include <memory>
using namespace std;
int main(int argc, char const *argv[])
{
    shared_ptr<int> tab{new int(7)};
    tab;
    return 0;
}
