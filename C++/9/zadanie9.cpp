#include <iostream>
#include <ostream>
#include <string>
#include <fstream>

using namespace std;
class ignore 
{
    int wart;
    friend istream& operator>>(istream &is, const ignore &licz)
    {   int i =1;
        char c=is.get();
        while((c=is.get())!='\n'&&i<licz.wart){
            i++;
        }
        return is;  }
    public:
    ignore (int wart): wart(wart){};
    };
    inline istream& clearline(istream& is)
    {
        char c=is.get();
        while((c=is.get())!='\n'){
        }
        return is;
    }
    inline ostream& comma(ostream& os)
    {
        os<<", ";
        return os;
    }
    inline ostream& colon(ostream& os)
    {
        os<<": ";
        return os;
    }
    class index 
{
    int xs;
    int ws;
    friend ostream& operator<<(ostream &is, const index &licz)
    {   
        int xss=licz.xs;
        int wss=licz.ws;
        string s="]";
        int x;
        while (xss>0&&wss>0)
        {
            x=xss%10;
            xss=xss/10;
            s=to_string(x)+s;
            wss=wss-1;
        }
        while(wss>0){
            s="0"+s;
            wss=wss-1;
        }
        s="["+s;
        is<<s;
        return is;  
    }
    public:
    index (int x,int w):xs(x), ws(w){};
    };
    class wejscie{
        string nazwa = "dane.txt";
        ifstream plik;
        wejscie(){
            this->plik.open(this->nazwa);
        }
        ~wejscie(){
            this->plik.close();
        }
    };
    class wyjscie{
        string nazwa = "dane.txt";
        ofstream plik;
        wyjscie(){
            this->plik.open(this->nazwa);
        }
        ~wyjscie(){
            this->plik.close();
        }
    };
    int main(int argc, char const *argv[])
    {
        string s , b;
        cin>>s>>clearline>>b;
        cout<<s<<" "<<b;
        cin>>s>>ignore(3)>>b;
        cout<<s<<" "<<b;
        cout<<comma<<colon<<index(3,2);
    }
    
