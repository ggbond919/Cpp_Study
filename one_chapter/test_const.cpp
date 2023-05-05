#include <iostream>

class Test_Const{
public:
    const int c;
    int a;
    int b;
public:
    Test_Const():c(3){
        a = 1;
        b = 2;
    }
    // 常函数，在结尾处
    int get_data_a() const{
        return a;
    }
    const int get_data_b(){
        return b;
    }

};

int main(){
    Test_Const t;
    auto b = t.get_data_b();
    b = 3;

    // 常对象可以访问常成员函数、常变量和普通变量，但是不能修改变量
    const Test_Const t1;
    std::cout << t1.a << std::endl;
    std::cout << t1.get_data_a() << std::endl;

    return 0;
}