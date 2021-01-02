#include "wymierna.hpp"
using namespace obliczenia;
int wymierna::get_mianownik() const{
    return this->mianownik;
}

int wymierna::get_licznik() const{
    return this->licznik;
}

int wymierna::NWD(int64_t a, int64_t b){
    if (b == 0)
        return a;
    return NWD(b, a % b);
}

wymierna::wymierna(int l, int m){
    if(m == 0) throw dzielenie_przez_0();
    int nwd = NWD(l, m);
    if(l * m < 0){
        this->licznik = (-1) * abs(l); this->mianownik = abs(m);
    }
    else{
        this->licznik = abs(l) / nwd; this->mianownik = abs(m) / nwd;
    }
}

wymierna::wymierna(int licz) : obliczenia::wymierna(licz, 1) {};

wymierna wymierna::operator!() noexcept(false){
    if (this->licznik == 0) 
    {
        throw dzielenie_przez_0();
    }
    return wymierna(this->mianownik, this->licznik);
}

wymierna wymierna::operator-() noexcept(true){
    return wymierna(-1 * this->licznik, this->mianownik);
}

wymierna wymierna::operator*(const wymierna &druga) noexcept(false){
    int64_t nowy_licznik, nowy_mianownik, nwd;
    nowy_licznik = this->get_licznik() * druga.get_licznik();
    nowy_mianownik = this->get_mianownik() * druga.get_mianownik();
    nwd = this->NWD(nowy_licznik, nowy_mianownik);
    nowy_licznik = nowy_licznik / nwd; nowy_mianownik = nowy_mianownik / nwd;

    if(nowy_licznik < INT32_MIN || nowy_licznik > INT32_MAX)
    {
        throw przekroczenie_zakresu();
    }
    nowy_mianownik = this->get_mianownik() * druga.get_mianownik();
    if(nowy_mianownik < INT32_MIN || nowy_mianownik > INT32_MAX)
    {
        throw przekroczenie_zakresu();
    }
    return wymierna(nowy_licznik, nowy_mianownik);
}

wymierna wymierna::operator/(const wymierna &druga) noexcept(false){
    if(druga.get_licznik() == 0) throw dzielenie_przez_0();
    int64_t nowy_licznik, nowy_mianownik, nwd;
    nowy_licznik = this->get_licznik() * druga.get_mianownik();
    nowy_mianownik = this->get_mianownik() * druga.get_licznik();
    nwd = this->NWD(nowy_licznik, nowy_mianownik);
    nowy_licznik = nowy_licznik / nwd;
    nowy_mianownik = nowy_mianownik / nwd;
    
    if(nowy_licznik < INT32_MIN || nowy_licznik > INT32_MAX){
        throw przekroczenie_zakresu();
    }   
    if(nowy_mianownik < INT32_MIN || nowy_mianownik > INT32_MAX){
        throw przekroczenie_zakresu();
    }
    return wymierna(nowy_licznik, nowy_mianownik);
}

wymierna wymierna::operator+(const wymierna &druga) noexcept(false){
    int64_t nowy_licznik, nowy_mianownik, nwd;
    nowy_licznik = this->get_licznik() * druga.get_mianownik() + druga.get_licznik() * this->get_mianownik();
    nowy_mianownik = this->get_mianownik() * druga.get_mianownik();
    nwd = this->NWD(nowy_licznik, nowy_mianownik);
    nowy_licznik = nowy_licznik / nwd; 
    nowy_mianownik = nowy_mianownik / nwd;

    if(nowy_licznik < INT32_MIN || nowy_licznik > INT32_MAX){
        throw przekroczenie_zakresu();
    }   
    if(nowy_mianownik < INT32_MIN || nowy_mianownik > INT32_MAX){
        throw przekroczenie_zakresu();
    }
    return wymierna(nowy_licznik, nowy_mianownik);
}

wymierna wymierna::operator-(const wymierna &druga) noexcept(false){
int64_t nowy_licznik, nowy_mianownik, nwd;
nowy_licznik = this->get_licznik() * druga.get_mianownik() - druga.get_licznik() * this->get_mianownik();
nowy_mianownik = this->get_mianownik() * druga.get_mianownik();
nwd = this->NWD(nowy_licznik, nowy_mianownik);
nowy_licznik = nowy_licznik / nwd; 
nowy_mianownik = nowy_mianownik / nwd;

if(nowy_licznik < INT32_MIN || nowy_licznik > INT32_MAX){
    throw przekroczenie_zakresu();
    }   
if(nowy_mianownik < INT32_MIN || nowy_mianownik > INT32_MAX){
    throw przekroczenie_zakresu();
    }
return wymierna(nowy_licznik, nowy_mianownik);
}

wymierna::operator double(){
    return double(this->licznik) / this->mianownik;
};

wymierna::operator int(){
    if(double(*this) - 0.5 >= this->licznik/this->mianownik){
        return int(this->licznik/this->mianownik) + 1;  };
    return int(this->licznik/this->mianownik);
};

std::ostream & obliczenia::operator<<(std::ostream &out, const wymierna &l){
    std::vector<int> wynik;
    std::vector<int> reszty;
    std::string wyraz="";
    int reszta = l.get_licznik() % l.get_mianownik();
    wyraz=wyraz+ std::to_string(int(l.get_licznik() / l.get_mianownik()));
    
    if (reszta == 0) { 
        out<<wyraz; 
        return out;
    }
    reszty.push_back(reszta);
    wyraz=wyraz+  ".";
    reszta=abs(reszta);
    while(true){
        wynik.push_back(reszta * 10 / l.get_mianownik());
        reszta = reszta * 10 % l.get_mianownik();
        if(reszta == 0){
            for(int i = 0; i < wynik.size(); i++){
                wyraz=wyraz+ std::to_string(wynik[i]);
            }
            out<<wyraz;
            return out;
        }
        for(int j{0}; j < wynik.size(); j++){
            if(reszty[j] == reszta){
                for(int k{0}; k < j; k++){
                    wyraz=wyraz+ std::to_string(wynik[k]);
                }
                wyraz=wyraz+ "(";
                for(int k{0}; k< reszty.size(); k++){
                    wyraz=wyraz+ std::to_string(wynik[k]);
                }
                wyraz=wyraz+ ")";
                out<<wyraz; 
                return out;
            }
        }
        reszty.push_back(reszta);
    }
}