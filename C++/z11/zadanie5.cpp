#include <iostream>
#include <string>

template<typename T>
class Klasa{

    template<typename T>
    struct On_heap{
        private:
        T* p; 
        public:
        On_heap() : p(new T){} 
        ~On_heap() { delete p; } 
        T& operator*() { return *p; }
        //T* operator−>() { return p; }
        On_heap(constOn_heap&) = delete; 
        On_heap& operator=(const On_heap&) = delete;
    };

    template<typename T>
    struct On_stack{
        private:
        T* p; 
        public:
        On_heap() : p(new T){} 
        ~On_heap() { delete p; } 
        T& operator*() { return *p; }
        //T* operator−>() { return p; }
        On_heap(constOn_heap&) = delete; 
        On_heap& operator=(const On_heap&) = delete;
    };

    template<typename T> 
    struct obj_holder {
        using type = typename std::conditional<
        (sizeof(std::string)>=sizeof(T)),
        On_stack<T>, 
        On_heap<T>>::type;
        ~obj_holder(){
            if constexpr(sizeof(std::string)>=sizeof(T)){
                ~On_stack<T>();
            }else
            {
                ~On_heap<T>();
            }
            
        }

        }
    
    Klasa(){

    }
    ~Klasa(){
        ~obj_holder();
    }

};


