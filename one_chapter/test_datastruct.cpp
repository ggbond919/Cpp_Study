#include <exception>
#include <iostream>
#include <vector>

void test_vec_func() {
    std::vector<int> v{ 1, 1, 2, 3 };
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;
    v.push_back(4);
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;

    auto ite = v.rend();
    std::cout << *ite << std::endl;

    auto ite_begin = v.rbegin();
    std::cout << *ite_begin << std::endl;

    // 返回最后一个元素后一个位置的迭代器
    auto ite_end = v.end();
    std::cout << *ite_end << std::endl;

    // 返回指定位置的元素，会进行边界检查
    auto e = v.at(1);
    std::cout << e << std::endl;
    try {
        auto e1 = v.at(v.size());
    }
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    // resize函数会将size和容量都置成一样大小，未初始化部分置为0
    v.resize(10);
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;
    v.pop_back();
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;

    // erase()函数会减少size，但不会改变实际容量
    v.erase(v.begin());
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;

    // 调用clear()之后，容量还是原来的大小，只不过容器内元素被清空
    v.clear();
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;
}

void test_vec_func1() {
    std::vector<int> v{ 1, 2, 3 };
    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    v.assign(3, 1);
    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    v.assign({ 4 });
    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::vector<int> v1{ 4, 5, 6 };
    v.assign(v1.begin(), v1.end());
    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void test_vec_func2() {
    std::vector<int> v{ 1, 2, 3 };
    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;

    // insert在当前迭代器前一个位置插入
    v.insert(v.end(), 4);
    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;

    v.insert(v.begin(), 9);
    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;

    v.emplace(v.begin(), 8);
    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;
}

// 关于扩容和删除多余容量
void test_vec_func3() {
    std::vector<int> v;
    // 可以提前指定容量
    v.reserve(3);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;
    v.push_back(4);
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;

    // 缩减为真实容量
    v.shrink_to_fit();
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;
}

int main() {
    // test_vec_func();
    // test_vec_func1();
    // test_vec_func2();
    // test_vec_func3();
    std::cout << sizeof(bool) << std::endl;
    return 0;
}