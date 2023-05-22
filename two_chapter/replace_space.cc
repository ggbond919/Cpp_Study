#include <cstddef>
#include <iostream>
#include <string>

void Solution(std::string s) {
    while (true) {
        auto index = s.find(' ');
        if (index == std::string::npos) {
            break;
        }
        else {
            s.insert(index, { "%20" });
            s.erase(index + 3, 1);
        }
    }
    std::cout << s << std::endl;
}

int main() {

    return 0;
}