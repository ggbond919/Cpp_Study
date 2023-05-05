#include <iostream>

class Test_Static{
public:
    static int test;
    int a;
    int b;
public:
    void show();
};
int Test_Static::test = 1;

// static变量在类外分配内存,不算入类内
int main(){
    std::cout << sizeof(Test_Static) << std::endl;
    Test_Static t;
    std::cout << sizeof(t) << std::endl;
    // 8
    // 8
    return 0;
}