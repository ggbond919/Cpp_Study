#include "one_chapter/test_static.h"
#include <iostream>

extern int g_test_static;
static int test_static = 5;
/// https://blog.csdn.net/o8413897/article/details/41050021

/// test_static已经有了同名静态变量，此处再定义出现问题
// static int test;
int test1;
int main() {
    {
        static int t;
        int t1;
        double t2;
        // printf("%d\n",t);
        std::cout << t << std::endl;
        std::cout << t1 << std::endl;
        std::cout << t2 << std::endl;
        std::cout << test1 << std::endl;
        std::cout << g_test_static << std::endl;
        std::cout << test_static << std::endl;
    }

    Test_Static ts;
    ts.test = 10;
    Test_Static::show();
    Test_Static::show();
    Test_Static::show();
    


    return 0;
}