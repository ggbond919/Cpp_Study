#include <iostream>
#include <string>

// 友元函数两种情况
// 1.将类外全局函数视为友元函数，此可让类外函数访问类内私有成员

// 提前声明
void show();
class Test_Friend2;

class Test_Friend1{
private:
    int a;
public:
    Test_Friend1(){
        a = 1;
    }
    void show_b(Test_Friend2 * f2);
    friend void show(Test_Friend1* f);
};
void show(Test_Friend1* f){
    // 如果不声明为友元函数会报错 'a' is a private member of 'Test_Friend1'
    std::cout << f->a << std::endl;
}

// 2.将另一个类的成员函数声明为友元函数
class Test_Friend2{
private:
    int b;
public:
    Test_Friend2(){
        b = 2;
    }
public:
    friend void Test_Friend1::show_b(Test_Friend2 * f2);
};

// 不能放在头文件内去实现该函数，编译期从上至下编译时无法找到完整的Test_Friend2类
void Test_Friend1::show_b(Test_Friend2 * f2){
    // 如果放在类内去实现 会报错Member access into incomplete type 'Test_Friend2'
    std::cout << f2->b << std::endl;
}

// 3.友元类相对更为自由，即如果A是B的友元类，则A中所有函数都是B的友元函数
class Test_Friend4;

class Test_Friend3{
public:
    void show_a(Test_Friend4* f);
    void show_b(Test_Friend4* f);
};

class Test_Friend4{
private:
    int a;
    int b;
public:
    Test_Friend4(){
        a = 1;
        b = 2;
    }
public:
    friend Test_Friend3;
};

void Test_Friend3::show_a(Test_Friend4* f){
    std::cout << f->a << std::endl;
}

void Test_Friend3::show_b(Test_Friend4* f){
    std::cout << f->b << std::endl;
}


int main(){
    Test_Friend1 *f = new Test_Friend1();
    show(f);

    Test_Friend3 *f3 = new Test_Friend3();
    Test_Friend4 *f4 = new Test_Friend4();
    f3->show_a(f4);
    f3->show_b(f4);


    return 0;
}