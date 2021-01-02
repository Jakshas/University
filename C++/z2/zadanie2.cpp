#include <iostream>
#include <memory>
#include <fstream>
#include <string>
using namespace std;
class line_writer
{
private:
    /* data */
public:
    ofstream plik;
    line_writer(string s);
    ~line_writer();
    void pisz(string s);
};

line_writer::line_writer(string s):plik(s){}

void line_writer::pisz(string s){
    plik<<s<<endl;
}
line_writer::~line_writer()
{
    cout<<"delete";
}
int main(int argc, char const *argv[])
{
    line_writer *write=new line_writer("plik.txt");
    shared_ptr<line_writer> p1{write};
    shared_ptr<line_writer> p2{write};
    shared_ptr<line_writer> p3{write};
    shared_ptr<line_writer> p4{write};
    p1->pisz("1 ");
    p2->pisz("2 ");
    p3->pisz("3 ");
    p4->pisz("4 ");
    return 0;
}
