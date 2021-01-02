#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

class wyrazenie{
    public:
        int priorytet;
        virtual double oblicz() = 0;
        virtual string opis() = 0; 
};

class liczba : public wyrazenie{
    public:
        double wartosc;
        liczba(double input);
        string opis();
        double oblicz();
}; 

class stala : public wyrazenie{
    protected:
        double wartosc;
};

class pi : public stala{
    public:
        string opis();
        double oblicz();
        pi();
};

class e : public stala{
    public:
        string opis();
        double oblicz();
        e();
};

class fi : public stala{
    public:
        string opis();
        double oblicz();
        fi();
};

class zmienna : public wyrazenie{
    private:
        static vector<pair<string, double>> zbior;
    public:
        string nazwa_zmiennej;
        static void usun(string nazwa);
        zmienna(string nazwa, double wartosc);
        string opis();
        double oblicz(); 
};

class operatorjed : public wyrazenie{
    protected:
        wyrazenie* wyr;

};

class Sin : public operatorjed{
    public:
        Sin(wyrazenie *k);
        string opis();
        double oblicz();
};

class Cos : public operatorjed{
    public:
        Cos(wyrazenie *k);
        string opis();
        double oblicz();
};

class odwrot : public operatorjed{
    public:
        odwrot(wyrazenie *k);
        string opis();
        double oblicz();
};

class Exp : public operatorjed{
    public:
        Exp(wyrazenie *k);
        string opis();
        double oblicz();
};

class przeciw : public operatorjed{
    public:
        przeciw(wyrazenie *k);
        string opis();
        double oblicz();
};

class ln : public operatorjed{
    public:
        ln(wyrazenie *k);
        string opis();
        double oblicz();
};

class bezw : public operatorjed{
    public:
        bezw(wyrazenie *k);
        string opis();
        double oblicz();
};

class operatorbin : public operatorjed{
    protected:
        wyrazenie *lewe;
        wyrazenie *prawe;
        bool lewostronnielaczne;
    public:
        operatorbin(wyrazenie *l, wyrazenie *p);
};

class Dod : public operatorbin{
    public:
        Dod(wyrazenie *l, wyrazenie *p);
        double oblicz();
        string opis();
};

class Odejm : public operatorbin{
    public:
        Odejm(wyrazenie *l, wyrazenie *p);
        double oblicz();
        string opis();
};

class Mnoz : public operatorbin{
    public:
        Mnoz(wyrazenie *l, wyrazenie *p);
        double oblicz();
        string opis();
};

class Dziel : public operatorbin{
    public:
        Dziel(wyrazenie *l, wyrazenie *p);
        double oblicz();
        string opis();
};

class Pot : public operatorbin{
    public:
        Pot(wyrazenie *l, wyrazenie *p);
        double oblicz();
        string opis();
};

class Log : public operatorbin{
    public:
        Log(wyrazenie *l, wyrazenie *p);
        double oblicz();
        string opis();
};

class Mod : public operatorbin{
    public:
        Mod(wyrazenie *l, wyrazenie *p);
        double oblicz();
        string opis();
};
