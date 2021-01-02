#include "symbol.hpp"

using namespace std;

int main(){
    kalkulator::zmienna *init_vars = new kalkulator::zmienna("init_var"); //variable to manage all variables
    while(true){
        string input_line;
        getline(cin, input_line);
        if(if_exit(input_line)){
            return 0;
        }

        else if(if_print(input_line)){
            try{
                cout << evaluator(input_line.substr(6), *init_vars) << '\n';
            }
            catch(std::invalid_argument &exep){
                cout << "error" << '\n';
            }
            catch(std::domain_error &e){
                cout << "unknown variable" << '\n';
            }
        }

        else if(if_clear(input_line)){
            init_vars->clear();
            kalkulator::zmienna *init_vars = new kalkulator::zmienna("init_var");
        }

        else if(if_assign(input_line)){
            if(input_line.find(" to ") >= 0){
                std::string val_to_parse = input_line.substr(7, input_line.find(" to ") - 7);
                double val = evaluator(val_to_parse, *init_vars);
                string name = input_line.substr(input_line.find(" to ") + 4);
                if(name == "exit" || name == "assign" || name == "clear" || name == "print")
                    cout << "error" << endl;
                if(!(init_vars->in(name))){
                    kalkulator::zmienna* nowa = new kalkulator::zmienna(name);
                }
                init_vars->assign(name, val);
            }
            else{
                cout<<"error" << '\n';
            }
        }
        else if(init_vars->in(input_line)){
            cout << input_line << " = " << init_vars->val_lookup(input_line) << '\n';
        }
        else{
            cout<<"error" << '\n';
        }
    }
}

bool if_exit(string inp){
    if(inp.find("exit") == 0)
        return true;
    return false;
}

bool if_print(string inp){
    if(inp.find("print") == 0){
        return true;
    }
    return false;
}

bool if_assign(string inp){
    if(inp.find("assign") == 0)
        return true;
    return false;
}

bool if_clear(string inp){
    if(inp.find("clear") == 0)
        return true;
    return false;
}

double evaluator(string expr, kalkulator::zmienna &env){ 
    stack<kalkulator::symbol*> parsed;
    vector<string> one = vector<string>{"cos", "sin", "abs", "sgn", "ln", "ceil", "frac", "floor", "atan", "acot", "exp"};
    vector<string> two = vector<string>{"+", "-", "/", "*", "max", "min", "mod", "pow", "log"};
    for(int i{0}; i < expr.size(); i++){
        if(expr[i] == ' ')
            i++;
        string pom = expr.substr(i, expr.find(" ", i) - i); 
        try{
            parsed.push(new kalkulator::liczba(stod(pom)));
            i += pom.length();
        }
        catch(invalid_argument &exep){
            bool onearg_fn = false;
            for(string fn : one){
                if(fn == pom)
                    onearg_fn = true;
            }
            bool twoarg = false;
            for(string fn : two){
                if(fn == pom)
                    twoarg = true;
            }
            if(onearg_fn){
                if(parsed.empty())
                    throw(invalid_argument("ERROR"));
                kalkulator::symbol *argument = parsed.top();
                parsed.pop();
                if(pom == "abs")
                    parsed.push(new kalkulator::abs(argument));
                else if(pom == "sgn")
                    parsed.push(new kalkulator::sgn(argument));
                else if(pom == "cos")
                    parsed.push(new kalkulator::cos(argument));
                else if(pom == "sin")
                    parsed.push(new kalkulator::sin(argument));
                else if(pom == "exp")
                    parsed.push(new kalkulator::exp(argument));
                else if(pom == "ceil")
                    parsed.push(new kalkulator::ceil(argument));
                else if(pom == "floor")
                    parsed.push(new kalkulator::floor(argument));
                else if(pom == "atan")
                    parsed.push(new kalkulator::atan(argument));
                else if(pom == "acot")
                    parsed.push(new kalkulator::acot(argument));
                else if(pom == "ln")
                    parsed.push(new kalkulator::ln(argument));
                else if(pom == "frac")
                    parsed.push(new kalkulator::frac(argument));
                i += pom.length();
            }
            else if(twoarg){
                if(parsed.size() < 2)
                    throw(invalid_argument("ERROR"));
                kalkulator::symbol *arg2 = parsed.top();
                parsed.pop();
                kalkulator::symbol *arg1 = parsed.top();
                parsed.pop();
                if(pom == "+")
                    parsed.push(new kalkulator::add(arg1, arg2));
                if(pom == "-")
                    parsed.push(new kalkulator::sub(arg1, arg2));
                if(pom == "/")
                    parsed.push(new kalkulator::div(arg1, arg2));
                if(pom == "*")
                    parsed.push(new kalkulator::mult(arg1, arg2));
                if(pom == "min")
                    parsed.push(new kalkulator::min(arg1, arg2));
                if(pom == "max")
                    parsed.push(new kalkulator::max(arg1, arg2));
                if(pom == "pow")
                    parsed.push(new kalkulator::pow(arg1, arg2));
                if(pom == "log")
                    parsed.push(new kalkulator::log(arg1, arg2));
                i += pom.length();   
            }
            else{
                if(env.in(pom))
                    parsed.push(new kalkulator::zmienna("pom"));
                else
                    throw(domain_error(""));
            }
        }
    }
    if(parsed.size() > 1)
        throw(invalid_argument("S"));
    try{
        return (parsed.top())->eval();
    }
    catch(std::exception &e){
        throw(logic_error("s"));
    }
}