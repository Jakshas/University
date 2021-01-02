#include<iostream>
#include<algorithm>
#include<list>
#include<string>

using namespace std;

class point
{
    public:
        double x;
        double y;
        double R,G,B;
        string name;

        point(float x, float y, int r, int g, int b, string name):x(x),y(y),R(r),G(g),B(b),name(name){}

        point():x(0),y(0),R(0),G(0),B(0),name(""){}

        float luminacja() const
        {
            return R * 0.3 + G * 0.59 + B * 0.1;
        }

        friend ostream& operator<<(ostream& os, point inp)
        {
            return os << inp.name << " " << inp.x << " " << inp.y << " R-" << inp.R << " G-"  << inp.G << " B-" << inp.B << endl;
        }
};

void pisz(list<point>& inp)
{
    for(auto x : inp)
    {
        if (x.name != "")
        {
            cout << x << endl;
        }
    }
}

void usun(list<point>& inp)
{
    inp.erase(remove_if(inp.begin(), inp.end(), [] (point& a) {return a.name.size() > 5; }), inp.end());
    pisz(inp);
}

void cwiartki(list<point>& inp)
{
    cout << "I " << count_if(inp.begin(), inp.end(), [] (point& a) { return a.x > 0 && a.y > 0;}) << endl;
    cout << "II " << count_if(inp.begin(), inp.end(), [] (point& a) { return a.x < 0 && a.y > 0;})<< endl;
    cout << "III " << count_if(inp.begin(), inp.end(), [] (point& a) { return a.x < 0 && a.y < 0;})<< endl;
    cout << "IV " << count_if(inp.begin(), inp.end(), [] (point& a) { return a.x > 0 && a.y < 0;})<< endl;
}

void sortujL(list<point>& inp)
{
    inp.sort([] (point a, point b) {return a.luminacja() < b.luminacja(); });
    pisz(inp);
}

void ciemne(list<point>& inp)
{
    list<point> copied(inp.size());
    copy_if(inp.begin(), inp.end(), copied.begin(), [] (point& a) {return a.luminacja() < 64; });
    int j=0;
    for (auto &&i : copied)
    {
        if (i.name != "")
        {
            j++;
        }
        
    }
    
    cout << "ciemne- " << j<< endl;
    pisz(copied);
}

int main()
{
    list<point> test;
    test.push_back(point(1, 1, 100,200,40, "aaaaaaaaa"));
    test.push_back(point(1, 1, 100,200,40, "bbbbbbb"));
    test.push_back(point(1, 1, 100,200,40, "ccccccccccccccc"));
    test.push_back(point(1, 1, 100,200,40, "dddddddddd"));
    test.push_back(point(1, 1, 100,200,40, "eeeeeeeee"));
    test.push_back(point(1, 1, 100,200,40, "fff"));
    test.push_back(point(1, 1, 100,200,40, "gggggggggggg"));
    test.push_back(point(1, 1, 100,200,40, "hhhhhhhh"));
    test.push_back(point(1, 1, 100,200,40, "iiiii"));
    test.push_back(point(1, 1, 100,200,40, "jjjjjj"));
    test.push_back(point(1, 1, 100,200,40, "kkkk"));
    test.push_back(point(1, 1, 100,200,40, "lllll"));
    test.push_back(point(1, 1, 100,200,40, "mmmmmmm"));
    test.push_back(point(1, 1, 100,200,40, "nnnnn"));
    test.push_back(point(1, 1, 200, 100, 2, "oooooooooo"));
    test.push_back(point(1, -1, 0, 0, 2, "p"));
    test.push_back(point(-1, 1, 0, 100, 7, "rrrrrrr"));
    test.push_back(point(-1,-1, 200,100,80, "sssssssss"));
    usun(test);
    cout << endl;
    sortujL(test);
    cout << endl;
    cwiartki(test);
    cout << endl;
    ciemne(test);
    cout << endl;
}