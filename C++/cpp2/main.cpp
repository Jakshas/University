//Jakub Szajner
#include <iostream>
#include <math.h>

using namespace std;


class Wektor
{
public:
    double dx;
    double dy;
    Wektor()=default;
    Wektor(double dx,double dy)
    {
        this->dx=dx;
        this->dy=dy;
    }
    Wektor(const Wektor &wek)
    {
        this->dx=wek.dx;
        this->dy=wek.dy;
    }
    Wektor zluz(Wektor a,Wektor b)
    {
        Wektor c=Wektor(a.dx+b.dx,a.dy+b.dy);
        return c;
    }
};
class Punkt
{
public:
    double x;
    double y;
    Punkt()=default;
    Punkt(double x,double y)
    {
        this->x=x;
        this->y=y;
    }
    Punkt(Punkt p,Wektor w)
    {
        this->x=p.x+w.dx;
        this->y=p.y+w.dy;
    }
    Punkt(const Punkt &pkt)
    {
        this->x=pkt.x;
        this->y=pkt.y;
    }
};
class Prosta
{
public:
    double a;
    double b;
    double c;
    double geta()
    {
        return this->a;
    }
    double getb()
    {
        return this->b;
    }
    double getc()
    {
        return this->c;
    }
    Prosta(Punkt a,Punkt b)
    {
        if (a.x==b.x && a.y==b.y)
            throw invalid_argument("nie mo¿na jednoznacznie utworzyæ prostej");
        this->a=(a.y-b.y)/(a.x-b.x);
        this->b=1;
        this->c=a.y-a.x*this->a;
    }
    Prosta(Wektor w)
    {
        this->a=-1*(w.dx/w.dy);
        this->b=1;
        this->c=this->a*w.dx-w.dy;
    }
    Prosta(double a,double b,double c)
    {
        if(a==0&&b==0)
        {
            throw invalid_argument("nie mo¿na jednoznacznie utworzyæ prostej");
        }
        this->a=a;
        this->b=b;
        this->c=c;
    }
    Prosta(Prosta p,Wektor w)
    {
        this->a=p.a;
        this->b=p.b;
        this->c=p.c+w.dx*p.a+w.dy;
    }
    Prosta & operator =( const Prosta & ) = delete;
    bool badajWrow(Wektor w)
    {
        if((w.dy/w.dx)==(this->a/this->b))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool badajWprost(Wektor w)
    {
        if((w.dy/w.dx)==(-1*this->b/this->a))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool czyna(Punkt p)
    {
        if((this->a*p.x+c)==(p.y*this->b))
        {
            return true;
        }
        else
        {
            double gura=((this->a*p.x)+(this->b*p.y)+c);
            double wartosc=abs((this->a*p.x)+(this->b*p.y)+c)/(sqrt(a*a+b*b));
            cout<<wartosc<<endl;
            return false;
        }
    }
};
bool czyProw(Prosta a,Prosta b)
{
    if((a.a/a.b)==(b.a/b.b))
    {
        return true;
    }
    else
    {
        return false;
    }
}
    bool badajPprost(Prosta a, Prosta b)
    {
        if((a.b/a.a)==(-1*b.b/b.a))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    Punkt gdzieprzecina(Prosta j, Prosta d){
    double x,y;
    if(czyProw(j,d)){
      cerr<<"sa rownoleg³e"<<endl;
    }else{
    x=(-1*j.c*d.b-(-1)*d.c*j.b)/(j.a*d.b-d.a*j.b);
    y=(-1*d.c*j.a-(-1)*j.c*d.a)/(j.a*d.b-d.a*j.b);
    Punkt g=Punkt(x,y);
    return g;
    }
    }
int main()
{
    Wektor a=Wektor(12,3);
    cout<<a.dx;
    Wektor c =Wektor(a);
    cout<<c.dy;
}
