#include "symbol.hpp"

using namespace kalkulator;

std::vector<std::pair<std::string, double>> zmienna::var;

liczba::liczba(double inpval){
    this->val = inpval;
}

double liczba::eval(){
    return this->val;
}

zmienna::zmienna(std::string name){
    for(int i{0}; i < zmienna::var.size(); i++){
        if (zmienna::var[i].first == name){
            this->val = i;
            return;
        }
    }
    var.push_back(make_pair(name, 0));
    this->val = var.size();
}

double zmienna::val_lookup(std::string name){
    for(int i{0}; i < zmienna::var.size(); i++){
        if (zmienna::var[i].first == name){
            return var[i].second;
        }
    }
    return 0;
}

bool zmienna::in(std::string name){
    for(int i{0}; i < zmienna::var.size(); i++){
        if (zmienna::var[i].first == name){ 
            return true;
        }
    }
    return false; 
}

double zmienna::get_val(int pos){
    return var[pos].second;
}

void zmienna::assign(std::string name, double val){
    for(int i{0}; i < zmienna::var.size(); i++){
        if (zmienna::var[i].first == name) 
            var[i].second = val;
    }
}

double zmienna::eval(){
    return this->val_lookup(this->name);
}

void zmienna::clear(){
    var = std::vector<std::pair<std::string, double>>();
}

oaf::oaf(symbol *k) : arg(k) {};
abs::abs(symbol *k) : oaf(k) {};

double abs::eval(){
    return std::abs(arg->eval());
}

sgn::sgn(symbol *k) : oaf(k) {};

double sgn::eval(){
    if(arg->eval() < 0)
        return -1;
    else if(arg->eval() == 0)
        return 0;
    return 1;
}

floor::floor(symbol *k) : oaf(k) {};

double floor::eval(){
    return std::floor(arg->eval());
}

ceil::ceil(symbol *k) : oaf(k) {};

double ceil::eval(){
    return std::ceil(arg->eval());
}

frac::frac(symbol *k) : oaf(k) {};

double frac::eval(){
    return std::abs(arg->eval()) - std::floor(std::abs(arg->eval())); 
}

sin::sin(symbol *k) : oaf(k) {};

double sin::eval(){
    return std::sin(arg->eval());
}

cos::cos(symbol *k) : oaf(k) {};

double cos::eval(){
    return std::cos(arg->eval());
}

atan::atan(symbol *k) : oaf(k) {};

double atan::eval(){
    return std::atan(arg->eval());
}

acot::acot(symbol *k) : oaf(k) {};

double acot::eval(){
    return std::atan(1/(arg->eval()));
}

exp::exp(symbol *k) : oaf(k) {};

double exp::eval(){
    return std::exp(arg->eval());
}

ln::ln(symbol *k) : oaf(k) {};

double ln::eval(){
    return std::log(arg->eval());
}

taf::taf(symbol *x, symbol *y) : left(x), right(y) {};

add::add(symbol *x, symbol *y) : taf(x, y) {};

double add::eval(){
    return left->eval() + right->eval();
}

sub::sub(symbol *x, symbol *y) : taf(x, y) {};

double sub::eval(){
    return left->eval() - right->eval();
}

div::div(symbol *x, symbol *y) : taf(x, y) {};

double div::eval(){
    return left->eval() / right->eval();
}

mult::mult(symbol *x, symbol *y) : taf(x, y) {};

double mult::eval(){
    return left->eval() * right->eval();
}

min::min(symbol *x, symbol *y) : taf(x, y) {};

double min::eval(){
    return std::min(left->eval(), right->eval());
}

max::max(symbol *x, symbol *y) : taf(x, y) {};

double max::eval(){
    return std::max(left->eval(), right->eval());
}

mod::mod(symbol *x, symbol *y) : taf(x, y) {};

double mod::eval(){
    return std::fmod(left->eval(), right->eval()); 
}

log::log(symbol *x, symbol *y) : taf(x, y) {};

double log::eval(){
    return std::log(left->eval()) / std::log(right->eval());
}

pow::pow(symbol *x, symbol *y) : taf(x, y) {};

double pow::eval(){
    return std::pow(left->eval(), right->eval());
}