#include <iostream>
#include <string>

void Solution(std::string s, int n) {
    std::string lans = "";
    std::string rans = "";
    int i = 0;
    for(auto &c : s) {
        if(i < n) {
            rans += c;
        } else {
            lans += c;
        }
        i++;
    }
    std::cout << lans+rans << std::endl;
}

/// 0ms
void Solution1(std::string s, int n) {
    auto str = s.substr(n);
    auto str1 = str + s.substr(0,n);
    std::cout << str1 << std::endl;
}

int main() {
    Solution(std::string("abcdefg"),2);
    Solution1(std::string("abcdefg"),2);
    Solution(std::string("lrloseumgh"),6);
    Solution1(std::string("lrloseumgh"),6);
    return 0;
}