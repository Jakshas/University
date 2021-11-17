#include <iostream>
#include <string>
#include <vector>

namespace obliczenia{

    class wymierna{
        private:
            int licznik;
            int mianownik;
            int NWD(int64_t a, int64_t b); 
        public:
            wymierna(int licz, int mian); 
            wymierna(int licz);           
            int get_licznik() const;      
            int get_mianownik() const;  
            wymierna operator!(); 
            wymierna operator-() noexcept; 
            wymierna operator+ (const wymierna &druga); 
            wymierna operator- (const wymierna &druga); 
            wymierna operator* (const wymierna &druga); 
            wymierna operator/ (const wymierna &druga); 
            operator double(); 
            operator int();
            friend std::ostream &operator<<(std::ostream &out, const wymierna &inp);
    };

    class wyjatekwymierny : std::exception {};
    class dzielenie_przez_0 : wyjatekwymierny {};
    class przekroczenie_zakresu : wyjatekwymierny {};

}
