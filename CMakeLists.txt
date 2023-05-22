cmake_minimum_required(VERSION 3.0.0)
project(test)
option(BUILD_TEST "ON for complile test" ON)

set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -std=c++11 -O0 -fstandalone-debug -Wall") 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -rdynamic -fPIC") 
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-function -Wno-builtin-macro-redefined -Wno-deprecated -Wno-deprecated-declarations")

include_directories(.)
set(SRC01
    #one_chapter/test_inlinefunc.cpp
    one_chapter/main.cpp
)

set(SRC02
    one_chapter/test_func_overload.cpp
)

set(SRC03
    one_chapter/test_extern.c
    one_chapter/test_externcplus.cpp
)

set(SRC03_1
    one_chapter/test_extern.c
    one_chapter/test_externc.c
)

set(SRC04
    one_chapter/test_class.cpp
)

set(SRC05
    one_chapter/test_static.cpp
)

set(SRC06
    one_chapter/test_const.cpp
)

set(SRC07
    one_chapter/test_friend_func.cpp
)

set(SRC08
    one_chapter/test_template.cpp
)

set(SRC09
    one_chapter/test_const_ref.cpp
)

set(SRC10
    one_chapter/test_rewrite_printf.cpp
)

set(SRC11
    one_chapter/test_time.cpp
)

set(SRC12
    one_chapter/test_Init.cpp
)

set(SRC13
    one_chapter/test_singleton.cpp
)

set(SRC14
    one_chapter/test_copy_constructor.cpp
)

set(SRC15
    one_chapter/test_deep_shallow_copy.cpp
)

set(SRC16
    one_chapter/test_cast.cpp
)

set(SRC17
    one_chapter/test_string.cpp
)

set(SRC18
    two_chapter/replace_space.cc
)

set(SRC19
    two_chapter/left_words.cc
)

set(SRC20
    two_chapter/is_space.cc
)

set(SRC21
    one_chapter/test_datastruct.cpp
)

set(SRC22
    one_chapter/test_functional.cpp
)






add_executable(chapter01 ${SRC01})
add_executable(chapter02 ${SRC02})
add_executable(chapter03 ${SRC03})
add_executable(chapter03_1 ${SRC03_1})
add_executable(chapter04 ${SRC04})
add_executable(chapter05 ${SRC05})
add_executable(chapter06 ${SRC06})
add_executable(chapter07 ${SRC07})
add_executable(chapter08 ${SRC08})
add_executable(chapter09 ${SRC09})
add_executable(chapter10 ${SRC10})
add_executable(chapter11 ${SRC11})
add_executable(chapter12 ${SRC12})
add_executable(chapter13 ${SRC13})
add_executable(chapter14 ${SRC14})
add_executable(chapter15 ${SRC15})
add_executable(chapter16 ${SRC16})
add_executable(chapter17 ${SRC17})
add_executable(chapter18 ${SRC18})
add_executable(chapter19 ${SRC19})
add_executable(chapter20 ${SRC20})
add_executable(chapter21 ${SRC21})
add_executable(chapter22 ${SRC22})




