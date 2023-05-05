#include <iostream>

// 拷贝构造函数和赋值函数辨析
class Class_Copy {
public:
    Class_Copy() {
        std::cout << "constructot" << std::endl;
    }
    // 必须是引用，不然会陷入构造函数的死循环里面
    // 拷贝构造函数可以重载
    Class_Copy(const Class_Copy& c) {
        std::cout << "copy constructot" << std::endl;
    }
    Class_Copy(Class_Copy& c) {
        std::cout << "copy constructot" << std::endl;
    }
    Class_Copy& operator=(const Class_Copy& c) {
        std::cout << "operator= constructot" << std::endl;
        return *this;
    }
};

// 函数传参形式，也会调用Class_Copy的拷贝构造函数
void Test_Copy(Class_Copy t) {
    std::cout << &t << std::endl;
}

// 返回值是一个匿名对象，编译器做了优化；
Class_Copy Test_Copy() {
    Class_Copy c;
    // 返回时第一次拷贝构造一个匿名对象
    std::cout << &c << std::endl;
    return c;
}

int main() {
    Class_Copy cc;
    std::cout << &cc << std::endl;
    std::cout << "==================================" << std::endl;
    // 必须区分一个重要的概念，在定义的同时进行赋值，叫做初始化，其调用的是拷贝构造函数
    Class_Copy cc1 = cc;
    std::cout << &cc1 << std::endl;
    std::cout << "==================================" << std::endl;
    // 而初始化之后，再进行赋值，其调用的是运算符 =
    Class_Copy cc11;
    cc11 = cc1;
    std::cout << &cc11 << std::endl;
    std::cout << "==================================" << std::endl;
    Class_Copy cc2(cc1);
    std::cout << &cc2 << std::endl;
    std::cout << "==================================" << std::endl;
    Test_Copy(cc2);
    std::cout << "==================================" << std::endl;
    // 因为编译器做了优化，所以理论上两次拷贝构造函数都不会被执行
    // 第二次接收返回值是执行了拷贝构造函数
    auto c = Test_Copy();
    std::cout << &c << std::endl;
    std::cout << "==================================" << std::endl;
    return 0;
}