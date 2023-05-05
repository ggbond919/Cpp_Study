#include <bits/types/time_t.h>
#include <iostream>
#include <bits/stdint-intn.h>
#include <bits/stdint-uintn.h>
#include <bits/types/time_t.h>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <ctime>
#include <vector>
#include <map>
#include <functional>

void test_time_func(){
    struct tm tm;
    time_t time1 = std::time(0);
    localtime_r(&time1, &tm);
    char buf[64];
    std::string m_format = "%Y-%m-%d %H:%M:%S";
    std::strftime(buf,sizeof(buf),m_format.c_str(),&tm); 
    std::cout << buf << std::endl;   
}

int main(){

    test_time_func();


    return 0;
}