#include <cstddef>
#include <iostream>
#include <string>
#include <regex>

bool Solution(std::string s) {
    // if(s.find_first_not_of("abcdfghijklmnopqrstuvwxyzABCDFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos) {
    //     return false;
    // }
    /// 带小数点的单拎出来处理
    /// 4种情况,前三种情况归为一类,前面可以有正负号,后一种情况归为一类,前面可以有正负号
    /// 1 d.d
    /// 2 d.
    /// 3 .d
    /// 4 d
    /// 处理完上述情况后再处理E|e之后的情况
    std::regex r("^\\s*(((\\+|\\-)?((\\d+\\.)|(\\.\\d+)|(\\d+\\.\\d+)))|((\\+|\\-)?\\d+))((e|E)((\\+|\\-)?\\d+))?\\s*$");
    //std::regex r("^\\s*((\\+|\\-)?)(\\d*\\.?\\d*)|((\\+|\\-)?\\d+)(e|E)((\\+|\\-)?\\d+)\\s*+$");
    return std::regex_search(s,r);

}

int main() {
    auto flag = Solution("3.5e15");


    return 0;
}