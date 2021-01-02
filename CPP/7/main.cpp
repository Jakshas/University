#include "wymierna.hpp"

int main(int argc, char const *argv[])
{
    try{
    obliczenia::wymierna w1=obliczenia::wymierna(10,20);
    obliczenia::wymierna w2=obliczenia::wymierna(4);
    obliczenia::wymierna w3=w1+w2;
    obliczenia::wymierna w4=!w3;
    std::cout<<w3<<std::endl;
    std::cout<<double(w4)<<std::endl;
    std::cout<<w4<<std::endl;
    std::cout<<w3<<std::endl;
    std::cout<<w1-w2<<std::endl;
    std::cout<<w1*w2<<std::endl;
    std::cout<<w1/w2<<std::endl;
    }catch(obliczenia::wyjatekwymierny e){
    }
    return 0;
}
