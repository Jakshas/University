#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

class wyrazenie{
    public:
        int prio;
        bool laczne = 0;
        virtual double oblicz()=0;
        virtual string pisz()=0;
};
class liczba: public wyrazenie{
    public:
        double wartosc;
        liczba(double input);
        string pisz();
        double oblicz();
};
class stala : public wyrazenie{
    protected:
        double wartosc;
};

class pi : public stala{
    public:
        string pisz();
        double oblicz();
        pi();
};

class e : public stala{
    public:
        string pisz();
        double oblicz();
        e();
};

class fi : public stala{
    public:
        string pisz();
        double oblicz();
        fi();
};

class zmienna : public wyrazenie{
    private:
        inline static vector<pair<string, double>> zbior;
    public:
        string nazwa_zmiennej;
        zmienna(string nazwa, double wartosc);
        string pisz();
        double oblicz(); 
};

class operatorjed : public wyrazenie{
    protected:
        wyrazenie* wyr;

};

class Sin : public operatorjed{
    public:
        Sin(wyrazenie *k);
        string pisz();
        double oblicz();
};

class Cos : public operatorjed{
    public:
        Cos(wyrazenie *k);
        string pisz();
        double oblicz();
};

class odwrot : public operatorjed{
    public:
        odwrot(wyrazenie *k);
        string pisz();
        double oblicz();
};

class Exp : public operatorjed{
    public:
        Exp(wyrazenie *k);
        string pisz();
        double oblicz();
};

class przeciw : public operatorjed{
    public:
        przeciw(wyrazenie *k);
        string pisz();
        double oblicz();
};

class ln : public operatorjed{
    public:
        ln(wyrazenie *k);
        string pisz();
        double oblicz();
};

class bezw : public operatorjed{
    public:
        bezw(wyrazenie *k);
        string pisz();
        double oblicz();
};

class operatorbin : public operatorjed{
    protected:
        wyrazenie *lewe;
        wyrazenie *prawe;
    public:
        operatorbin(wyrazenie *l, wyrazenie *p);
};

class dodaj : public operatorbin{
    public:
        dodaj(wyrazenie *l, wyrazenie *p);
        double oblicz();
        string pisz();
};

class odejmij : public operatorbin{
    public:
        odejmij(wyrazenie *l, wyrazenie *p);
        double oblicz();
        string pisz();
};

class mnoz : public operatorbin{
    public:
        mnoz(wyrazenie *l, wyrazenie *p);
        double oblicz();
        string pisz();
};

class dziel : public operatorbin{
    public:
        dziel(wyrazenie *l, wyrazenie *p);
        double oblicz();
        string pisz();
};

class Pot : public operatorbin{
    public:
        Pot(wyrazenie *l, wyrazenie *p);
        double oblicz();
        string pisz();
};

class Log : public operatorbin{
    public:
        Log(wyrazenie *l, wyrazenie *p);
        double oblicz();
        string pisz();
};

class Mod : public operatorbin{
    public:
        Mod(wyrazenie *l, wyrazenie *p);
        double oblicz();
        string pisz();
};