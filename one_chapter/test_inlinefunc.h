#ifndef _TEST_INLINE_H_
#define _TEST_INLINE_H_

// 理解成编译期的#define,其目的是在代码量少的时候
// 在编译期直接替换成代码段，在函数调用时直接展开
// 避免参数入栈，地址查找的资源消耗
inline int Add(int a,int b){
    return a+b;
}

int Dec(int a,int b){
    return a-b;
}
class A{
private:
    int a;

};

#endif