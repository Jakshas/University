#include <iostream>
using namespace std;
void hanoi(int n,char Begin,char Aux, char End)
{
    if(n==1)
        cout<<Begin<<" -> "<<End<<endl;
    else
    {
        hanoi(n-1,Begin,End,Aux);
        hanoi(1,Begin,Aux,End);
        hanoi(n-1,Aux,Begin,End);

    }
}
int main(int argc, char *argv[])
{
  hanoi(3, 'A', 'B', 'C');
  return 0;
}
