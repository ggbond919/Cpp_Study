#include "test_static.h"
#include <iostream>

int Test_Static::test = 1;

/// 全局变量在源文件中定义。
int g_test_static = 1;
/// 作用域限制在.cpp
static int test_static = 2;
void Test_Static::show() {
    std::cout << test << std::endl;
    std::cout << test_static++ << std::endl;
}
