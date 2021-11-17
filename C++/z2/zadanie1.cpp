 #include <iostream>
 #include <memory>
 #include <cmath>
 #include <ctime>
 using namespace std;
class licznik
{
    public:
    uint64_t l=1;
    licznik(/* args */);
    ~licznik();
};
licznik::licznik(){

}
licznik::~licznik()
{
    cerr<<l<<", ";
}
void dodaj(unique_ptr<licznik[]> & p);
int n=10;
int m=10;

void dodaj(unique_ptr<licznik[]> & p, int i){
    if(i==0){
        return;
    }
    p[rand()%n].l=p[rand()%n].l+i;
    return dodaj(p,i-1);
}
int main(int argc, char const *argv[])
{
    unique_ptr<licznik[]> p=make_unique<licznik[]>(n);
    srand(time(nullptr));
    dodaj(p,m); 
}
