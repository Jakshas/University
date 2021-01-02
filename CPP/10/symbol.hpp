#include <iostream>
#include <vector>
#include <cmath>
#include <stack>

namespace kalkulator{   
    class symbol{
        public:
            int some_num;
            virtual double eval() = 0;
    };

    class operand : public symbol{
        public:
            double val;
    };

    class liczba : public operand{
        public:
            double eval();
            liczba(double num);
    };

    class zmienna : public operand{
        public:
            std::string name;
            static std::vector<std::pair<std::string, double>> var;
            zmienna(std::string name);
            void assign(std::string name, double val);
            double eval();
            void clear();
            double val_lookup(std::string name);
            bool in(std::string name);
            double get_val(int position);
    };


    class funkcja : public symbol{};

    class oaf : public funkcja{
        public:
            symbol *arg;
            oaf(symbol *inp);
    };

    class abs : public oaf{
        public:
            abs(symbol *inp);
            double eval();
    };

    class sgn : public oaf{
        public:
            double eval();
            sgn(symbol *inp);
    };

    class floor : public oaf{
        public:
            double eval();
            floor(symbol *inp);
    };

    class ceil : public oaf{
        public:
            double eval();
            ceil(symbol *inp);
    };

    class frac : public oaf{
        public:
            double eval();
            frac(symbol *inp);
    };

    class sin : public oaf{
        public:
            double eval();
            sin(symbol *inp);
    };

    class cos : public oaf{
        public:
            double eval();
            cos(symbol *inp);
    };

    class atan : public oaf{
        public:
            double eval();
            atan(symbol *inp);
    };

    class acot : public oaf{
        public:
            double eval();
            acot(symbol *inp);
    };

    class exp : public oaf{
        public:
            double eval();
            exp(symbol *inp);
    };

    class ln : public oaf{
        public:
            double eval();
            ln(symbol *inp);
    };

    class taf : public funkcja{
        public:
            symbol *left; symbol *right;
            taf(symbol *x, symbol *y);
    };

    class add : public taf{
        public:
            add(symbol *x, symbol *y);
            double eval();
    };

    class sub : public taf{
        public:
            sub(symbol *x, symbol *y);
            double eval();
    };

    class mult : public taf{
        public:
            mult(symbol *x, symbol *y);
            double eval();
    };

    class div : public taf{
        public:
            div(symbol *x, symbol *y);
            double eval();
    };

    class log : public taf{
        public:
            log(symbol *x, symbol *y);
            double eval();
    };

    class min : public taf{
        public:
            min(symbol *x, symbol *y);
            double eval();
    };

    class max : public taf{
        public:
            max(symbol *x, symbol *y);
            double eval();
    };

    class mod : public taf{
        public:
            mod(symbol *x, symbol *y);
            double eval();
    };

    class pow : public taf{
        public:
            pow(symbol *x, symbol *y);
            double eval();
    };
}
using namespace std;
bool if_exit(string inp);
bool if_clear(string inp);
bool if_print(string inp);
bool if_assign(string inp);
double evaluator(string inp, kalkulator::zmienna &var);