#include "test_class.h"

void Test_Class::show(){
    std::cout << a << std::endl;
}

int main(){
    Test_Class tc;
    tc.show();
    Test_Class *tc1 = new Test_Class();
    tc1->show();
    return 0;
}