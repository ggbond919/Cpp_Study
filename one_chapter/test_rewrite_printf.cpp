#include <cstdarg>
#include <cstdio>
#include <iostream>
#include <sstream>

class Test_Printf{
public:
    void printf(const char* fmt,...);
    void vprintf(const char* fmt,va_list ap);
public:
    std::stringstream m_ss;
};

void Test_Printf::printf(const char* fmt,...){
    va_list ap;
    va_start(ap, fmt);
    vprintf(fmt, ap);
    va_end(ap);    
}
void Test_Printf::vprintf(const char* fmt,va_list ap){
    char *buf = nullptr;
    int len   = vasprintf(&buf, fmt, ap);
    if (len != -1) {
        m_ss << std::string(buf, len) << std::endl;
        std::cout << m_ss.str();
        std::free(buf);
    }
}

int main(){

    Test_Printf t;
    t.printf("fatal %s:%d", __FILE__, __LINE__);

    return 0;
}