#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int32_t x=10, y=-2;
    int32_t p = x * ~y;
    uint32_t p2 = (uint32_t)y * (uint32_t)x;
    cout << (p + p2  == -x);
    return 0;
}
