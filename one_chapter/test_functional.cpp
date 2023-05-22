#include <iostream>
#include <memory>
#include <functional>



class Test_Functional{
public:
    Test_Functional(){
        std::cout << "constructor.." << std::endl;
    }
    ~Test_Functional(){
        std::cout << "destructor.." << std::endl;
    }
};

using Ptr = std::shared_ptr<Test_Functional>;
using Func = std::function<void()>;

void Test_Functional_Func(){
    Ptr ptr = std::make_shared<Test_Functional>();
    std::cout << "计数为：" << ptr.use_count() << std::endl;
}

Func func = std::bind(Test_Functional_Func);
void Test_Functional_Func1(){
    // Func func1;
    // func1.swap(func);
    // func1();
    func();
}

int main(){
    func();
    Test_Functional_Func1();
    return 0;
}