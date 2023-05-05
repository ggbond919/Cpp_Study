#include <iostream>
#include <fstream>
class Test_Cast_Base {
public:
    int a = 100;

public:
    virtual void show_a() {
        std::cout << this->a << std::endl;
    }
};

class Test_Cast_Derived : public Test_Cast_Base {
public:
    int a = 200;
    int b = 300;
    int c = 400;

public:
    void show_b() {
        std::cout << this->a << " " << this->b << " " << this->c << std::endl;
    }
    void show_a() {
        std::cout << this->a << " " << this->b << " " << this->c << std::endl;
    }
};

// static_cast
// 1.基本类型的转换，同C风格一致
// 2.void*转换为目标类型指针
// 3.向上转换类型安全，向下转换类型不安全，编译器不会检查
// 4.不能用于常变量和非常变量的转换
void Test_Static_Cast() {

    int a = 100;
    double d = static_cast<double>(a);
    std::cout << d << std::endl;
    // int* p = &a;
    // 不同类型指针不能互相转换
    // double *pd = static_cast<double*>(p);

    // 向上转型安全
    Test_Cast_Derived* derived = new Test_Cast_Derived();
    static_cast<Test_Cast_Base*>(derived)->show_a();

    // 向下转型不安全
    Test_Cast_Base* base = new Test_Cast_Base();
    static_cast<Test_Cast_Derived*>(base)->show_b();
}

// 去常属性一般是用来传递参数时，满足形参的条件，可能会需要const_cast
void Test_Const_Cast() {
    const int a = 25;
    int* p = const_cast<int*>(&a);
    *p = 18;
    // 并未改变const值
    std::cout << *p << " " << a << std::endl;
}

// 上行转换时和static_cast一致
// 向下转换时，static_cast不会检查类型，而dynamic_cast会检查类型
// dynamic_cast要求有虚函数和继承这两个条件，否则不能使用
void Test_Dynamic_Cast() {
    // 该情况下两种转换都能成功
    Test_Cast_Base* base = new Test_Cast_Derived();
    static_cast<Test_Cast_Derived*>(base)->show_b();
    static_cast<Test_Cast_Derived*>(base)->show_a();

    dynamic_cast<Test_Cast_Derived*>(base)->show_b();
    dynamic_cast<Test_Cast_Derived*>(base)->show_a();

    // 以下情况static_cast不会做类型检查，而dynamic_cast会做类型检查
    Test_Cast_Base* base1 = new Test_Cast_Base;
    // static_cast直接输出无效字符
    static_cast<Test_Cast_Derived*>(base1)->show_a();
    static_cast<Test_Cast_Derived*>(base1)->show_b();
    // dynamic_cast类型检查发现异常，会返回空指针
    if (dynamic_cast<Test_Cast_Derived*>(base1) == nullptr) {
        std::cout << "空指针" << std::endl;
    }
    else {
        dynamic_cast<Test_Cast_Derived*>(base1)->show_a();
    }
}

int main() {
    Test_Static_Cast();
    std::cout << "===================================" << std::endl;
    Test_Const_Cast();
    std::cout << "===================================" << std::endl;
    Test_Dynamic_Cast();
    return 0;
}