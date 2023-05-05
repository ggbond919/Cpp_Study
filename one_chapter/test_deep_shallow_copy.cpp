#include <cstring>
#include <iostream>

// 深拷贝，浅拷贝
// 当类内有动态资源时，使用深拷贝
class Test_Deep_Shallow {
public:
    Test_Deep_Shallow(int len) {
        m_len = len;
        arr = new int[m_len];
    }
    Test_Deep_Shallow(const Test_Deep_Shallow& t) {
        this->m_len = t.m_len;
        this->arr = new int[this->m_len];
        std::memcpy(this->arr, t.arr, (this->m_len)*sizeof(int));
    }
    Test_Deep_Shallow& operator=(const Test_Deep_Shallow& t) {
        this->m_len = t.m_len;
        this->arr = new int[this->m_len];
        std::memcpy(this->arr, t.arr, (this->m_len)*sizeof(int));
        return *this;
    }
    void MyPrint() {
        for (auto i = 0; i < m_len; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    ~Test_Deep_Shallow(){
        delete[] arr;
    }

public:
    int  m_len;
    int* arr;
};

int main() {
    Test_Deep_Shallow t1(10);
    for (auto i = 0; i < t1.m_len; i++) {
        t1.arr[i] = i;
    }
    t1.MyPrint();

    // 调用 operator=()
    Test_Deep_Shallow t2(t1.m_len);
    t2 = t1;
    t2.MyPrint();
    
    // 调用拷贝
    Test_Deep_Shallow t3 = t2;
    t3.MyPrint();

    // 如果是浅拷贝则会指向同一块空间
    // 将拷贝构造注释掉观察结果
    // t3和t2都指向了同一块空间
    // error double free
    t3.arr[0] = 9;
    t2.MyPrint();
    t3.MyPrint();

    return 0;
}