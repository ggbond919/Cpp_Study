#include <iostream>
#include <memory>

/// TODO:自定义shared_ptr类
class Test_Ptr {
public:
    Test_Ptr() {
        std::cout << "Test_Ptr()" << std::endl;
    }
    ~Test_Ptr() {
        std::cout << this << " ~Test_Ptr()" << std::endl;
    }
};

void Test_Ptr_Use() {
    std::shared_ptr<Test_Ptr> owner;
    {
        std::shared_ptr<Test_Ptr> ptr(new Test_Ptr);
        owner = ptr;
        std::cout << ptr.use_count() << std::endl;
    }

    std::cout << owner.use_count() << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << owner.unique() << std::endl;

    std::shared_ptr<Test_Ptr> other = owner;
    std::cout << owner.use_count() << std::endl;
    /// 其指向的引用计数减一，当reset参数为空时，并且当前shared_ptr对象置为空，不为空时，指向参数，其所有权+1
    other.reset();

    if (!other) {
        std::cout << owner.use_count() << std::endl;
    }
    std::cout << "====================================" << std::endl;

    std::weak_ptr<Test_Ptr> wp(owner);
    auto sp = wp.lock();
    /// 返回了一个shared_ptr，引用计数加1
    if (sp) {
        std::cout << sp.use_count() << std::endl;
    }

    /// double free
    // auto p = other.get();
    // delete p;
    std::cout << "====================================" << std::endl;
    Test_Ptr* p = new Test_Ptr;
    Test_Ptr* p1;
    {
        std::unique_ptr<Test_Ptr> unique(p);
        p1 = unique.release();
        if (!unique) {
            std::cout << "所有权被释放,指向的对象并不会被析构" << std::endl;
        }
    }
    std::cout << "====================================" << std::endl;
    std::cout << p << " = " << p1 << std::endl;
    delete p1;
}

class B;
class A {
public:
    A() {
        std::cout << "A()" << std::endl;
    }
    ~A() {
        std::cout << "~A()" << std::endl;
    }
public:
    std::shared_ptr<B> ptr;
};

class B {
public:
    B() {
        std::cout << "B()" << std::endl;
    }
    ~B() {
        std::cout << "~B()" << std::endl;
    }
public:
    std::weak_ptr<A> ptr;
};

void Test() {
    std::shared_ptr<A> a(new A);
    std::shared_ptr<B> b(new B);
    a->ptr = b;
    b->ptr = a;
}

int main() {
    Test_Ptr_Use();
    Test();
    return 0;
}