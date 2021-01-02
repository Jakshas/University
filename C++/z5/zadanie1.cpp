#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

queue<char> wyrazenie;
queue<char> onp;
std::stack<char> stos;

void dowyr(string s){
    for (int i = 0; i < s.length(); i++)
    {
        wyrazenie.push(s[i]);
    } 
}
void wyrdoonp(){
    queue<char> &wyrazenie1=wyrazenie;
    queue<char> &onp1=onp;
    std::stack<char> &stos1=stos;
    while (wyrazenie.size()>0)
    {
        int j;
        char c= wyrazenie.front();
        if (c>='0'&&c<='9') onp.push(c);
        else if (c=='(')stos.push(c);
        else if (c=='+'||c=='-'||c=='*'||c=='/')
            {
                if (c=='*'||c=='/')
                {
                    j=3;
                }else
                {
                    j=2;
                }        
                for(int d ; stos.size() != 0 &&  (d = ((stos.top()=='(')?1:(stos.top()=='*'||stos.top()=='/')?3:2))>=j ;) {
                    onp.push(stos.top());
                    stos.pop();
                }
                stos.push(c);  
            }else
            {

                
                for(int d ; (d = (stos.top()=='(')?1:2) != 1;) {
                    onp.push(stos.top());
                    stos.pop();
                }
                stos.pop();
            }
        wyrazenie.pop();
        }
            while(stos.size() != 0) {
            onp.push(stos.top());
            stos.pop();
        }
}

void wypisz(){
    while (onp.size() > 0)
    {
        cout << onp.front()<<" ";
        onp.pop();
    }
    
}

int main(int argc, char const *argv[])
{
    string input = "4-2*3/(5+6)";
    dowyr(input);
    wyrdoonp();
    wypisz();
    return 0;
}
