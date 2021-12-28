#include <iostream>
using namespace std;
class tab_bit{
    typedef uint64_t slowo; // komorka w tablicy
    static const int rozmiarSlowa = 64; // rozmiar slowa w bitach
    friend istream & operator >> (istream &we, tab_bit &tb);
    friend ostream & operator << (ostream &wy, const tab_bit &tb);
    public:
    class ref{ 
        public:
        slowo *ktore;
        int bit;
        ref(int bit, tab_bit *tab);
        tab_bit::ref & operator = (const int &tb);
        tab_bit::ref & operator = (const ref &tb);
        tab_bit::ref & operator = (const bool &tb);
    };
    protected:
        int dl; // liczba bitów
        slowo *tab; // tablica bitów
    public:
        explicit tab_bit (int rozm); // wyzerowana tablica bitow [0...rozm]
        explicit tab_bit (slowo tb); // tablica bitów [0...rozmiarSlowa zainicjalizowana wzorcem
        tab_bit (const tab_bit &tb); // konstruktor kopiujący
        tab_bit (tab_bit &&tb); // konstruktor przenoszący
        tab_bit & operator = (const tab_bit &tb); // przypisanie kopiujące
        tab_bit & operator = (tab_bit &&tb); // przypisanie przenoszące
        ~tab_bit (); // destruktor
 //   private:
        bool czytaj (int i) const; // metoda pomocnicza do odczytu bitu 
        bool pisz (int i, bool b); // metoda pomocnicza do zapisu bitu
    public:
        bool operator[] (int i) const; // indeksowanie dla stałych tablic bitowy
        ref &operator[] (int &i); // indeksowanie dla zwykłych tablicbitowych
        inline int rozmiar () const; // rozmiar tablicy w bitach
    public:
        tab_bit operator |(tab_bit a);
        tab_bit operator |=(tab_bit a);
        tab_bit operator &(tab_bit a);
        tab_bit operator &=(tab_bit a);
        tab_bit operator ^(tab_bit a);
        tab_bit operator ^=(tab_bit a);
        tab_bit operator !();
    // operatory bitowe: | i |=, & i &=, ^ i ^= oraz !
    public:
    // zaprzyjaźnione operatory strumieniowe: << i >>
};