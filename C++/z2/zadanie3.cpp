#include <iostream>
#include <memory>

class Test {
public: 
    Test() {
        std::cout << "Test built" << std::endl;
    }
    ~Test() {
        std::cout << "Test destroyed" << std::endl;
    }
};

int main(int argc, const char** argv) {
    {
        std::shared_ptr<Test> b;
        std::weak_ptr<Test> t;
        {
            std::shared_ptr<Test> a = std::make_shared<Test>();
            //t = a;
            b = a;
        }
        std::cin.get();
    }
}