#include <cstddef>
#include <iostream>
#include <string>


int main() {
    std::string s = "We are happy.";
    // while(true) {
    //     auto index = s.find(' ');
    //     if(index == std::string::npos) {
    //         break;
    //     } else {
    //         s.insert(index,{"%20"});
    //         s.erase(index + 3, 1);
    //     }
    // }
    std::string ans;
    for(auto &p : s) {
        if(p == ' ') {
            ans.push_back('%');
            ans.push_back('2');
            ans.push_back('0');
        } else {
            ans.push_back(p);
        }
    }



    return 0;
}