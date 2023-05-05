#include <iostream>


int main(){

    std::string str = "nihao";
    std::string str1 = "haoni";
    const std::string &s = str;
    std::string &s1 = str;
    s1 = str1;


    return 0;
}