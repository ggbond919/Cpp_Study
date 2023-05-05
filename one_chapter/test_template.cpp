#include "one_chapter/test_extern.h"
#include <iostream>

// 函数模板
template<typename T>
void Swap(T& a,T& b){
    T tmp = a;
    a = b;
    b = tmp;

}
// 类模板
template<typename T>
class MyTemplateTest{
public:
    MyTemplateTest(T a);
public:
    T m_a;
public:
    void show();
};

// 类模板注意：
// 1.加上模板头
// 2.类作用域加上模板类型
// 3.定义类对象时需要指明具体类型
template<typename T>
MyTemplateTest<T>::MyTemplateTest(T a){
    m_a = a;
}

template<typename T>
void MyTemplateTest<T>::show(){
    std::cout << m_a << std::endl;
}

// 模板具体化
// 模板具体化分为函数模板具体化、类模板具体化，类模板部分具体化，又称为偏特化
// 所谓具体化是指，为一些特殊类型所作的特殊处理

// 对函数模板进行具体化
struct template_embody{
    int a;
};
template<typename T>
void show(T t){
    std::cout << t << std::endl;
}
// 此处需要template<>即可，因为已经指定了具体类型template_embody
template<>
void show<template_embody>(template_embody t){
    std::cout << t.a << std::endl;
}

// 对类模板进行具体化
template<typename T>
class Class_Embody{
public:
    Class_Embody(T a);
public:
    void show();
public:
    T m_a;
};
template<typename T>
Class_Embody<T>::Class_Embody(T a){
    m_a = a;

}
template<typename T>
void Class_Embody<T>::show(){
    std::cout << "这是未具体化的类模板" << m_a << std::endl;
}

template<> 
class Class_Embody<const char*>{
public:
    Class_Embody(const char* a);
public:
    void show();
public:
    const char* m_a;
};
// 此处注意，因为类型已定，所以函数定义时不需要再加模板头template<>
Class_Embody<const char*>::Class_Embody(const char* a){
    m_a = a;
}
void Class_Embody<const char*>::show(){
    std::cout << "这是具体化的类模板：" << m_a << std::endl;
}

// 在编写类模板代码时，要将模板化的代码声明和定义放在头文件当中，否则在运行时
// 有可能无法找到具体函数的实现而报错
// 通过模板显示实例化可以解决上述无法分离模板函数只能头文件的问题
// 在源文件下方template void func(type T);标明具体类型type即可

int main(){
    // 普通函数模板
    int a = 1;
    int b = 2;
    Swap(a, b);
    std::cout << a << " " << b << std::endl;

    // 3.定义类对象时需要指明具体类型
    MyTemplateTest<int> *mtt = new MyTemplateTest<int>(6);
    mtt->show();

    // 具体化类模板
    const char* str = "你好";
    Class_Embody<const char*> *ce = new Class_Embody<const char*>(str);
    ce->show();
    return 0;
}